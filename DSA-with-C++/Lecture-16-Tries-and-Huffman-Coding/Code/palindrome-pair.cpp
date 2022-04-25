/*
Palindrome Pair
Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
The function should return either true or false. You don't have to print anything.

Input Format :
The first line of the test case contains an integer value denoting 'n'.

The following contains 'n' number of words each separated by a single space.

Output Format :
The first and only line of output contains true if the conditions described in the task are met and false otherwise.

Constraints:
0 <= n <= 10^5
Time Limit: 1 sec

Sample Input 1 :
4
abc def ghi cba
Sample Output 1 :
true
Explanation of Sample Input 1:
"abc" and "cba" forms a palindrome

Sample Input 2 :
2
abc def
Sample Output 2 :
false
Explanation of Sample Input 2:
Neither their exists a pair which forms a palindrome, nor any of the words is a palindrome in itself. Hence, the output is 'false.'
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */
    
    bool patternMatchingUtility(TrieNode *root, string pattern){

        if(pattern.length() == 0){

            return true;
        }

        int index = pattern[0] - 'a';
        if(root -> children[index] != NULL){

            return patternMatchingUtility(root -> children[index], pattern.substr(1));
        }

        else{

            return false;
        }
    }

    bool isPalindromePair(vector<string> words) {
        
        for(int i = 0; i < words.size(); i++){

            string rev = string(words[i].rbegin(), words[i].rend());
            string utility = rev.substr(0, rev.size() - 1);
            if(patternMatchingUtility(root, words[i]) || patternMatchingUtility(root, rev) || rev == words[i] ||
               patternMatchingUtility(root, utility)){

                return true;
            }
            add(words[i]);
            add(rev);
        }
        return false;
    }
    
//     bool search(TrieNode *root, string word){
//         if(word.size() == 0){
//             if(root -> isTerminal)
//                 return true;
//             else
//                 return false;
//         }
//         int index = word[0] - 'a';
//         TrieNode *child;
//         if(root -> children[index] != NULL)
//             child = root -> children[index];
//         else
//             return false;
//         return search(child, word.substr(1));
//     }
    
//     bool search(string word){
//         return search(root, word);
//     }
    
//     bool isPalindrome(string s){
//         int i = 0;
//         int j = s.length() - 1;
//         while(i < j){
//             if(s[i] != s[j])
//                 return false;
//             swap(s[i],s[j]);
//             i++;
//             j--;
//         }
//         return true;
//     }
    
//     string reverse(string word){
//         int i = 0; 
//         int j = word.length() - 1;
//         while(i < j){
//             swap(word[i], word[j]);
//             i++;
//             j--;
//         }
//         return word;
//     }

//     bool isPalindromePair(vector<string> words) {
//         // Write your code here
//         for(int i = 0; i < words.size(); i++){
//             if(isPalindrome(words[i]))
//                 return true;
//             else
//                 add(words[i]);
//         }
//         for(int i = 0; i < words.size(); i++){
//             string s = reverse(words[i]);
//             if(search(s))
//                 return true;
//         }
//         return false;
//     }
};

int main()
{
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}