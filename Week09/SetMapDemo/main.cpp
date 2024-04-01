#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
using namespace std;



int main()
{
    unordered_set<string> words = {"carrot", "apple"};

    words.insert("banana");
    words.insert("banana");
    words.insert("guava");

    for(auto it = words.begin(); it != words.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;


    cout << "What word should I remove? ";
    string searchWord;
    cin >> searchWord;

    //Find returns an iterator. It is == .end() if item not found
    auto wordLoc = words.find(searchWord);
    if( wordLoc == words.end() ) {
        cout << "That word is not present" << endl;
    } else {
        //Erase word using the iterator
        words.erase(wordLoc);

        cout << "Removed. Set is now: ";
        for(auto it = words.begin(); it != words.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}
