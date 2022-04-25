/*
Code : All connected components
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.

Output Format :
Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order of different components doesn't matter.

Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1

Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 

Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
*/

#include<bits/stdc++.h>
using namespace std;
void helper(int **edges, int n, int sv, vector<int> &smallAns, bool *visited){  // we pass smallAns as a reference because in vector deep copy is performed
    visited[sv] = true;
    smallAns.push_back(sv);
    for(int i = 0; i < n; i++){
        if(i != sv && !visited[i] && edges[sv][i] == 1){
            helper(edges, n, i, smallAns, visited);
        }
    }
}
void dfs(int **edges, int n, int sv, vector<vector<int>> *output){
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            vector<int> smallAns;
            helper(edges, n, i, smallAns, visited);
            //if(smallAns.size() > 0)
                output -> push_back(smallAns);
        }
    }
    delete [] visited;
}
int main(){
    int v, e;
    cin >> v >> e;
    int **edges = new int*[v];
    for(int i = 0; i < v; i++){
        edges[i] = new int[v];
        for(int j = 0; j < v; j++)
            edges[i][j] = 0;
    }
    
    for(int i = 0; i < e; i++){
        int sv, ev;
        cin >> sv >> ev;
        edges[sv][ev] = 1;
        edges[ev][sv] = 1;
    }
    vector<vector<int>> * output = new vector<vector<int>>;
    dfs(edges, v, 0, output);
    for(int i = 0; i < output -> size(); i++){
        sort(output->at(i).begin(),output->at(i).end());
        for(int j = 0; j < output -> at(i).size(); j++){
            cout << output -> at(i).at(j) << " ";
        }
        cout << endl;
    }
}