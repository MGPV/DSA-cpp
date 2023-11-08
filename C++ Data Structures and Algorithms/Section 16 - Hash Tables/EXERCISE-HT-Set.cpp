#include <iostream>

using namespace std;


class Node {
    public:
        string key;
        int value;
        Node* next;

        Node(string key, int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};

class HashTable {
    private:
        static const int SIZE = 7;
        Node* dataMap[SIZE];

        int hash(string key) {
            int hash = 0;
            for (int i = 0; i < key.length(); i++) {
                int asciiValue = int(key[i]);
                hash = (hash + asciiValue *  23) % SIZE;
            }
            return hash;
        }

    public:
        // ---------------------------------------------------
        //  Destructor code is similar to keys() function
        //  Watch that video to help understand how this works
        // ---------------------------------------------------
        ~HashTable() {
            for(int i = 0; i < SIZE; i++) {
                Node* head = dataMap[i];
                Node* temp = head;
                while (head) {
                    head = head->next;
                    delete temp;
                    temp = head;
                }
            }
        }
        
        void printTable() {
            for(int i = 0; i < SIZE; i++) {
                cout << i << ":" << endl;
                if(dataMap[i]) {
                    Node* temp = dataMap[i];
                    while (temp) {
                        cout << "   {" << temp->key << ", " << temp->value << "}" << endl;
                        temp = temp->next;
                    }
                }
            }
        }
        
        void set(string key, int value){
            int index = hash(key); //get the index according to the hash key
            Node* newNode = new Node(key, value); //create new node
            if(dataMap[index] == nullptr){ //if the index is empty, set new node there
                dataMap[index] = newNode;
            } else { //if the index is not empty, we make a temp pointer that will iterate through the LL at that address
                Node* temp = dataMap[index];
                while(temp->next != nullptr){ //this means that the LL has not ended
                    temp = temp->next; //move temp step by step until it is at the end
                }
                temp->next = newNode; //set temp next to be the new node in the LL
            }
        }
    
};


int main() {

    HashTable* myHashTable = new HashTable();

    myHashTable->set("nails", 100);
    myHashTable->set("tile", 50);
    myHashTable->set("lumber", 80);

    myHashTable->set("bolts", 200);
    myHashTable->set("screws", 140);

    myHashTable->printTable();

    /*
        EXPECTED OUTPUT:
        ----------------
        0:
        1:
        2:
        3:
           {screws, 140}
        4:
           {bolts, 200}
        5:
        6:
           {nails, 100}
           {tile, 50}
           {lumber, 80}

    */  

}

