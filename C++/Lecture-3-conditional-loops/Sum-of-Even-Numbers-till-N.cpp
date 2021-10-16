#include<iostream>
using namespace std;


int main(){
	int n,sum=0,count = 2;
    cin>>n;
    while(count<=n){
        sum = sum + count;
        count = count + 2;
    }
    cout<<sum<<endl;
}