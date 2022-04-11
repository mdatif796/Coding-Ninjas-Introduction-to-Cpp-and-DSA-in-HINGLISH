/*
Highest Occuring Character

For a given a string(str), find and return the highest occurring character.
Example:

Input String: "abcdeapapqarr"
Expected Output: 'a'
Since 'a' has appeared four times in the string which happens to be the highest frequency character, the answer would be 'a'.
If there are two characters in the input string with the same frequency, return the character which comes first.

Consider:
Assume all the characters in the given string to be in lowercase always.

Input Format:
The first and only line of input contains a string without any leading and trailing spaces.

Output Format:
The only line of output prints the updated string. 

Note:
You are not required to print anything explicitly. It has already been taken care of.

Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second

Sample Input 1:
abdefgbabfba
Sample Output 1:
b

Sample Input 2:
xy
Sample Output 2:
x
*/

#include <iostream>
#include <cstring>
using namespace std;

char highestOccurringChar(char input[]) {
    // Write your code here
    int frequencyCount[256] = {0};  // create a frequency array
    for(int i = 0; input[i] != '\0'; i++) {
        int a = input[i];
        frequencyCount[a]++;
    }
    // char ans = input[0];
    // int count = frequencyCount[int(ans)];
    // for(int i = 0; i < 256; i++) {
    //     if(frequencyCount[i] > count) {
    //         count = frequencyCount[i];
    //         ans = i;
    //     }
    // }
    // return ans;
    
    int largest = frequencyCount[0];
    int largestIndex = 0;
    for(int i = 1; i < 256; i++) {
        if(frequencyCount[i] > largest) {
            largest = frequencyCount[i];
            largestIndex = i;
        }
    }
    char res = largestIndex;
    return res;
}

int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << highestOccurringChar(str);
}