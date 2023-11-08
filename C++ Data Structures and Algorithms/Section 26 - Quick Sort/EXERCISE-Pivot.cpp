#include <iostream>

using namespace std;


void swap(int array[], int firstIndex, int secondIndex) {
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}


int pivot(int array[], int pivotIndex, int endIndex){
    int swapIndex = pivotIndex; //places swap at pivot (these symbolize INDEXES)
    for(int i = pivotIndex + 1; i < endIndex; i++){ //i is placed after pivotIndex and goes until the end of the array
        if(array[i] < array[pivotIndex]){ //if the value at i is less than the value at the pivot
            swapIndex++; //move the swap index
            swap(array, swapIndex, i); //swap and i items are switched
        }
    }
    swap(array, pivotIndex, swapIndex); //swaps pivot item with swap item
    return swapIndex; //it returns the index that represents the middle of the array
}





int main() {
    
    int myArray[] = {4,6,1,7,3,2,5};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    int returnedIndex = pivot(myArray, 0, size-1);

    cout << "Returned Index: " << returnedIndex << "\n\n";

    for (auto value : myArray) {
        cout << value << " ";
    }

    /*
        EXPECTED OUTPUT:
        ----------------
        Returned Index: 3

        2 1 3 4 6 7 5  
        
     */
    
}

