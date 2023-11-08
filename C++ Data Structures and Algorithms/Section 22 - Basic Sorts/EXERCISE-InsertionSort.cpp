#include <iostream>

using namespace std;


void insertionSort(int array[], int size){
    for(int i = 1; i < size; i++){ //iteration starts at the second index
        int temp = array[i]; //set temp to the second value
        int j = i-1; //set j to the previous value
        while(j > -1 && temp < array[j]){ //this only happens if the second value is greater than the first value in the loop
            array[j + 1] = array[j]; //insert previous value to the next one (greater where the lesser was)
            array[j] = temp; //insert lesser value to where the previous one was
            j--; //decrease j
        }
    }
}



int main() {
    
    int myArray[] = {6,4,2,5,1,3};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    insertionSort(myArray, size);


    for (auto value : myArray) {  
        cout << value << " ";
    }

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 
        
     */
    
}

