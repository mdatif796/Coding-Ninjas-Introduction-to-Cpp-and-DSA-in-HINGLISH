/*
Check Palindrome (recursive)

Check whether a given String S is a palindrome using recursion. Return true or false.

Input Format :
String S

Output Format :
'true' or 'false'

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
racecar
Sample Output 1:
true

Sample Input 2 :
ninja
Sample Output 2:
false
*/

#include <iostream>
using namespace std;

int length(char input[]){
    int i = 0;
    int count = 0;
    while(input[i] != '\0') {
        count++;
        i++;
    }
    return count;
}

bool helper(char input[], int si, int ei) {
    if(si >= ei)
        return true;
    if(input[si] != input[ei])
        return false;
    return helper(input, si+1, ei-1);
}

bool checkPalindrome(char input[]) {
    // Write your code here
	int len = length(input);
    int si = 0;
    int ei = len - 1;
    return helper(input, si, ei);
}

int main()
{
    char input[50];
    cin >> input;

    if (checkPalindrome(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
