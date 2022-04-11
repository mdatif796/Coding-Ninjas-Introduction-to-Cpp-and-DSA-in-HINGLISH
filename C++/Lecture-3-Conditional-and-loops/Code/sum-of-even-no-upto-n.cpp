/*
    Given a number N, print sum of all even numbers from 1 to N.
Input Format :
Integer N
Output Format :
Required Sum 
Sample Input 1 :
 6
Sample Output 1 :
12
*/

#include <iostream>
using namespace std;

int main()
{

    int n,sum=0,count = 2; // we initialize count with 2 because we need to find sum of even no.
    cin>>n;
    while(count<=n){
        sum = sum + count;
        count = count + 2;
    }
    cout<<sum<<endl;
}