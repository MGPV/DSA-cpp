#include <iostream>

using namespace std;


void swap(int array[], int firstIndex, int secondIndex) {
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}


int pivot(int array[], int pivotIndex, int endIndex) {
    int swapIndex = pivotIndex;
    for (int i = pivotIndex + 1; i <= endIndex; i++) {
        if (array[i] < array[pivotIndex]) {
            swapIndex++;
            swap(array, swapIndex, i);
        }
    }
    swap(array, pivotIndex, swapIndex);

    return swapIndex;
}


void quickSort(int array[], int leftIndex, int rightIndex){
    if(leftIndex >= rightIndex) return; //when indexes are equal, we return the top of the call stack
    int pivotIndex = pivot(array, leftIndex, rightIndex); //set pivotIndex according to the pivot function
    quickSort(array, leftIndex, pivotIndex - 1); //recursive to sort the left side of the array
    quickSort(array, pivotIndex + 1, rightIndex); //recursive to sort the fight side of the array
}



int main() {
    
    int myArray[] = {4,6,1,7,3,2,5};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    quickSort(myArray, 0, size-1);


    for (auto value : myArray) {  
        cout << value << " ";
    }
    
    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 7 
        
     */

}

