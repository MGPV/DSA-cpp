#include <iostream>
#include <vector>

using namespace std;


bool itemInCommon(vector<int> vect1, vector<int> vect2) {
    for (auto i : vect1) { //inefficient way with O(n^2)
        for (auto j : vect2) { //for each item in vector 1, loop through vector 2
            if (i == j) return true; //if any value in i is equal to any value in j, return true
        }
    }
    return false;
}


int main() {

    vector<int> vect1 {1, 3, 5};

    vector<int> vect2 {2, 4, 6};

    cout << itemInCommon(vect1, vect2);

}

