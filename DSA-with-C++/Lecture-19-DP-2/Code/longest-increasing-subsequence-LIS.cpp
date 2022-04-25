/*
Longest Increasing Subsequence
Given an array with N elements, you need to find the length of the longest subsequence in the given array such that all elements of the subsequence are sorted in strictly increasing order.

Input Format
The first line of input contains an integer N. The following line contains N space separated integers, that denote the value of elements of array.

Output Format
The first and only line of output contains the length of longest subsequence.

Constraints
1 <= N <= 10^3
Time Limit: 1 second

Sample Input 1 :
6
5 4 11 1 16 8
Sample Output 1 :
3
Sample Output Explanation
Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).

Sample Input 2 :
3
1 2 2
Sample Output 2 :
2
*/

#include <iostream>
using namespace std;

/*
#include<vector>
int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
    int *output = new int[n];
    output[0] = 1;
    for(int i = 1; i < n; i++){
        output[i] = 1;
        for(int j = i - 1; j >= 0; j--){
            if(arr[j] >= arr[i])
                continue;
            int possibleAns = output[j] + 1;
            if(possibleAns > output[i])
                output[i] = possibleAns;
        }
    }
    
    int best = 0;
    for(int i = 0; i < n; i++){
        if(best < output[i])
            best = output[i];
    }
    return best;
    
    
    // if(n <= 0)
    //     return 0;
    // if(n == 1)
    //     return 1;
    // if(arr[0] < arr[1]){ 
    //     int x = longestIncreasingSubsequence(arr + 1, n - 1) + 1;
    //     int y = longestIncreasingSubsequence(arr + 1, n - 1);
    //     return max(x, y);
    // }
    // else
    //     return longestIncreasingSubsequence(arr + 1, n - 1);
    // // return max(x, y);
}
*/

int longestIncreasingSubsequence(int *arr, int n)
{
    int *dp = new int[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (ans < dp[i])
        {
            ans = dp[i];
        }
    }
    delete[] dp;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}