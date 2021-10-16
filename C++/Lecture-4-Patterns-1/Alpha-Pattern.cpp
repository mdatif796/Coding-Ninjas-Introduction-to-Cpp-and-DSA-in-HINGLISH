#include<iostream>
using namespace std;


int main(){
    
    int n;
    cin >> n;
    int i = 1;
    char c = 'A';
    while(i <= n){
        int j = 1;
        while(j <= i){
            cout << c;
        	j++;
        }
        c++;
        i++;
        cout << endl;
    }
    
}