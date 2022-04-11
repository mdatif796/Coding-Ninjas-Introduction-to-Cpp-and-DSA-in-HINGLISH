/*
Square Root (Integral)

Given a number N, find its square root. You need to find and print only the integral part of square root of N.
For eg. if number given is 18, answer is 4.

Input format :
Integer N

Output Format :
Square root of N (integer part only)

Constraints :
0 <= N <= 10^8

Sample Input 1 :
10
Sample Output 1 :
3

Sample Input 2 :
4
Sample Output 2 :
2
*/

#include <iostream>
using namespace std;

int main()
{
    // 1st way of solving this
	// int n;
	// cin >> n;
	// int sub = 1;
	// int count = 0;
	// while(n > 0){
	// // Here i use subtraction method for finding the square root 
	// n = n - sub;
	// sub += 2;
	// count++;
	// if(n < sub)
	// break;
	// }
	// cout << count;
    
    // 2nd way of solving this
    int n;
    cin >> n;
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(i * i <= n){
            res = i;
        } else
            break;
    }
    cout << res;
}
