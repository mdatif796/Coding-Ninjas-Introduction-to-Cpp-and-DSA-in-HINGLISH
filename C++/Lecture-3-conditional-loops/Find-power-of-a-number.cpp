#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int x, n;
    cin >> x >> n;
    int value = 1;
    while(n != 0){
        value = value * x;
        n = n - 1;
    }
    cout << value << endl;
}