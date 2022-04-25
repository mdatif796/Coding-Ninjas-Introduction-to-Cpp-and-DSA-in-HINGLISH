/*
Code: Knapsack (Memoization and DP)
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry, you have to find and return the maximum value that thief can generate by stealing items.
Note
Space complexity should be O(W).

Input Format :
The first line contains an integers, that denote the value of N. The following line contains N space separated integers, that denote the values of weight of items. The following line contains N space separated integers, that denote the values associated with the items. The following line contains an integer that denote the value of W. W denotes maximum weight that thief can carry.

Output Format :
The first and only line of output contains the maximum value that thief can generate, as described in the task. 

Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Time Limit: 1 second

Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
*/

#include <cstring>
#include <iostream>
using namespace std;
/*
Memoization
#include<bits/stdc++.h>
#include<vector>
int max(int a, int b){
    return (a>b)?a:b;
}
int knapsack(int* weight, int* value, int n, int maxWeight) {

    vector <vector<int>> dp(n+1,vector<int>(maxWeight+1));
    
    int i,w;
    for(i=0;i<=n;i++){
        for(w=0;w<=maxWeight;w++){
            if(i==0||w==0){
                dp[i][w]=0;
            }
            else if(weight[i-1]<=w){
                dp[i][w]=max(value[i-1]+dp[i-1][w-weight[i-1]],dp[i-1][w]);
            }
            else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }
    return dp[n][maxWeight];
}
*/

//Dp
int knapsack(int* weight, int* value, int n, int maxWeight) {
    // Write your code here
    int **ans = new int*[maxWeight + 1];
    for(int i = 0; i <= maxWeight; i++)
        ans[i] = new int[n + 1];
    
    // filling first row and first col with 0 because any of the value either maxWeight or n is zero
    for(int i = 0; i <= n; i++)
        ans[0][i] = 0;
    for(int i = 1; i <= maxWeight; i++)
        ans[i][0] = 0;
    
    for(int i = 1; i <= maxWeight; i++){
        for(int j = 1; j <= n; j++){
            if(weight[n - j] > maxWeight - weight[n - j]){
                ans[i][j] = ans[i - 1][j - 1];
            } else {
                int x = ans[i - 1][j - 1] + value[n - i];
                int y = ans[i - 1][j - 1];
                ans[i][j] = max(x, y);
            }
        }
    }
    return ans[maxWeight][n];
    
}

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}