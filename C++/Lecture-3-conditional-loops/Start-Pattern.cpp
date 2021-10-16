#include<iostream>
using namespace std;


int main(){

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