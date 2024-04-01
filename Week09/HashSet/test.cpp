//Bring in unit testing code and tell it to build a main function
//If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

//Hide some false warnings - this is supposed to look commented out
// clazy:skip

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include "StringHashTable.h"

#include <vector>

using namespace std;

TEST_CASE( "Contains" ) {
    StringHashTable t;
    t.buckets[t.getBucket("A")] = "A";

    INFO(t);
    REQUIRE( t.contains("A") );
}

TEST_CASE( "ContainsProbe" ) {
    StringHashTable t;

    //Find something that does NOT occupy the last location
    string key = "A";
    int targetBucket = t.getBucket(key);
    while(targetBucket == t.tableCapacity - 1) {
        key += "A";
        targetBucket = t.getBucket(key);
    }

    //Fill bucket the value should be in
    t.buckets[targetBucket] = "No";

    //Place key in next bucket
    int nextBucket = targetBucket + 1;
    t.buckets[nextBucket] = key;

    INFO(t);
    REQUIRE( t.contains(key) );
}


TEST_CASE( "ContainsProbeWithWrap" ) {
    StringHashTable t;

    //Find something that should occupy next to last location
    string key = "A";
    int targetBucket = t.getBucket(key);
    while(targetBucket != t.tableCapacity - 2) {
        key += "A";
        targetBucket = t.getBucket(key);
    }

    //Now fill that location and last location
    t.buckets[targetBucket] = "No";
    t.buckets[targetBucket + 1] = "No";

    //Place key in location 0 and see if we find it
    t.buckets[0] = key;

    INFO(t);
    REQUIRE( t.contains(key) );
}



TEST_CASE( "Insert" ) {
    StringHashTable t;
    t.insert("B");

    unsigned int targetBucket = t.getBucket("B");
    INFO(targetBucket);
    INFO(t);
    REQUIRE( t.buckets[targetBucket] == "B" );
    REQUIRE( t.currentSize == 1 );
}


TEST_CASE( "InsertWithProbe" ) {
    StringHashTable t;

    //Find something that occupies location 1
    string key = "B";
    int targetBucket = t.getBucket(key);
    while(targetBucket != 1) {
        key += "B";
        targetBucket = t.getBucket(key);
    }

    //Fill that and next two
    t.buckets[1] = "No";
    t.buckets[2] = "No";
    t.buckets[3] = "No";
    t.currentSize = 3;

    //Then add item
    t.insert(key);

    INFO(t);
    REQUIRE( t.buckets[4] == key );
    REQUIRE( t.currentSize == 4 );
}


TEST_CASE( "InsertWith Wrap" ) {
    StringHashTable t;

    //Find something that should occupy last location
    string key = "B";
    int targetBucket = t.getBucket(key);
    while(targetBucket != t.tableCapacity - 1) {
        key += "B";
        targetBucket = t.getBucket(key);
    }

    //Now fill that location and location 0
    t.buckets[t.tableCapacity - 1] = "No";
    t.buckets[0] = "No";
    t.currentSize = 2;

    //Place key
    t.insert(key);

    INFO(t);
    REQUIRE( t.buckets[1] == key );
    REQUIRE( t.currentSize == 3 );
}


TEST_CASE( "InsertWithProbe" ) {
    StringHashTable t;

    //Find something that occupies location 1
    string key = "B";
    int targetBucket = t.getBucket(key);
    while(targetBucket != 1) {
        key += "B";
        targetBucket = t.getBucket(key);
    }

    //Fill that and next two
    t.buckets[1] = "No";
    t.buckets[2] = "No";
    t.buckets[3] = "No";
    t.currentSize = 3;

    //Then add item
    t.insert(key);

    INFO(t);
    REQUIRE( t.buckets[4] == key );
    REQUIRE( t.currentSize == 4 );
}




TEST_CASE( "Remove" ) {
    StringHashTable t;
    t.insert("C");
    t.remove("C");

    INFO(t);
    REQUIRE( !t.contains("C") );
    REQUIRE( t.currentSize == 0 );
}


TEST_CASE( "RemoveAndInsert" ) {
    StringHashTable t;
    t.insert("C");

    //Make a tombstone
    t.remove("C");

    unsigned int targetBucket = t.getBucket("C");

    //Find something that should occupy same location
    string key = "B";
    while(targetBucket != t.getBucket(key)) {
        key += "B";
    }

    //Should replace the tombstone at location targetBucket
    t.insert(key);

    INFO(t);
    REQUIRE( t.buckets[targetBucket] == key );
    REQUIRE( t.currentSize == 1 );
}

TEST_CASE( "ContainsWithTombstone" ) {
    StringHashTable t;

    unsigned int targetBucket = t.getBucket("C");

    //Find something that should occupy same location
    string key = "B";
    while(targetBucket != t.getBucket(key)) {
        key += "B";
    }

    //Insert blocker, then C and remove leaving a tombstone
    t.insert(key);
    t.insert("C");
    t.remove(key);


    INFO(t);
    REQUIRE( t.contains("C") );
    REQUIRE( t.currentSize == 1 );
}



TEST_CASE( "Grow" ) {
    StringHashTable t;
    //Add a tombstone
    t.buckets[2] = "#";

    //Add all items from this list - F should trigger grow
    vector<string> items = {"A", "B", "C", "D", "E", "F"};
    for(string s : items) {
        t.insert(s);
    }

    //Are they all still there?
    for(string s : items) {
        REQUIRE( t.contains(s) );
    }

    REQUIRE( t.size() == 6 );

    //Add a few more items, also add to our vector
    items.push_back("G");
    t.insert("G");
    items.push_back("H");
    t.insert("H");
    items.push_back("I");
    t.insert("I");
    items.push_back("J");
    t.insert("J");

    //Check everything again
    for(string s : items) {
        REQUIRE( t.contains(s) );
    }
}

//Return next string in alphabetic order
// AAA, AAB, AAC..., AAZ, ABA, ABB,...
string nextString(string s) {
    for(int i = static_cast<int>(s.length() - 1); i >= 0; i--) {
        if(s[i] < 'Z') {
            s[i]++;
            break;
        }
        else
            s[i] = 'A';
    }
    return s;
}

TEST_CASE( "GrowStressTest" ) {
    StringHashTable t;

    string s = "AAA";
    for(int i = 0; i < 100; i++) {
        t.insert(s);
        s = nextString(s);
    }

    //Are they all still there?
    REQUIRE( t.size() == 100 );
    s = "AAA";
    for(int i = 0; i < 100; i++) {
        REQUIRE( t.contains(s) );
        s = nextString(s);
    }
}
