/*
Print the following pattern for the given number of rows.
Pattern for N = 4
   1
  212
 32123
4321234

Input format : N (Total no. of rows)

Output format : Pattern in N lines

Sample Input :
5
Sample Output :
        1
      212
    32123
  4321234
543212345
*/

#include<iostream>
using namespace std;

int main(){

  // Write your code here  
	int n;
    cin >> n;
    int i = 1;
    while(i <= n){
        int space = 1;
        while(space <= n - i){
            cout << " ";
            space++;
        }
        int k = i;
        int j = 1;
        while(j <= i){
            cout << k;
            k--;
            j++;
        }
        int m = 1;
        int n = 2;
        while(m < i){
            cout << n;
            n++;
            m++;
        }
        cout << endl;
        i++;
    }
  
}
