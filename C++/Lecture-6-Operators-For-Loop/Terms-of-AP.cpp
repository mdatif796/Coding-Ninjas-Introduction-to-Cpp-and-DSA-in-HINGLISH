#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int x;
    cin >> x;
    int n = 1;
    int count = 0;
    while(n){
        if((3*n + 2) % 4 != 0){
            cout << 3*n + 2 << " ";
            count++;
        }
        if(count == x)
            break;
        n++;
    }
}