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
    public:
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
 
        bool insert(int value){
            Node* newNode = new Node(value);
            if(root == nullptr){ //empty tree, set root to the newNode
                root = newNode;
                return true;
            }
            Node* temp = root; //create a temp that will iterate through the tree
            while(true){ //while loop for when the tree "exists"
                if(newNode->value == temp->value) return false; //values can't be repeated in a BST
                if(newNode->value < temp->value){ //left subtree
                    if(temp->left == nullptr) { //if no child is present, set the child to be newNode
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left; //this happens when the previous if statement is not executed (no return 'true' is given)
                } else {
                    if(temp->right == nullptr) { //same logic as the previous if statement
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }
        
};



int main() {
        
    BinarySearchTree* myBST = new BinarySearchTree();

    myBST->insert(2);
    myBST->insert(1);
    myBST->insert(3);

    /*
        THE LINES ABOVE CREATE THIS TREE:
                     2
                    / \
                   1   3
    */
        
                  

    // ROOT MUST BE PUBLIC FOR THESE LINES TO WORK
    cout << "Root: " << myBST->root->value;
    cout << "\n\nRoot->Left: " << myBST->root->left->value;
    cout << "\n\nRoot->Right: " << myBST->root->right->value;


    /*
        EXPECTED OUTPUT:
        ----------------
        Root: 2

        Root->Left: 1

        Root->Right: 3

    */

}
