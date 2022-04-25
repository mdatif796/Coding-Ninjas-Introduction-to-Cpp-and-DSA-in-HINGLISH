/*
Code: BST Class
Implement the BST class which includes following functions -
1. search
Given an element, find if that is present in BST or not. Return true or false.
2. insert -
Given an element, insert that element in the BST at the correct position. If element is equal to the data of the node, insert it in the left subtree.
3. delete -
Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.
4. printTree (recursive) -

Print the BST in ithe following format -
For printing a node with data N, you need to follow the exact format -
N:L:x,R:y
where, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines.
*/

#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST {
    // Define the data members
    BinaryTreeNode<int> *root;

    bool search(int data, BinaryTreeNode<int> *node){
        if(node == NULL)
            return false;
        if(node -> data == data)
            return true;
        else if(node -> data > data)
            return search(data, node -> left);
        else
            return search(data, node -> right);
    }

    void print(BinaryTreeNode<int> *root){
        if(root == NULL)
            return;
        cout << root -> data << ":";
        if(root -> left != NULL)
            cout << "L:" << root -> left -> data << ",";
        if(root -> right != NULL)
            cout << "R:" << root -> right -> data;
        cout << endl;
        print(root -> left);
        print(root -> right);
    }
    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int> *root){

        if(root == NULL){
            root = new BinaryTreeNode<int>(data);;
            return root;
        }
        if(root -> data >= data){
            BinaryTreeNode<int> *left = insert(data, root -> left);
            root -> left = left;
        } else {
            BinaryTreeNode<int> *right = insert(data, root -> right);
            root -> right = right;
        }
        return root;
    }

    BinaryTreeNode<int>* remove(int data, BinaryTreeNode<int> *root){
        if(root == NULL)
            return NULL;
        if(root -> data == data){
            if(root -> right == NULL && root -> left == NULL){
                delete root;
                return NULL;
            }
            else if(root -> right == NULL){
                BinaryTreeNode<int> *temp = root -> left;
                root -> left = NULL;
                delete root;
                return temp;
            } else if(root -> left == NULL){
                BinaryTreeNode<int> *temp = root -> right;
                root -> right = NULL;
                delete root;
                return temp;
            } else { 
                BinaryTreeNode<int> *temp = root -> right;
                BinaryTreeNode<int> *temp1 = root -> right;
                while(temp != NULL && temp -> left != NULL)
                    temp = temp -> left;
                temp -> left = root -> left;
                root -> right = NULL;
                root -> left = NULL;
                delete root;
                return temp1;
            }
        }
        if(root -> data >= data){ 
            BinaryTreeNode<int> *left = remove(data, root -> left);
            root -> left = left;
        } else {
            BinaryTreeNode<int> *right = remove(data, root -> right);
            root -> right = right;
        }
        return root;
    }
    public:
    BST() { 
        // Implement the Constructor
        root = NULL;
    }

    /*----------------- Public Functions of BST -----------------*/

    void remove(int data) { 
        // Implement the remove() function 
        root = remove(data, root);
    }

    void print() { 
        // Implement the print() function
        print(root);
    }

    void insert(int data) { 
        // Implement the insert() function 
        root = insert(data, root);
    }

    bool search(int data) {
        // Implement the search() function 
        return search(data, root);
    }
};

int main()
{
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            tree->insert(input);
            break;
        case 2:
            cin >> input;
            tree->remove(input);
            break;
        case 3:
            cin >> input;
            cout << ((tree->search(input)) ? "true\n" : "false\n");
            break;
        default:
            tree->print();
            break;
        }
    }
}