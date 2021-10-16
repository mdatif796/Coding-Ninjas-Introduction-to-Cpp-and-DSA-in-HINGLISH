#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    for(int i = 2;i <= n;i++){
        bool divided = false;
        for(int d = 2;d < i;d++){
            if(i % d == 0){
                divided = true;
                break;
            }
            }
            if(!divided){
                cout << i << endl;
        }
    }
  
}