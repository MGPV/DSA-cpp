#include <iostream>

using namespace std;


void merge(int array[], int leftIndex, int midIndex, int rightIndex){
    int leftArraySize = midIndex - leftIndex + 1; //first determine subarray sizes
    int rightArraySize = rightIndex - midIndex;
    int leftArray[leftArraySize]; //assign sizes to each subarray
    int rightArray[rightArraySize];
    for(int i = 0; i < leftArraySize; i++){ //left subarray
        leftArray[i] = array[leftIndex + i]; //at i's current index, set the value to the array's left index + i (+ i is what is moving the value to the next one on the original array)
    }
    for(int j = 0; j < rightArraySize; j++){ //same as previous for function but starting from the middle of the array (+ j is what is moving the value to the next one on the original array)
        rightArray[j] = array[midIndex + 1 + j];
    }
    
    int index = leftIndex; //will iterate through the whole array to insert values back to it
    int i = 0;
    int j = 0;

    while(i < leftArraySize && j < rightArraySize) { //one subarray will finish first
        if(leftArray[i] <= rightArray[j]){ //we compare values at both subarrays
            array[index] = leftArray[i]; //assign the current value at left subarray to the original array
            index++; //in both cases increase index
            i++; //increase only i
        } else { //if right subarray is less than
            array[index] = rightArray[j]; //assign the current value at left subarray to the original array
            index++; //in both cases increase index
            j++; //increase only j
        }
    }

    while(i<leftArraySize){ //means that left subarray is not empty yet
        array[index] = leftArray[i]; //assign the current value at left subarray to the original array
        index++; //increase index
        i++; //increase i
    }

    while(j<rightArraySize){ //means that right subarray is not empty yet
    array[index] = leftArray[j]; //assign the current value at right subarray to the original array
    index++; //increase index
    j++; //increase j
    }
}
 
 
int main() {
    
    int myArray[] = {1,3,7,8,2,4,5,6};

    int size = sizeof(myArray) / sizeof(myArray[0]);
    int leftIndex = 0;
    int rightIndex = size - 1;
    int midIndex = (size / 2) - 1;


    merge(myArray, leftIndex, midIndex, rightIndex);


    for (auto value : myArray) {  
        cout << value << " ";
    }
    
    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 7 8 
        
     */

}

