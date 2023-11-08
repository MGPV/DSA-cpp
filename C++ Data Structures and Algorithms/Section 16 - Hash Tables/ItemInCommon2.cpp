#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;


bool itemInCommon(vector<int> vect1, vector<int> vect2) { //more efficient way
    unordered_map<int, bool> myMap; //represents the hash table, using the value in the vector as key and boolean true as value

    for (auto i : vect1) { //loop through the vector 1 and insert the values into the hash table
        myMap.insert({i, true});
    }

    for (auto j : vect2) { //loop through vector 2
        if (myMap[j]) return true; //check if the current value is present in the hash table
    }
    
    return false; //if the value is not present, return false
}


int main() {

    vector<int> vect1  {1, 3, 5};

    vector<int> vect2  {2, 4, 6};

    cout << itemInCommon(vect1, vect2);

}

