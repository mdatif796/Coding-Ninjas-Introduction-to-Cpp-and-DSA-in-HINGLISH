#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n;
    cin >> n;
    long int res = 0;
    long int placevalue = 1;   // place value start as 1 , 10 , 100 , 1000 .....  like 
    while(n != 0){
        int c = n % 2;
        res = res + c * placevalue;
        placevalue *= 10;
        n = n / 2;
    }
    cout << res;
}
