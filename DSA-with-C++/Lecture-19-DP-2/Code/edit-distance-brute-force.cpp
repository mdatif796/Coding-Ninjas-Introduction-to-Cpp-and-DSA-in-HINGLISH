/*
Code : Edit Distance
Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
Edit Distance
Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character

Note
Strings don't contain spaces

Input Format :
The first line of input contains a string, that denotes the value of s. The following line contains a string, that denotes the value of t.

Output Format :
The first and only line of output contains the edit distance value between the given strings.

Constraints :
1<= m,n <= 10
Time Limit: 1 second

Sample Input 1 :
abc
dc
Sample Output 1 :
2
*/

#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

int editDistance(string s1, string s2) {
	// Write your code here
    // base case
    if(s1.size() == 0 || s2.size() == 0)
        return max(s1.size() , s2.size());
    // OR
    // int m = s1.size();
    // int n = s2.size();
    // if(m == 0 && n == 0)
    //     return 0;
    // else if(m == 0)
    //     return n;
    // else if(n == 0)
    //     return m;
    
    // recursive call
    if(s1[0] == s2[0])
        return editDistance(s1.substr(1), s2.substr(1));
    else {
        // delete
        int a = editDistance(s1, s2.substr(1)) + 1;
        // insert
        int b = editDistance(s1.substr(1), s2) + 1;
        // replace
        int c = editDistance(s1.substr(1), s2.substr(1)) + 1;
        return min(a, min(b, c));
    }
}

int main()
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}