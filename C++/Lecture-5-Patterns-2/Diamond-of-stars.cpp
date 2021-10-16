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
