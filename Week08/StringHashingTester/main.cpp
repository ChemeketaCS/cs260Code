#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;


////Version 1 - first char
unsigned int myHash(const string& text) {
    unsigned int total = 0;
    total += text.at(0);
    return total;
}

////Version 2 - sum up char values
//unsigned int myHash(const string& text) {
//    unsigned int total = 0;
//    for(char c : text)
//        total += c;
//    return total;
//}

////Version 3 - shift chars as added, combine with XOR
//unsigned int myHash(const string& text) {
//    unsigned int total = 0;
//    for(char c : text)
//        total = (total << 5) + c;
//    return total;
//}

////Version 4 - use std::hash
//unsigned int myHash(const string& text) {
//    //std::hash is a struct that thinks it is a function - has an () operator
//    std::hash<string> h;
//    return h(text);
//}

int main() {
    vector<string> words = { "abc", "a", "apple", "bac", "cab", "cat", "dog"};
    cout << setw(8) << "Word" << " : " << setw(10) << "Hash" << " : " << "Hash mod 11" << endl;

    for(string word : words)
        cout << setw(8) << word << " : " << setw(10)
             << myHash(word) << " : "
             << myHash(word) % 11 << endl;

}
