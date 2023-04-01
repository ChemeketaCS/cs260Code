#include <iostream>

using namespace std;

#include <algorithm>

/**
 * @brief mergeFunc Merge two consecutive sorted ranges within an
 * array into one sorted range
 *
 * @param arr Array with sorted ranges
 * @param low Index of start of first range (inclusive)
 * @param mid Index of end of first range (inclusive)
 * @param high Index of end of second range (inclusive)
 * @param temp Array to copy values into
 *
 * @pre
 * a[low]-a[mid] are sorted
 * a[mid+1]-a[high] are sorted
 * @post
 * a[low]-a[high] are sorted
 *
 */
void mergeFunc(int arr[], int low, int mid, int high, int temp[]) {
    //TODO - Fixme

    //Set up i (first half location), j (second half location),
    //   and k (location in temp)

    //While first half is not empty and second half not empty
    //  Decide if first or second half has next smallest item
    //  Move it it temp

    //While first half is not empty
    //  Move next item from it to temp

    //While second half is not empty
    //  Move next item from it to temp

    //Copy indexes from low-high from temp back to arr
}


/**
 * @brief mergeSortInternal Recursive merge sort function
 * @param arr Array of ints to sort
 * @param low Index we should start sort at (inclusive)
 * @param high Index we should sort up to (inclusive)
 * @param temp Extra array that will be used to merge
 *
 * Note: we take temp in to avoid consantly allocating/deallocating
 * new arrays
 */
void mergeSortInternal (int arr[], int low, int high, int temp[]) {
    //TODO - Fixme

    // base case: 1 or fewer elements is sorted
    if (low >= high)
        return;

    //Set mid to halfway between low and high
    //Recursively sort first low to mid
    //Recursively sort second mid+1 to high

    //Call mergeFunc to merge the two halves
}


/**
 * @brief mergeSort Sorts the given array by building a temporary array
 * and then calling the recursive mergeSortInternal
 */
void mergeSort(int arr[], int arrSize) {
    int* temp = new int[arrSize];
    mergeSortInternal (arr, 0, arrSize-1, temp);
    delete [] temp;
}

