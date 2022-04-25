/*
String to Integer

Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.

Input format :
Numeric string S (string, Eg. "1234")

Output format :
Corresponding integer N (int, Eg. 1234)

Constraints :
0 <= |S| <= 9
where |S| represents length of string S.

Sample Input 1 :
00001231
Sample Output 1 :
1231

Sample Input 2 :
12567
Sample Output 2 :
12567
*/

#include <iostream>
using namespace std;

#include<math.h>
#include<cstring>
// int length(char input[]){
//     int i = 0;
//     int count = 0;
//     while(input[i] != '\0'){
//         count++;
//         i++;
//     }
//     return count;
// }

// int helper(char input[], int si, int ei){
//     if(si >= ei)
//         return 0;
//     int smallOutput = helper(input, si, ei-1);
//     char c = input[ei];
//     int a = c - '0';
//     a = pow(10,ei+1) + a;
//     return smallOutput + a;
// }

int stringToNumber(char input[]) {
    // Write your code here
    int len = strlen(input);
    if(input[0] == '\0')
        return 0;
    int smallOutput = stringToNumber(input+1);
    char c = input[0];
    int a = c - '0';
    a = pow(10,len-1) * a;
    return smallOutput + a;
}

int main()
{
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
