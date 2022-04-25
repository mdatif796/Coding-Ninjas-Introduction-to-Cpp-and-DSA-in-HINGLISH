/*
Binary Search (Recursive)

Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
Return -1 if x is not present in the given array.
Note : If given array size is even, take first mid.

Input format :
Line 1 : Array size

Line 2 : Array elements (separated by space)

Line 3 : x (element to be searched)

Sample Input :
6
2 3 4 5 6 8 
5 
Sample Output:
3 
*/

#include <iostream>
using namespace std;

int binarySearchHelper(int input[], int si, int ei, int element){
    if(si > ei)
        return -1;
    int mid = (si+ei)/2;
    if(input[mid] == element)
        return mid;
    if(input[mid] > element)
        return binarySearchHelper(input, si, mid-1, element);
    else if(input[mid] < element)
        return binarySearchHelper(input, mid+1, ei, element);
}

int binarySearch(int input[], int size, int element) {
    // Write your code here
	if(size == 0)
        return -1;
    return binarySearchHelper(input, 0, size-1, element);
}


int main()
{
    int input[100000], length, element, ans;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
        ;
    }

    cin >> element;
    ans = binarySearch(input, length, element);
    cout << ans << endl;
}
