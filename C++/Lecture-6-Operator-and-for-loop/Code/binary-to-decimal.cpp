/*
Binary to decimal

Given a binary number as an integer N, convert it into decimal and print.

Input format :
An integer N in the Binary Format
Output format :
Corresponding Decimal number (as integer)

Constraints :
0 <= N <= 10^9

Sample Input 1 :
1100
Sample Output 1 :
12

Sample Input 2 :
111
Sample Output 2 :
7
*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
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
