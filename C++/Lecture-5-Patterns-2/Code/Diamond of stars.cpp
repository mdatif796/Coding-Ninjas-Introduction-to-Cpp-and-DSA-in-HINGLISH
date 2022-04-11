/* n = 5
Print the following pattern for the given number of rows.
Note: N is always odd.


Pattern for N = 5



The dots represent spaces.



Input format :
N (Total no. of rows and can only be odd)
Output format :
Pattern in N lines
Constraints :
1 <= N <= 49
Sample Input 1:
5
Sample Output 1:
  *
 ***
*****
 ***
  *
Sample Input 2:
3
Sample Output 2:
  *
 ***
  *
*/

#include<iostream>
using namespace std;


int main() {
    
    int n ;
    cin >> n;
    int N = n / 2 + 1;
    // code for 1st half of my figure
    int i = 1;
    while(i <= N){
        int spaces = 1;
        while(spaces <= N - i){
            cout << " ";
            spaces++;
        }
        int star = 1;
        while(star <= i * 2 - 1){
            cout << "*";
            star++;
        }
        cout << endl;
        i++;
    }
    // code for second half of our figure
    int j = 1;
    int k = n - 2;
    while(j <= N - 1){
        int space = 1;
        while(space <= j){
            cout << " ";
            space++;
        }
        int stars = 1;
        while(stars <= k){
            cout << "*";
            stars++;
        }
        k = k - 2;
        cout << endl;
        j++;
    }
}
