/*
Return all codes - String

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.

Input format :
A numeric string

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

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Donât print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    int len = input.size();
    if(len == 0){ 
        output[0] = "";
        return 1;
    }
    // if(len == 1){
    //     int a = input[0] - '0';
    //     char b = a + 'a' - 1;
    //     output[0] = b;
    //     return 1;
    // }
    // create two new string array
    string result1[10000], result2[10000];
    
    int s1 = getCodes(input.substr(1), result1);
    int a = input[0] - '0';
    char b = a + 'a' - 1;
    int k = 0;
    for(int i = 0; i < s1; i++){
        output[k++] = b + result1[i];
    }
    
    int s2 = 0;
    if(input.size() > 1){ 
        int c = input[0] - '0';
        int d = input[1] - '0';
        int e = c*10 + d;
        if(e >= 10 && e <= 26){
            s2 = getCodes(input.substr(2), result2);
            char character = e + 'a' - 1;
            for(int i = 0; i < s2; i++){
                output[k++] = character + result2[i];
            }
        }
    }
    return s1 + s2;
}


int main()
{
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for (int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
