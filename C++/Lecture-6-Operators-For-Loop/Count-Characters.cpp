#include<iostream>
using namespace std;

int main(){

    char c = cin.get();
    int alpha = 0;
    int dig = 0;
    int whiteSpace = 0;
    while(c != '$'){
        if(c >= 'a' && c <= 'z'){
            alpha++;
        } else if(c >= '0' && c <= '9'){
            dig++;
        } else if(c == ' ' || c == '\t' || c == '\n'){
            whiteSpace++;
        }
        c = cin.get();
    }
    cout << alpha << " " << dig << " " << whiteSpace << endl;
  
}