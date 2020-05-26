#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;


//Read in a list of words from the console. Stop at "."
vector<string> getWordList() {
    vector<string> list;
    string word;
    while(cin >> word && word != ".") {
        list.push_back(word);
    }
    return list;
}

//Returns a count of how many letters are different between s1 & s2
// Assumes words are the same size
// Position matters: "abc" is 3 different from "cab"
int letterDifference(const string& s1, const string& s2) {
    int differentChars = 0;
    for(unsigned int i = 0; i < s1.size(); i++) {
        if(s1[i] != s2[i])
            differentChars += 1;
    }
    return differentChars;
}



int main()
{
    vector<string> words = getWordList();
    string start, end;

    //Get starting and ending words
    cin >> start >> end;


}
