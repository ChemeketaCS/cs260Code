#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


//--------------------------------------------

struct Person {
    string firstName;
    string lastName;

    bool operator==(const Person& other) const {
        return firstName == other.firstName
                && lastName == other.lastName;
    }
};

unsigned int Person(const Person& p) {
    std::hash<string> h;
    return h(p.firstName) ^ h(p.lastName);
}

//--------------------------------------------


//--------------------------------------------
struct Player {
    string userName;
    int score;
};

unsigned int HashPlayer(const Player& p) {
    std::hash<string> h;
    return h(p.userName);
}
//--------------------------------------------


//--------------------------------------------
struct Student {
    string firstName;
    string lastName;
    string kNumber;

    bool operator==(const Student& other) const {
        return kNumber == other.kNumber;
    }
};

unsigned int HashStudent(const Student& p) {
    std::hash<string> h;
    return h(p.kNumber);
}
//--------------------------------------------


//--------------------------------------------
struct Point {
    int x;
    int y;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};


unsigned int HashPoint(const Point& p) {
    return (p.x << 16) ^ p.y;
}

//--------------------------------------------


int main() {

}
