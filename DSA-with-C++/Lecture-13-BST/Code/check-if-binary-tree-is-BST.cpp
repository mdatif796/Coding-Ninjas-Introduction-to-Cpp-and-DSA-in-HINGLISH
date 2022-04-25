/*
Check if a Binary Tree is BST
Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format :
The first and only line of output contains either true or false.

Constraints :
Time Limit: 1 second

Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1
Sample Output 1 :
true

Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
Sample Output 2 :
false
*/

#include <iostream>
#include <queue>
#include <climits>

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

using namespace std;

// 4th approach
// O(n)

#include<climits>
bool isBSTHelper(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX){
    if(root == NULL)
        return true;
    if(root -> data < min || root -> data > max)
        return false;
    bool isLeftOk = isBSTHelper(root -> left, min, root -> data - 1);
    bool isRightOk = isBSTHelper(root -> right, root -> data, max);
    return isLeftOk && isRightOk;
}

bool isBST(BinaryTreeNode<int> *root){
    return isBSTHelper(root,INT_MIN,INT_MAX);
}









// 3rd approach
// O(n)

// #include<climits>
// pair<pair<int,int>, bool> isBST2(BinaryTreeNode<int> *root){
//     if(root == NULL){
//         pair<pair<int,int>,bool> p;
//         p.first.first = INT_MAX;
//         p.first.second = INT_MIN;
//         p.second = true;
//         return p;
//     }
    
//     pair<pair<int,int>,bool> left = isBST2(root -> left);
//     pair<pair<int,int>,bool> right = isBST2(root -> right);
    
//     int minimum = min(root -> data, min(left.first.first, right.first.first));
//     int maximum = max(root -> data, max(left.first.second, right.first.second));
//     bool isBSTFinal = root -> data > left.first.second && root -> data <= right.first.first && left.second && right.second;
    
//     pair<pair<int,int>,bool> output;
//     output.first.first = minimum;
//     output.first.second = maximum;
//     output.second = isBSTFinal;
//     return output;
// }
// bool isBST(BinaryTreeNode<int> *root){
//     pair<pair<int,int>,bool> ans = isBST2(root);
//     return ans.second;
// }

// 2nd approach
// O(n)

// #include<climits>
// class isBSTClass{
//     public:
//     int minimum;
//     int maximum;
//     bool isBST;
// };

// isBSTClass isBST2(BinaryTreeNode<int> *root){
//     if(root == NULL){
//         isBSTClass p;
//         p.minimum = INT_MAX;
//         p.maximum = INT_MIN;
//         p.isBST = true;
//         return p;
//     }
//     isBSTClass left = isBST2(root -> left);
//     isBSTClass right = isBST2(root -> right);
    
//     int minimum = min(root -> data, min(left.minimum, right.minimum));
//     int maximum = max(root -> data, max(left.maximum, right.maximum));
//     bool isBSTFinal = root -> data > left.maximum && root -> data <= right.minimum && left.isBST && right.isBST;
    
//     isBSTClass output;
//     output.minimum = minimum;
//     output.maximum = maximum;
//     output.isBST = isBSTFinal;
//     return output;
// }

// bool isBST(BinaryTreeNode<int> *root) {
// 	// Write your code here
//     isBSTClass ans = isBST2(root);
//     return ans.isBST;
// }




// 1st approach
// O(n * h)

// int maximum(BinaryTreeNode<int> *root){
//     if(root == NULL)
//         return INT_MIN;
//     return max(root -> data, max(maximum(root -> left), maximum(root -> right)));
// }
// int minimum(BinaryTreeNode<int> *root){
//     if(root == NULL)
//         return INT_MAX;
//     return min(root -> data, min(minimum(root -> left), minimum(root -> right)));
// }

// bool isBST(BinaryTreeNode<int> *root) {
// 	// Write your code here
//     if(root == NULL)
//         return true;
//     bool output = root -> data > maximum(root -> left) && root -> data <= minimum(root -> right) && isBST(root -> left) && isBST(root -> right);
//     return output;
// }

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}