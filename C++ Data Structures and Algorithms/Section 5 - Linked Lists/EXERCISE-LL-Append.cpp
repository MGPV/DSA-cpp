#include <iostream>

using namespace std;


class Node { 
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
}; 


class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getHead() {
            if (head == nullptr) {
                cout << "Head: nullptr" << endl;
            } else {
                cout << "Head: " << head->value << endl;
            }
        }

        void getTail() {
            if (tail == nullptr) {
                cout << "Tail: nullptr" << endl;
            } else { 
                cout << "Tail: " << tail->value << endl;
            }  
        }

        void getLength() {
            cout << "Length: " << length << endl;
        }

        void append(int value) {
            Node* newNode = new Node(value); //create a new node with a given value
            if(length == 0){
                head = newNode; //if length is 0 then the new node is the only node
                tail = newNode; //assign head and tail to the new node 
            } else {
                tail->next = newNode; //assign the tail's pointer to the new node
                tail = newNode; //assign tail to the new node so that the new node becomes the new tail
            }
        }
	    
};



int main() {
        
    LinkedList* myLinkedList = new LinkedList(1);

    myLinkedList->append(2);

    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();

    cout << endl << "Linked List:" << endl;
    myLinkedList->printList();  


    /*  
        EXPECTED OUTPUT:
    	----------------
        Head: 1
        Tail: 2
        Length: 2

        Linked List:
        1
        2

    */
        
}
