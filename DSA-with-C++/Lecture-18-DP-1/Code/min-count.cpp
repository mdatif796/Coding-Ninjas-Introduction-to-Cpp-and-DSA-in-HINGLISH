/*
Code : Minimum Count
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.

Input format :
The first and the only line of input contains an integer value, 'N'.

Output format :
Print the minimum count of numbers required.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.

Sample Input 2 :
9
Sample Output 2 :
1
*/

#include <bits/stdc++.h>
using namespace std;

//Brute Force
int minCount_bf(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, minCount_bf(n - (i * i)));
    }
    return ans + 1;
}

//Memoization
int helper_mem(int n, int *ans)
{
    if (n == 0)
    {
        return 0;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }
    int smallAns = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {

        smallAns = min(smallAns, helper_mem(n - (i * i), ans));
    }
    ans[n] = smallAns + 1;
    return ans[n];
}

int minCount_mem(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = -1;
    }

    return helper_mem(n, ans);
}

#include<cmath>

// Dynamic Programming

int minCount(int n){
    int *ans = new int[n + 1];
    
    ans[0] = 0;
    for(int i = 1; i <= n; i++){
        int j = 1;
        int val = INT_MAX;
        while(true){
            if(pow(j, 2) > i)
                break;
            int x = ans[i - (int)(pow(j, 2))];
            val = min(x, val);
            j++;
        }
        ans[i] = val + 1;
    }
    int res = ans[n];
    delete [] ans;
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << minCount(n);
}