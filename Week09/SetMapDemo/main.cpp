#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    unordered_map<char, string> babyWords;
    babyWords['A'] = "Apple";
    babyWords['B'] = "Banana";

    if(babyWords.find('C') != babyWords.end())
        cout << "We have a C" << endl;
    else
        cout << "No C" << endl;

    //Try to print C that is not there...
    cout <<  babyWords['C'] << endl;

    if(babyWords.find('C') != babyWords.end())
        cout << "We have a C" << endl;
    else
        cout << "No C" << endl;
}
