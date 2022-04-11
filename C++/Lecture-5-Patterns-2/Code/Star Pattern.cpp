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
    while(i <= n){
        int spaces = 1;
        while(spaces <= n - i){
            cout << " ";
            spaces++;
        }
        int stars = 1;
        while(stars <= i * 2 - 1){
            cout << "*";
            stars++;
        }
        cout << endl;
        i++;
    }
}
