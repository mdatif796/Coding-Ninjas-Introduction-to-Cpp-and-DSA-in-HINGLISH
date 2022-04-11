/*
Number Star Pattern

Print the following pattern for given number of rows.
Input format :

Line 1 : N (Total number of rows)

Sample Input :
   5
Sample Output :
1234554321
1234**4321
123****321
12******21
1********1
*/

#include<iostream>
using namespace std;


int main(){

  // Write your code here
	int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cout << i;
    }
    for(int i = n; i >=1; i--){
        cout << i;
    }
    cout << endl;
    int i = 1;
    while(i < n){
        int j = i;
        int m = 1;
        while(j < n){
            cout << m;
            m++;
            j++;
        }
        int star = 1;
        while(star <= i * 2){
            cout << "*";
            star++;
        }
        int k = i;
        int l = n - i;
        while(k < n){
            cout << l;
            l--;
            k++;
        }
        cout << endl;
        i++;
    }
}
