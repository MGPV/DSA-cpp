#include <iostream>

using namespace std;


    void selectionSort(int array[], int size){
        for(int i = 0; i < size; i++){ //sets i for the iteration through the array
            int minIndex = i; //sets minimum index, will change if a new minimum is found
            for(int j = i + 1; j < size; j++){ //starts at index 1
                if(array[j] < array[minIndex]){ //compare both indexes' values
                    minIndex = j; //if the value at index j is less than the value at minimum index change the index
                }
            }
            if(i != minIndex){ //if minIndex is changed, then swap the values
                int temp = array[i];
                array[i] = array[minIndex];
                array[minIndex] = temp;
            }
        }
    }



int main() {
    
    int myArray[] = {6,4,2,5,1,3};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    selectionSort(myArray, size);


    for (auto value : myArray) {  
        cout << value << " ";
    }

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 
        
     */
    
}

