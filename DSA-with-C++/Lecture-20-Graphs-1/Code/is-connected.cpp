/*
Code : Is Connected ?
Given an undirected graph G(V,E), check if the graph G is connected graph or not.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.

Output Format :
The first and only line of output contains "true" if the given graph is connected or "false", otherwise.

Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second

Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true

Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
*/
#include<iostream>
using namespace std;

// take starting vertex and start traversing the graph by maintaining a visited array
// if after traversing , false is present in visited array then we say that the graph
// is disconnected
void isConnectedDFS(int **edges, int n, int sv, bool *visited){
    visited[sv] = true;
    for(int i = 0; i < n; i++){
        if(i != sv && edges[sv][i] == 1 && !visited[i])
            isConnectedDFS(edges, n, i, visited);
    }
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
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++)
        visited[i] = false;
    isConnectedDFS(edges, v, 0, visited);
    for(int i = 0; i < v; i++){
        if(visited[i] == false){ 
            cout << "false" << endl;
            return 0;
        }
    }
    cout << "true" << endl;
    return 0;
}