#include <iostream>

using namespace std;


void bubbleSort(int array[], int size){
    for(int i = size-1; i > 0; i--){ //for loop that starts at the end of the list to limit the following iterations to the unsorted part of the array
        for(int j = 0; j < i; j++){ //for loop that goes up the array until where i currently is. in each iteration it checks each pair of elements witht the following if statement
            if(array[j] > array[j+1]){ //checks if the current element (array[j]) is greater than the next, if so the swap occurs
                int temp = array[j]; //set temp to the current element
                array[j] = array[j+1]; //set the current element to the next
                array[j+1] = temp; //set temp (previous current) to the spot of the next element
            }
        }
    }
};



int main() {
    
    int myArray[] = {6,4,2,5,1,3};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    bubbleSort(myArray, size);


    for (auto value : myArray) {  
        cout << value << " ";
    }

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 
        
     */
    
}

