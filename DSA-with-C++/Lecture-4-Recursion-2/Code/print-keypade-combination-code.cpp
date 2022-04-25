/*
Print Keypad Combinations Code

Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.

Input Format :
Integer n

Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

void printKeypadHelper(int num, string output){
    if(num == 0){
        cout << output << endl;
        return;
    }
    int n = num % 10;
    string s;
    switch(n){
        case 0:
            s = "";
            break;
        case 1:
            s = "";
            break;
        case 2:
            s = "abc";
            break;
        case 3:
            s = "def";
            break;
        case 4:
            s = "ghi";
            break;
        case 5:
            s = "jkl";
            break;
        case 6:
            s = "mno";
            break;
        case 7:
            s = "pqrs";
            break;
        case 8:
            s = "tuv";
            break;
        case 9:
            s = "wxyz";
            break;
    }
    for(int i = 0; i < s.size(); i++)
        printKeypadHelper(num/10,s[i] + output);
    
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output = "";
    printKeypadHelper(num, output);
}


int main()
{
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
