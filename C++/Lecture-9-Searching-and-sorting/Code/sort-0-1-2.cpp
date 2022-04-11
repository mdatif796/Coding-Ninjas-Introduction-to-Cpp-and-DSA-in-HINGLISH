/*
Sort 0 1 2

You are given an integer array/list(ARR) of size N. It contains only 0s, 1s and 2s. Write a solution to sort this array/list in a 'single scan'.
'Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.

Note:
You need to change in the given array/list itself. Hence, no need to return or print anything. 

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers(all 0s, 1s and 2s) representing the elements in the array/list.

Output Format :
For each test case, print the sorted array/list elements in a row separated by a single space.

Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^5

Time Limit: 1 sec

Sample Input 1:
1
7
0 1 2 0 2 0 1
Sample Output 1:
0 0 0 1 1 2 2 

Sample Input 2:
2
5
2 2 0 1 1
7
0 1 2 0 1 2 0
Sample Output 2:
0 1 1 2 2 
0 0 0 1 1 2 2
*/

#include <iostream>
#include <algorithm>
using namespace std;

void sort012(int *arr, int n)
{
    //Write your code here
    // 2nd Approach
    int nz = 0;
    int nt = n - 1;
    for(int i = 0; i <= nt; i++) {
        if(arr[i] == 0) {
            int temp = arr[i];
            arr[i] = arr[nz];
            arr[nz] = temp;
            nz++;
        } else if(arr[i] == 2) {
            int temp = arr[i];
            arr[i] = arr[nt];
            arr[nt] = temp;
            i--;  // If the element at index i is 2 then we swap it with nt but not increase i because i should be 0,so further check it
            nt--;
        }
    }
    
    
    
    
    
    // 1st Approach
    // int zero = 0;
    // int one = 0;
    // int two = 0;
    // // count the number of 0, 1 and 2
    // for(int i = 0; i < n; i++) {
    //     if(arr[i] == 0) {
    //         zero++;
    //     } else if(arr[i] == 1) {
    //         one++;
    //     } else {
    //         two++;
    //     }
    // }
    // // replace the array element with number of 0 , 1 and 2
    // int k = 0;
    // for(int i = 0; i < zero; i++) {
    //     arr[k] = 0;
    //     k++;
    // }
    // for(int i = 0; i < one; i++) {
    //     arr[k] = 1;
    //     k++;
    // }
    // for(int i = 0; i < two; i++) {
    //     arr[k] = 2;
    //     k++;
    // }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;

        cin >> size;
        int *arr = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }

        sort012(arr, size);

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        delete[] arr;
        cout << endl;
    }

    return 0;
}