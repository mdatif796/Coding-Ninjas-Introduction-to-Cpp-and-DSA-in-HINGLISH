#include <iostream>
#include<cstring>
using namespace std;

void printaallprefixes(char str[]){
    for (int i = 0; str[i] != '\0'; i++){

        for (int j = 0; j <= i; j++){
            cout << str[j];
        }
        cout << endl;
    }
}

int main(){
    char input[] = "abcd";
    cout << strlen(input) << endl;
    printaallprefixes(input);
}
