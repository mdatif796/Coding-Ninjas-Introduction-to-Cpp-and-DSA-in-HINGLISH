#include<iostream>
using namespace std;


int main(){

    int s, e, w;
    cin >> s >> e >> w;
    int i = s;   //take i as a count value and assign s to it.
    while(i <= e){
        float c;
        c = (5 * (i - 32)) / 9;
        cout << i << "\t" << c << endl;
        i = i + w;  // increament i by w a/q.
    }
  
}