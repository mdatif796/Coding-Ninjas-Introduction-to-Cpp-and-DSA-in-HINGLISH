/*
Node with maximum child sum
Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space. 

Output format :
The first and only line of output contains the data of the node with maximum sum, as described in the task.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Sample Output 1 :
1
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

template <typename T>
class Pair
{
public:
    TreeNode<T> *greaterNode;
    int sum;
};

Pair<int> helper(TreeNode<int> *root)
{
    Pair<int> ans;
    int childSum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        childSum += root->children[i]->data;
    }
    ans.greaterNode = root;
    ans.sum = childSum;
    for (int i = 0; i < root->children.size(); i++)
    {
        Pair<int> smallAns = helper(root->children[i]);
        if (smallAns.sum > ans.sum)
        {
            ans = smallAns;
        }
    }
    return ans;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL)
        return NULL;
    TreeNode<int>* maxNode = root;
    int sum = root -> data;
    for(int i = 0; i < root -> children.size(); i++)
        sum += root -> children[i] -> data;
    for(int i = 0; i < root -> children.size(); i++){
        TreeNode<int>* maxNode2 = maxSumNode(root -> children[i]);
        int sum2 = maxNode2 -> data;
        for(int i = 0; i < maxNode2 -> children.size(); i++){
            sum2 += maxNode2 -> children[i] -> data;
        }
        if(sum2 > sum){
            sum = sum2;
            maxNode = maxNode2;
        }
    }
    return maxNode;
    
}

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();

    TreeNode<int> *ans = maxSumNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
}