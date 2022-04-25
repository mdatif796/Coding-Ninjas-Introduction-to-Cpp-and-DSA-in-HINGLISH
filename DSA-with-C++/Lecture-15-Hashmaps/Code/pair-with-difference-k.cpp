/*
Pairs with difference K
You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.
Note: Take absolute difference between the elements of the array.

Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of K.

Output format :
The first and only line of output contains count of all such pairs which have an absolute difference of K. 

Constraints :
0 <= n <= 10^4
Time Limit: 1 sec

Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2

Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
6
*/

#include <iostream>
#include <unordered_map>
using namespace std;

#include<unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k){
    unordered_map<int,int> um;
    int count = 0;
    for(int i = 0; i < n; i++){
        int val1 = arr[i] + k;
        int val2 = arr[i] - k;
        
        count += um[val1];
        if(k != 0)
            count += um[val2];
        
        um[arr[i]]++;
    }
    return count;
}


int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}