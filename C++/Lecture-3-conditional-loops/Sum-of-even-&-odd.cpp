#include<iostream>
using namespace std;

int main() {
	// Write your code here
    int n;
    int sum_of_even = 0;
    int sum_of_odd = 0;
    cin >> n;
    while(n != 0){
        int num = n%10;
        if(num % 2 == 0){
            sum_of_even = num + sum_of_even;
        } else {
            sum_of_odd = num + sum_of_odd;
        }
        n = n/10;
    }
    cout << sum_of_even << " " << sum_of_odd <<endl;
	
}