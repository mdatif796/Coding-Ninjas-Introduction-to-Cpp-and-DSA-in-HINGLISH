/*
Reverse Word Wise

Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.

Input format :
String in a single line

Output format :
Word wise reversed string in a single line

Constraints :
0 <= |S| <= 10^7
where |S| represents the length of string, S.

Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
Ninjas Coding to Welcome

Sample Input 2:
Always indent your code
Sample Output 2:
code your indent Always
*/

#include <iostream>
using namespace std;

// reverse function
void reverse(char input[], int si, int ei) {
    while(si < ei) {
        char temp = input[si];
    	input[si] = input[ei];
    	input[ei] = temp;
    	si++;
    	ei--;
    }
}

// length function
int length(char input[]) {
    int len = 0;
    for(int i = 0; input[i] != '\0'; i++) {
        len++;
    }
    return len;
}

void reverseStringWordWise(char input[]) {
    // Write your code here
    int len = length(input);
    reverse(input,0,len-1); // first reverse the whole array
    int j = 0;
    for(int i = 0; i < len; i++) {
        while(input[i] != ' '){
            i++;
            if(i >= len) break;   // if i is greater than or equal to len then break
        }
        if(input[i] == ' ') {
            reverse(input,j,i-1);  // reverse the individual word
            j = i + 1;
        }
    }
    reverse(input,j,len-1);   // reverse the last word because in last word we didn't find space that's why we reverse it separately 
}

int main()
{
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
