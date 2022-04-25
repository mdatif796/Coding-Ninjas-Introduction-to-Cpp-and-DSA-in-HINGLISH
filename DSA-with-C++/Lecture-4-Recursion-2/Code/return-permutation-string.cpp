/*
Return Permutations - String

Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.

Input Format :
String S

Output Format :
All permutations (in different lines)

Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba
*/

#include <iostream>
#include <string>
using namespace std;

#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    int len = input.size();
    if(len == 0){
        output[0] = "";
        return 1;
    }
    int k = 0;
    string newStr[10000];
    for(int i = 0; i < len; i++){
        int ans = returnPermutations(input.substr(0,i) + input.substr(i+1), newStr);
        for(int j = 0; j < ans; j++){
            output[k++] = input[i] + newStr[j];
        }
    }
    return k;
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
