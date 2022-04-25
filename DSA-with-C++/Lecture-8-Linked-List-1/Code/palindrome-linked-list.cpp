/*
Palindrome LinkedList
You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
First and the only line of each test case or query contains the the elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

Output format :
For each test case, the only line of output that print 'true' if the list is Palindrome or 'false' otherwise.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5

Time Limit: 1sec
Where 'M' is the size of the singly linked list.

Sample Input 1 :
1
9 2 3 3 2 9 -1
Sample Output 1 :
true

Sample Input 2 :
2
0 2 3 2 5 -1
-1
Sample Output 2 :
false
true
Explanation for the Sample Input 2 :
For the first query, it is pretty intuitive that the the given list is not a palindrome, hence the output is 'false'.

For the second query, the list is empty. An empty list is always a palindrome , hence the output is 'true'.
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

Node* findMiddle(Node *head){
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

Node* reverseLinkedList(Node *head){
    Node *prev = NULL;
    Node *curr = head;
    Node *Next = NULL;
    while(curr != NULL){
        Next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = Next;
    }
    return prev;
}

bool isPalindrome(Node *head){
    Node *middle = findMiddle(head);
    Node *secondHalf = reverseLinkedList(middle);
    Node *temp = head;
    while(secondHalf != NULL){
        if(temp -> data != secondHalf -> data)
            return false;
        else {
            temp = temp -> next;
            secondHalf = secondHalf -> next;
        }
    }
    return true;
}




// int length(Node *head){
//     if(head == NULL)
//         return 0;
//     Node *temp = head;
//     int count = 0;
//     while(temp != NULL){
//         count++;
//         temp = temp -> next;
//     }
//     return count;
// }

// bool isPalindrome(Node *head)
// {
//     //Write your code here
//     if(head == NULL || head -> next == NULL)
//         return true;
//     int len = length(head);
//     Node *temp = head;
//     int c = len/2;
//     while(c--){
//         Node *secondTemp = head;
//         int tempLength = len;
//         while(--tempLength){
//             secondTemp = secondTemp -> next;
//         }
//         if(temp -> data != secondTemp -> data)
//             return false;
//         temp = temp -> next;
//         len--;
//     }
    
//     return true;
    
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

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        bool ans = isPalindrome(head);

        if (ans)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }

    return 0;
}