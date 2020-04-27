#include <iostream>

#include "Stack.h"

using namespace std;

void solvePostFix() {
    Stack<int> nums;

    cout << "Enter a postfix expression:" << endl;

    //Read in input, place items on stacks
    while(cin.peek() != '\n') {
        //Check to see if we have a number
        if(isdigit(cin.peek())) {
            int num;
            cin >> num;
            nums.push(num);
        } else {
            //Either a space or
            char nextChar;
            cin.get(nextChar);
            if(nextChar != ' ') {
                int value2 = nums.pop();
                int value1 = nums.pop();
                int result = 0;
                switch(nextChar) {
                    case '+' : result = value1 + value2; break;
                    case '*' : result = value1 * value2; break;
                    case '-' : result = value1 - value2; break;
                }
                nums.push(result);
            }
        }
    }

    //read in /n from end of input
    char temp;
    cin.get(temp);

    cout << nums.pop() << endl;
}


void solveParens() {
    Stack<char> parens;

    cout << "Enter a line - I will check for matched () [] and {}:" << endl;


    bool success = true;
    char curChar;
    while(cin.peek() != '\n') {
        cin.get(curChar);

        switch(curChar) {
            case '(' :
            case '[' :
            case '{' : parens.push(curChar); break;
            case ')' :
                if(parens.empty() || parens.pop() != '(')
                    success = false;
                break;
            case ']' :
                if(parens.empty() || parens.pop() != '[')
                    success = false;
                break;
            case '}' :
                if(parens.empty() || parens.pop() != '{')
                    success = false;
                break;
            default:    //do nothing for other chars
                break;
        }
    }

    //Read in /n from input
    cin.get(curChar);

    if(success && parens.empty())
        cout << "Matched parens" << endl;
    else
        cout << "Unmatched" << endl;
}

int main() {

    solvePostFix();

    solveParens();

}
