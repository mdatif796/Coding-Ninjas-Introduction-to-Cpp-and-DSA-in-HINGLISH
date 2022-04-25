/*
Code : No. of balanced BTs
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.

Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.

Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.

Constraints :
1 <= h <= 24

Time Limit: 1 sec

Sample Input 1:
3
Sample Output 1:
15

Sample Input 2:
4
Sample Output 2:
315
*/

#include <iostream>
using namespace std;
const long long m = 1e9 + 7;

#include<cmath>
int balancedBTs(int n) {
    // Write your code here
    if(n <= 1)
        return 1;
    int x = balancedBTs(n - 1);  // both subtree should be have same number of nodes as difference between their height is <= 1
    int y = balancedBTs(n - 2); // one subtree should have n - 2 and other have n - 1 to maintain the difference as 1
    
    int mod = (int) (pow(10,9) + 7);
    
    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int) (((long)(2*x)*y) % mod);
    int ans = (int)((long)(temp1 + temp2) % mod);
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}