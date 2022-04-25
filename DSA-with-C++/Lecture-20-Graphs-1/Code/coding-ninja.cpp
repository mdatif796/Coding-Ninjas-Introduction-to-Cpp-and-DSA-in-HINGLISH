/*
Coding Ninjas
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.

Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
Each of the following N lines contain M characters. Please note that characters are not space separated.

Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.

Constraints :
1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second

Sample Input 1:
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output 1:
1
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool hasPath(vector<vector<char>> &board, int n, int m, int row, int col, string str, vector<vector<bool>> &visited){
    if(str.size() == 0)
        return true;
    int rows[] = {row - 1, row, row + 1};
    int cols[] = {col - 1, col, col + 1};
    for(int k = 0; k <= 2; k++){
        for(int l = 0; l <= 2; l++){
            if(rows[k] < 0 || cols[l] < 0 || rows[k] >= n || cols[l] >= m)
                continue;
            if(board[rows[k]][cols[l]] == str[0] && !visited[rows[k]][cols[l]]){
                visited[rows[k]][cols[l]] = true;
                bool smallAns = hasPath(board, n, m, rows[k], cols[l], str.substr(1), visited);
                if(smallAns)
                    return true;
                else
                    visited[rows[k]][cols[l]] = false;
            }
        }
    }
    return false;
}

bool hasPath(vector<vector<char>> &board, int n, int m, vector<vector<bool>> &visited){
    string str = "CODINGNINJA";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == str[0]){
                bool ans = hasPath(board, n, m, i, j, str.substr(1), visited);
                if(ans)
                    return true;
            }
        }
    }
    return false;
}

bool hasPath(vector<vector<char> > &board, int n, int m){
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    return hasPath(board, n, m, visited);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}