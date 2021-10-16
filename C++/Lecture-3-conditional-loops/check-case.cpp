#include<iostream>
using namespace std;

int main() {
	// Write your code here
	char c;
    cin>>c;
    if(c>='A' && c<='Z'){
        cout<<1<<endl;
    } else if(c>='a' && c<='z'){
        cout<<0<<endl;
    } else
        cout<<-1<<endl;
}