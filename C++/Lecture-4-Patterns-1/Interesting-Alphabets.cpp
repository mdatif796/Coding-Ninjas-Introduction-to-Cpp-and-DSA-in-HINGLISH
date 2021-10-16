#include<iostream>
using namespace std;


int main() {
    
    int n;
    cin >> n;
    int i = 1;
    char c = 'A' + n - 1;
    while(i <= n){
        int j = 1;
        while(j <= i){
            cout << c;
            c++;
            j++;
        }
        i++;
        c = 'A' + n - i;
        cout << endl;
    }
    
}