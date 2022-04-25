/*
Extract Unique characters
Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.

Input format:
The first and only line of input contains a string, that denotes the value of S.

Output format :
The first and only line of output contains the updated string, as described in the task.

Constraints :
0 <= Length of S <= 10^8
Time Limit: 1 sec

Sample Input 1 :
ababacd
Sample Output 1 :
abcd

Sample Input 2 :
abcde
Sample Output 2 :
abcde
*/

#include <iostream>
#include <string>
using namespace std;

#include <string>
#include <unordered_map>

#include<unordered_map>
string uniqueChar(string str) {
	// Write your code here
    unordered_map<char,int> um;
    
    // 1st approach
    string ans = "";
    for(int i = 0; str[i] != '\0'; i++){
        if(i == 0){
            ans += str[i];
            um[str[i]]++;
            continue;
        }
        if(um.size() > 0){
            if(um.count(str[i]) == 0)
                ans += str[i];
        }
        um[str[i]]++;
    }
    return ans;
    
//     for(int i = 0; str[i] != '\0'; i++)
//         um[str[i]]++;
    
//     string ans = "";
//     for(int i = 0; str[i] != '\0'; i++){
//         if(um.count(str[i]) > 0){
//             ans += str[i];
//             um.erase(str[i]);
//         }
//     }
//     return ans;
}

int main()
{
    string str;
    cin >> str;
    cout << uniqueChar(str);
}