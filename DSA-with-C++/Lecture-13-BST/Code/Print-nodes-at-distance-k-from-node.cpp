// You are given a Binary Tree of type integer, a target node, and an integer value K.
// Print the data of all nodes that have a distance K from the target node. The order in which they would be printed will not matter.
// Example:
// For a given input tree(refer to the image below):
// 1. Target Node: 5
// 2. K = 2
// alt txt

// Starting from the target node 5, the nodes at distance K are 7 4 and 1.
// Input Format:
// The first line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

// The second line of input contains two integers separated by a single space, representing the value of the target node and K, respectively.
// Output Format:
// All the node data at distance K from the target node will be printed on a new line.

// The order in which the data is printed doesn't matter.
// Constraints:
// 1 <= N <= 10^5
// Where N is the total number of nodes in the binary tree.

// Time Limit: 1 sec
// Sample Input 1:
// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
// 3 1
// Sample Output 1:
// 9
// 6
// Sample Input 2:
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
// 3 3
// Sample Output 2:
// 4
// 5

#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printkdistanceNodeDown(BinaryTreeNode<int>*root, int k) 
{ 
    // Base Case 
    if (root == NULL || k < 0)  return; 
  
    // If we reach a k distant node, print it 
    if (k==0) 
    { 
        cout << root->data << endl; 
        return; 
    } 
  
    // Recur for left and right subtrees 
    printkdistanceNodeDown(root->left, k-1); 
    printkdistanceNodeDown(root->right, k-1); 
} 
// Prints all nodes at distance k from a given target node. 
// The k distant nodes may be upward or downward.  This function 
// Returns distance of root from target node, it returns -1 if target 
// node is not present in tree rooted with root. 

    // Write your code here
int printkdistanceNode(BinaryTreeNode<int>* root, int target , int k) 
{ 
    // Base Case 1: If tree is empty, return -1 
    if (root == NULL) return -1; 
  
    // If target is same as root.  Use the downward function 
    // to print all nodes at distance k in subtree rooted with 
    // target or root 
    if (root->data == target) 
    { 
        printkdistanceNodeDown(root, k); 
        return 0; 
    } 
  
    // Recur for left subtree 
    int dl = printkdistanceNode(root->left, target, k); 
  
    // Check if target node was found in left subtree 
    if (dl != -1) 
    { 
         // If root is at distance k from target, print root 
         // Note that dl is Distance of root's left child from target 
         if (dl + 1 == k) 
            cout << root->data << endl; 
  
         // Else go to right subtree and print all k-dl-2 distant nodes 
         // Note that the right child is 2 edges away from left child 
         else
            printkdistanceNodeDown(root->right, k-dl-2); 
  
         // Add 1 to the distance and return value for parent calls 
         return 1 + dl; 
    } 
  
    // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE 
    // Note that we reach here only when node was not found in left subtree 
    int dr = printkdistanceNode(root->right, target, k); 
    if (dr != -1) 
    { 
         if (dr + 1 == k) 
            cout << root->data << endl; 
         else
            printkdistanceNodeDown(root->left, k-dr-2); 
         return 1 + dr; 
    } 
  
    // If target was neither present in left nor in right subtree 
    return -1; 
} 
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
 int x= printkdistanceNode(root,node,k);
}












// void printNodesAtDepthK(BinaryTreeNode<int> *root, int k){
//     if(root == NULL)
//         return NULL;
//     if(k == 0){
//         cout << root -> data << endl;
//        return;
//     }
//     printNodesAtDepthK(root -> left, k - 1);
//     printNodesAtDepthK(root -> right, k - 1);
// }


// void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
//     // Write your code herez
//     if(root == NULL)
//         return;
//     if(root -> data == node){
//         printNodesAtDepthK(root, k);
//     }
// }

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}