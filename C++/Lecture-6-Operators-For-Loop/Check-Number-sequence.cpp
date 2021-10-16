#include<iostream>
using namespace std;

int main() {
    int n,currNum,prevNum;
    bool isDec=true;
    cin>>n;
    cin>>prevNum;
    while(--n){
        cin>>currNum;
        if(currNum>prevNum){
            isDec=false;
        }else if(currNum<prevNum){
            if(!isDec){
                cout<<"false";
                return 0;
            }
        }else if(prevNum==currNum){
            cout<<"false";
            return 0;
        }
        prevNum=currNum;
    }
    cout<<"true";

}