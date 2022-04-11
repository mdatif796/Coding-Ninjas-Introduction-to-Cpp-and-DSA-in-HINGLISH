/*
Trim Spaces

Given an input string S that contains multiple words, you need to remove all the spaces present in the input string.
There can be multiple spaces present after any word.

Input Format :
 String S

Output Format :
Updated string

Constraints :
1 <= Length of string S <= 10^6

Sample Input :
abc def g hi
Sample Output :
abcdefghi
*/

#include <iostream>
#include <cstring>
using namespace std;

void trimSpaces(char input[]) {
    // Write your code here
    int len = strlen(input);
    for(int i = 0; i < len; i++) {
        if(input[i] == ' ') {
            for(int j = i; j < len; j++) {
                input[j] = input[j+1];
            }
            if(input[i] == ' ') {  // If at this point input[i] is having space then we don't increament 
                i--;
            }
            len--;
        }
    }
}

int main()
{
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input << endl;
}
