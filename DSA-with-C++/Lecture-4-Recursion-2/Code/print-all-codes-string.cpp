/*
Print all Codes - String

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.

Input format :
A numeric string S

Output Format :
All possible codes in different lines

Constraints :
1 <= Length of String S <= 10

Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
*/

#include <iostream>
using namespace std;

#include <string.h>
#include <string.h>
using namespace std;

void helper(string input, string output){
    int len = input.size();
    if(len == 0){
        cout << output << endl;
        return;
    }
    int a = input[0] - '0';
    char b = a + 'a' - 1;
    helper(input.substr(1), output+b);
    
    if(input.size() > 1) {
        int b = input[1] - '0';
        int c = a*10 + b;
        if(c >= 10 && c <= 26){
            char d = c + 'a' - 1;
            helper(input.substr(2), output+d);
        }
    }
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    string output = "";
    helper(input, output);
}


int main()
{
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
