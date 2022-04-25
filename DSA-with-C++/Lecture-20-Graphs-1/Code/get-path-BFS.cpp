/*
Code : Get Path - BFS
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
The following line contain two integers, that denote the value of v1 and v2.

Output Format :
Print the path from v1 to v2 in reverse order.

Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second

Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1

Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
*/

#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> getPathBFS(int **edges, int n, int v1, int v2, bool *visited){
    queue<int> pendingVertices;
    pendingVertices.push(v1);
    visited[v1] = true;
    vector<int> res;
    unordered_map<int, int> um;
    while(!pendingVertices.empty()){
        int f = pendingVertices.front();
        pendingVertices.pop();
        for(int i = 0; i < n; i++){
            if((i != f) && (edges[f][i] == 1) && (!visited[i])){
                pendingVertices.push(i);
                visited[i] = true;
                um[i] = f;
                if(i == v2){
                    while(i != v1){
                        res.push_back(i);
                        i = um[i];
                    }
                    res.push_back(i);
                    // res.push_back(um[i]);
                    return res;
                }
            }
        }
    }
    return res;
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
    
    // connecting the edges
    for(int i = 0; i < e; i++){
        int sv, ev;
        cin >> sv >> ev;
        edges[sv][ev] = 1;
        edges[ev][sv] = 1;
    }
    
    int v1, v2;
    cin >> v1 >> v2;
    
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++)
        visited[i] = false;
    
    vector<int> path = getPathBFS(edges, v, v1, v2, visited);
    for(int i=0; i<path.size(); i++){
         cout << path[i] << " ";
     }
}

