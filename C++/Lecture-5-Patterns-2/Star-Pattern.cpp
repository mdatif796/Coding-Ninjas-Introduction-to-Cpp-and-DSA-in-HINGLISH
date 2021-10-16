#include<iostream>
using namespace std;


int main(){

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