#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n;
    cin >> n;
    int output = 0;
    int placevalue = 1;   // place value start from 1 , 2 , 4 , 8 .....as 2 * 
    while(n != 0){
        int c = n % 10;
        if(c == 1){
            output = output + placevalue;
        }
        placevalue *= 2;
        n = n / 10;
    }
    cout << output;
}