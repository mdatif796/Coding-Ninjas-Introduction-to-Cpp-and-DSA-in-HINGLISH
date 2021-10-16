#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n;
    int choice;
    cin >> n >> choice;
    int sum = 0;
    int product = 1;
    for(int i = 1; i <=n; i++){
        sum += i;
        product *= i;
    }
    if( choice == 1)
        cout << sum << endl;
    else if(choice == 2)
        cout << product << endl;
    else
        cout << -1 << endl;
}