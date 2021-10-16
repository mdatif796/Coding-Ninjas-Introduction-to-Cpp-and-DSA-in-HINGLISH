#include<iostream>
using namespace std;

int main() {
	// Write your code here
    // 1st way of solving this
	// int n;
	// cin >> n;
	// int sub = 1;
	// int count = 0;
	// while(n > 0){
	// // Here i use subtraction method for finding the square root 
	// n = n - sub;
	// sub += 2;
	// count++;
	// if(n < sub)
	// break;
	// }
	// cout << count;
    
    // 2nd way of solving this
    int n;
    cin >> n;
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(i * i <= n){
            res = i;
        } else
            break;
    }
    cout << res;
}