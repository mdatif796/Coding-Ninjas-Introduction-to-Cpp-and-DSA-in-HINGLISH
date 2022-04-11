/*
Reverse Each Word

Aadil has been provided with a sentence in the form of a string as a function parameter. The task is to implement a function so as to print the sentence such that each word in the sentence is reversed.
Example:
Input Sentence: "Hello, I am Aadil!"
The expected output will print, ",olleH I ma !lidaA".

Input Format:
The first and only line of input contains a string without any leading and trailing spaces. The input string represents the sentence given to Aadil.

Output Format:
The only line of output prints the sentence(string) such that each word in the sentence is reversed. 

Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second

Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
emocleW ot gnidoC sajniN

Sample Input 2:
Always indent your code
Sample Output 2:
syawlA tnedni ruoy edoc
*/

#include <iostream>
#include <cstring>
using namespace std;

void reverse(char input[], int si, int ei) {
    while(si < ei) {
        char temp = input[si];
        input[si] = input[ei];
        input[ei] = temp;
        si++;
        ei--;
    }
}

int length(char input[]) {
    int count = 0;
    for(int i = 0; input[i] != '\0'; i++) {
        count++;
    }
    return count;
}

void reverseEachWord(char input[]) {
    // Write your code here
    int len = length(input);
    int j = 0;
    for(int i = 0; input[i] != '\0'; i++) {
        while(input[i] != ' ') {
            i++;
            if(i >= len) break;
        }
        if(input[i] == ' ') {
            reverse(input, j, i-1);
            j = i + 1;
        }
    }
    reverse(input, j, len - 1);
}

int main()
{
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    reverseEachWord(str);
    cout << str;
}