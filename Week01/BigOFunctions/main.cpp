#include <iostream>

using namespace std;


int findLocationOfMax(int array[], int size) {
    int maxLoc = 0;                             //1
    for(int i = 0; i < size; i++) {             //n times
        if(array[i] > array[maxLoc])              //1
            maxLoc = i;                           //1
    }
    return maxLoc;                              //1
}


void sortArray(int array[], int size) {
    int itemsToSort = size;                                   //1
    while(itemsToSort > 1) {                                  //n times
        int maxLoc = findLocationOfMax(array, itemsToSort);     //O(n)
        int temp = array[itemsToSort - 1];                      //1
        array[itemsToSort - 1] = array[maxLoc];                 //1
        array[maxLoc] = temp;                                   //1
        itemsToSort--;                                          //1
    }
}

void printArray(int array[], int size) {
    for(int i = 0; i < size; i++) {             //n times
        cout << array[i] << " ";                  //O(1)
    }
    cout << endl;                               //1
}


int main()
{
    int size = 10;          //O(1)
    int nums[] = {5, 12, 54, 21, 4, 14, 32, 29, 11, 23};  //O(n)

    printArray(nums, size); //O(n)
    sortArray(nums, size);  //O(n^2)
    printArray(nums, size); //O(n)
}
