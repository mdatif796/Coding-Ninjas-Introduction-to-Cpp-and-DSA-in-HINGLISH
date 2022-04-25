/*
Code : Has Path
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.

Output Format :
The first and only line of output contains true, if there is a path between v1 and v2 and false otherwise.

Constraints :
0 <= V <= 1000
0 <= E <= 1000
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= V - 1
0 <= v2 <= V - 1
Time Limit: 1 second

Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true

Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
*/

#include <iostream>
#include<queue>
using namespace std;

// BFS
bool hasPathBFS(int **edges, int n, int sv, int ev, bool *visited){
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    while(!pendingVertices.empty()){
        int front = pendingVertices.front();
        pendingVertices.pop();
        if(edges[front][ev] == 1)
            return true;
        for(int i = 0; i < n; i++){
            if(edges[front][i] == 1 && !visited[i]){
                visited[i] = true;
                pendingVertices.push(i);
            }
        }
    }
    return false;
}

// DFS
// bool hasPathDFS(int **edges, int n, int sv, int ev, bool *visited){
//     if(edges[sv][ev] == 1){
//         return true;
//     }
//     visited[sv] = true;
//     for(int i = 0; i < n; i++){
//         if(i == sv)
//             continue;
//         if(!visited[i]){ 
//             if(edges[sv][i] == 1){ 
//                 visited[i] = true;
//                 bool tempAns = hasPathDFS(edges, n, i, ev, visited);
//                 if(tempAns)
//                     return true;
//             }
//         }
//     }
//     return false;
// }

int main() {
    // Write your code here
    int v, e;
    cin >> v >> e;
    int **edges = new int*[v];
    for(int i = 0; i < v; i++){
        edges[i] = new int[v];
        for(int j = 0; j < v; j++)
            edges[i][j] = 0;
    }
    
    for(int i = 0; i < e; i++){
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    
    int sv, ev;
    cin >> sv >> ev;
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++)
        visited[i] = false;
    bool res = hasPathBFS(edges, v, sv, ev, visited);
    if(res)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    
    // deallocation
    delete [] visited;
    for(int i = 0; i < v; i++)
        delete [] edges[i];
    delete [] edges;
}