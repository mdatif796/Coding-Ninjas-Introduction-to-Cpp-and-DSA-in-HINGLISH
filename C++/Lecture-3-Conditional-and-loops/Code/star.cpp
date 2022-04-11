/*
   Print the following pattern
Pattern for N = 4



The dots represent spaces.



Input Format :
N (Total no. of rows)
Output Format :
Pattern in N lines
Constraints :
0 <= N <= 50
Sample Input 1 :
3
Sample Output 1 :
   *
  *** 
 *****
Sample Input 2 :
4
Sample Output 2 :
    *
   *** 
  *****
 *******
*/
#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int i = 1;
    int m = 1;
    while(i <= n){
        int k = 1, j = 1;
        // code for printing the no. of spaces
        while(k <= n-i){
            cout << " ";
            k = k + 1;
        }
        // code for printing the no. of stars
        while(j <= m){
            cout << "*";
            j = j + 1;
        }
        m = m + 2;
        i = i + 1;
        cout << endl;
    }
}
