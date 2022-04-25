/*
Code : In-place heap sort
Given an integer array of size N. Sort this array (in decreasing order) using heap sort.

Note: Space complexity should be O(1).

Input Format:
The first line of input contains an integer, that denotes the value of the size of the array or N.
The following line contains N space separated integers, that denote the value of the elements of the array.

Output Format :
The first and only line of output contains array elements after sorting. The elements of the array in the output are separated by single space.

Constraints :
1 <= n <= 10^6

Time Limit: 1 sec

Sample Input 1:
6 
2 6 8 5 4 3
Sample Output 1:
8 6 5 4 3 2
*/

#include <iostream>

#include<iostream>
using namespace std;
void heapSort(int arr[], int n) {
    // Write your code
    for(int i = 1; i < n; i++){
        int childIndx = i;
        while(childIndx > 0){
            int parentIndx = (childIndx - 1) / 2;
            if(arr[parentIndx] > arr[childIndx])
                swap(arr[parentIndx], arr[childIndx]);
            else
                break;
            childIndx = parentIndx;
        }
    }
    
    for(int i = 0;  i < n; i++){
        swap(arr[0], arr[n - i - 1]);
        int parentIndx = 0;
        int minIndx;
        while(parentIndx < n - i - 1){
            int lChildIndx = 2 * parentIndx + 1;
            int rChildIndx = 2 * parentIndx + 2;
            if(rChildIndx < n - i - 1){
                if(arr[lChildIndx] > arr[rChildIndx])
                    minIndx = rChildIndx;
                else
                    minIndx = lChildIndx;
            } else if(lChildIndx < n - i - 1){
                minIndx = lChildIndx;
            } else
                break;
            
            if(arr[parentIndx] > arr[minIndx])
                swap(arr[parentIndx], arr[minIndx]);
            else
                break;
            parentIndx = minIndx;
        }
    }
}

using namespace std;

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    heapSort(input, size);

    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}