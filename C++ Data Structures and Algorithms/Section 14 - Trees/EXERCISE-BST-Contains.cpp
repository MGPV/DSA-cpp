#include <iostream>

using namespace std;


class Node { 
    public: 
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};


class BinarySearchTree {
    private:
        Node* root;

    public:
        BinarySearchTree() { root = nullptr; }


        // ---------------------------------------------------
        //  Below is a helper function used by the destructor
        //  Deletes all nodes in BST
        //  Similar to DFS PostOrder in Tree Traversal section
        // ---------------------------------------------------
        void destroy(Node* currentNode) {
            if (currentNode->left) destroy(currentNode->left);
            if (currentNode->right) destroy(currentNode->right);
            delete currentNode;
        }

        ~BinarySearchTree() { destroy(root); }
 

        bool insert(int value) {
            Node* newNode = new Node(value);
            if (root == nullptr) {
                root = newNode;
                return true;
            }
            Node* temp = root;
            while(true) {
                if (newNode->value == temp->value) return false;
                if (newNode->value < temp->value) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }

        bool contains(int value){
            if(root==nullptr) return false;
            Node* temp = root;
            while(temp){ //loop runs as long as temp != nullptr
                if(value < temp->value){ //if the value is less than temp
                    temp = temp->left; //set temp to the left child
                } else if(value > temp->value){ //if the value is greater than temp
                    temp = temp->right; //set temp to the right child
                } else { //the above happens until temp's value is equal to the value we are looking for, then we return true
                    return true; 
                }
            }
            return false; //if the value is never found, temp will finally be pointing to nullptr so we return false
        }
        
};



int main() {
        
    BinarySearchTree* myBST = new BinarySearchTree();

    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(27);
    myBST->insert(52);
    myBST->insert(82);


    cout << "Contains 27: " << myBST->contains(27);
    cout << "\n\nContains 17: " << myBST->contains(17);


    /*
        EXPECTED OUTPUT:
        ----------------
        Contains 27: 1

        Contains 17: 0

    */    

}
