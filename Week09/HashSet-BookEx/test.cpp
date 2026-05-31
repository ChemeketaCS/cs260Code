// Bring in unit testing code and tell it to build a main function
// If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include "StringHashTable.h"

#include <vector>

using namespace std;

TEST_CASE("Contains") {
  StringHashTable t;
  t.m_buckets[t.getBucket("A")] = "A";

  INFO(t.toString());
  REQUIRE(t.contains("A"));
}

TEST_CASE("ContainsProbe") {
  StringHashTable t;

  // Find something that does NOT occupy the last location
  string key = "A";
  int targetBucket = t.getBucket(key);
  while (targetBucket == t.m_capacity - 1) {
    key += "A";
    targetBucket = t.getBucket(key);
  }

  // Fill bucket the value should be in
  t.m_buckets[targetBucket] = "No";

  // Place key in next bucket
  int nextBucket = targetBucket + 1;
  t.m_buckets[nextBucket] = key;

  INFO(t.toString());
  REQUIRE(t.contains(key));
}

TEST_CASE("ContainsProbeWithWrap") {
  StringHashTable t;

  // Find something that should occupy next to last location
  string key = "A";
  int targetBucket = t.getBucket(key);
  while (targetBucket != t.m_capacity - 2) {
    key += "A";
    targetBucket = t.getBucket(key);
  }

  // Now fill that location and last location
  t.m_buckets[targetBucket] = "No";
  t.m_buckets[targetBucket + 1] = "No";

  // Place key in location 0 and see if we find it
  t.m_buckets[0] = key;

  INFO(t.toString());
  REQUIRE(t.contains(key));
}

TEST_CASE("Insert") {
  StringHashTable t;
  t.insert("B");

  unsigned int targetBucket = t.getBucket("B");
  INFO("targetBucket" << targetBucket);
  INFO(t.toString());
  REQUIRE(t.m_buckets[targetBucket] == "B");
  REQUIRE(t.m_size == 1);
}

TEST_CASE("InsertWithProbe") {
  StringHashTable t;

  // Find something that occupies location 1
  string key = "B";
  int targetBucket = t.getBucket(key);
  while (targetBucket != 1) {
    key += "B";
    targetBucket = t.getBucket(key);
  }

  // Fill that and next two
  t.m_buckets[1] = "No";
  t.m_buckets[2] = "No";
  t.m_buckets[3] = "No";
  t.m_size = 3;

  // Then add item
  t.insert(key);

  INFO(t.toString());
  REQUIRE(t.m_buckets[4] == key);
  REQUIRE(t.m_size == 4);
}

TEST_CASE("InsertWith Wrap") {
  StringHashTable t;

  // Find something that should occupy last location
  string key = "B";
  int targetBucket = t.getBucket(key);
  while (targetBucket != t.m_capacity - 1) {
    key += "B";
    targetBucket = t.getBucket(key);
  }

  // Now fill that location and location 0
  t.m_buckets[t.m_capacity - 1] = "No";
  t.m_buckets[0] = "No";
  t.m_size = 2;

  // Place key
  t.insert(key);

  INFO(t.toString());
  REQUIRE(t.m_buckets[1] == key);
  REQUIRE(t.m_size == 3);
}

TEST_CASE("InsertWithProbe") {
  StringHashTable t;

  // Find something that occupies location 1
  string key = "B";
  int targetBucket = t.getBucket(key);
  while (targetBucket != 1) {
    key += "B";
    targetBucket = t.getBucket(key);
  }

  // Fill that and next two
  t.m_buckets[1] = "No";
  t.m_buckets[2] = "No";
  t.m_buckets[3] = "No";
  t.m_size = 3;

  // Then add item
  t.insert(key);

  INFO(t.toString());
  REQUIRE(t.m_buckets[4] == key);
  REQUIRE(t.m_size == 4);
}

TEST_CASE("Remove") {
  StringHashTable t;
  t.insert("C");
  t.remove("C");

  INFO(t.toString());
  REQUIRE(!t.contains("C"));
  REQUIRE(t.m_size == 0);
}

TEST_CASE("RemoveWithProbe") {
  StringHashTable t;

  // Find something that occupies location 1
  string key = "B";
  int targetBucket = t.getBucket(key);
  while (targetBucket != 1) {
    key += "B";
    targetBucket = t.getBucket(key);
  }

  // Fill that and next two
  t.m_buckets[1] = "No";
  t.m_buckets[2] = "No";
  t.m_buckets[3] = "No";
  t.m_size = 3;

  // Then add item and remove it
  t.m_buckets[4] = key;
  t.m_size = 4;
  t.remove(key);

  INFO(t.toString());
  REQUIRE(!t.contains(key));
  REQUIRE(t.m_size == 3);
}

TEST_CASE("RemoveAndInsert") {
  StringHashTable t;
  t.insert("C");

  // Make a tombstone
  t.remove("C");

  unsigned int targetBucket = t.getBucket("C");

  // Find something that should occupy same location
  string key = "B";
  while (targetBucket != t.getBucket(key)) {
    key += "B";
  }

  // Should replace the tombstone at location targetBucket
  t.insert(key);

  INFO("Testing if insert reused tombstone bucket");
  INFO("If you fail this, check your insert and update to handle tombstones");
  INFO(t.toString());
  REQUIRE(t.m_buckets[targetBucket] == key);
  REQUIRE(t.m_size == 1);
}

TEST_CASE("ContainsWithTombstone") {
  StringHashTable t;

  unsigned int targetBucket = t.getBucket("C");

  // Find something that should occupy same location
  string key = "B";
  while (targetBucket != t.getBucket(key)) {
    key += "B";
  }

  // Insert blocker, then C and remove leaving a tombstone
  t.insert(key);
  t.insert("C");
  t.remove(key);

  INFO("Testing if contains reads past tombstone bucket");
  INFO("If you fail this, check your contains");
  INFO(t.toString());
  REQUIRE(t.contains("C"));
  REQUIRE(t.m_size == 1);
}

TEST_CASE("Grow") {
  StringHashTable t;
  // Add a tombstone
  t.m_buckets[2] = "#";

  // Add all items from this list - F should trigger grow
  vector<string> items = {"A", "B", "C", "D", "E", "F"};
  for (string s : items) {
    t.insert(s);
  }

  // Are they all still there?
  for (string s : items) {
    REQUIRE(t.contains(s));
  }

  REQUIRE(t.size() == 6);

  // Add a few more items, also add to our vector
  items.push_back("G");
  t.insert("G");
  items.push_back("H");
  t.insert("H");
  items.push_back("I");
  t.insert("I");
  items.push_back("J");
  t.insert("J");

  // Check everything again
  for (string s : items) {
    REQUIRE(t.contains(s));
  }
}

// Return next string in alphabetic order
//  AAA, AAB, AAC..., AAZ, ABA, ABB,...
string nextString(string s) {
  for (int i = static_cast<int>(s.length() - 1); i >= 0; i--) {
    if (s[i] < 'Z') {
      s[i]++;
      break;
    } else
      s[i] = 'A';
  }
  return s;
}

TEST_CASE("GrowStressTest") {
  StringHashTable t;

  string s = "AAA";
  for (int i = 0; i < 100; i++) {
    t.insert(s);
    s = nextString(s);
  }

  // Are they all still there?
  REQUIRE(t.size() == 100);
  s = "AAA";
  for (int i = 0; i < 100; i++) {
    REQUIRE(t.contains(s));
    s = nextString(s);
  }
}
