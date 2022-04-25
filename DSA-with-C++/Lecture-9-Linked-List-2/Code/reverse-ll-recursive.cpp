/*
Code : Reverse LL (Recursive)
Given a singly linked list of integers, reverse it using recursion and return the head to the modified list. You have to do this in O(N) time complexity where N is the size of the linked list.
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^4
Where M is the size of the singly linked list.

Time Limit: 1sec

Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1
Sample Output 1 :
8 7 6 5 4 3 2 1

Sample Input 2 :
2
10 -1
10 20 30 40 50 -1
Sample Output 2 :
10 
50 40 30 20 10 
*/

#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;

// one another way
Node *reverseLinkedListRec(Node *head){
    if(head == NULL || head -> next == NULL)
        return head;
    
    Node *smallAns = reverseLinkedListRec(head -> next);
    
    Node *tail = head -> next;
    tail -> next = head;
    head -> next = NULL;
    
    return smallAns;
}





// reverse linked list using double pointer recursively

// class Pair{
//  public:
//     Node *head;
//     Node *tail;
// };

// Pair reverseLinkedListHelper(Node *head){
//     if(head == NULL || head -> next == NULL){
//         Pair ans;
//         ans.head = head;
//         ans.tail = head;
//         return ans;
//     }
    
//     Pair smallAns = reverseLinkedListHelper(head -> next);
    
//     smallAns.tail -> next = head;
//     head -> next = NULL;
    
//     Pair ans;
//     ans.head = smallAns.head;
//     ans.tail = head;
//     return ans;
// }




// Node *reverseLinkedListRec(Node *head){
//     return reverseLinkedListHelper(head).head;
// }
















// Node *reverseLinkedListRec(Node *head){
//     if(head == NULL || head -> next == NULL)
//         return head;
    
//     Node *tempHead = reverseLinkedListRec(head -> next);
    
//     Node *traverseHead = tempHead;
//     while(traverseHead -> next != NULL){
//         traverseHead = traverseHead -> next;
//     }
    
//     traverseHead -> next = head;
//     head -> next = NULL;
    
//     return tempHead;
// }




// Node *reverseLinkedListRec(Node *head)
// {
//     //Write your code here
    
//     // take three pointer
//     Node *prev = NULL;
//     Node *curr = head;
//     Node *Next = NULL;
    
//     while(curr != NULL){
//         // store next node address in Next
//         Next = curr -> next;
        
//         // store prev node address in curr next
//         curr -> next = prev;
        
//         // increament both the prev and curr pointer
//         prev = curr;
//         curr = Next;
//     }
    
//     // return the head of the linked list as prev
//     return prev;
    
// }

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        head = reverseLinkedListRec(head);
        print(head);
    }

    return 0;
}