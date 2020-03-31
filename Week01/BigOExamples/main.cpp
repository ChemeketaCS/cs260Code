#include <iostream>
#include <cmath>

using namespace std;

//double given number
int doubleNum(int num) {
    num *= 2;  				    //1
    return num;					//1
}


//returns the smallest value in collection
double minimum(double data[], int length) {
    double min = data[0];    //1
    int i = 1;               //1
    while(i < length) {      //n - 1
        //while comparison      //1
        if(data[i] < min)       //1
            min = data[i];      //1
        i++;                    //1
    }
    return min;              //1
}


int main()
{
    int n = 100;
    int sum = 0;

    //f(n)
    for(int i = 0; i < n; i++) {
        sum += i;
    }

    //g(n)
    for(int i = 0; i < n; i++) {
        int square = i * i;
        sum += square;
    }

    cout << "Hello world!" << endl;
    return 0;
}
