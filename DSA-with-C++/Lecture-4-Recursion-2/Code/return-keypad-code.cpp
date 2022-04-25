/*
Return Keypad Code

Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.

Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.

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

#include <string>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    int n = num % 10;
    if(num < 2) {
        output[0] = "";
        return 1;
    }
    int count = keypad(num/10, output);
    string s;
    switch(n) {
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
        case 0:
            s = "";
            break;
    }
    int outputSize = count * s.size();
    string temp[outputSize];
    int k = 0;
    for(int i = 0; i < count; i++) {
        for(int j = 0; j < s.size(); j++) {
            temp[k] = output[i] + s[j];
            k++;
        }
    }
    for(int i = 0; i < outputSize; i++) {
        output[i] = temp[i];
    }
    return outputSize;
}

int main()
{
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
