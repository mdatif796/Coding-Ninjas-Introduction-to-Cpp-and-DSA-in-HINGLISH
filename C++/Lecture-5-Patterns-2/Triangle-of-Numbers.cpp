#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i = 1;
    while(i <= n){
        int k = i;
        int spaces = 1;
        while(spaces <= n - i){
            cout << " ";
            spaces++;
        }
        int j = 1;
        while(j <= i){
            cout << k;
            k++;
            j++;
        }
        j = 1;
        while(j <= i - 1){
            cout << k - 2;
            k--;
            j++;
        }
        cout << endl;
        i++;
    }
    
}