#include <bits/stdc++.h>
using namespace std;

// Memoization
int minCostPathHelper(int **input, int **output, int row, int col, int i, int j){
    // if we reach the destination
    if(i == row - 1 && j == col - 1)
        return input[i][j];
    // if i or j crosses the border
    if(i >= row || j >= col)
        return INT_MAX;
    // check if output is present
    if(output[i][j] != -1)
        return output[i][j];
    int x = minCostPathHelper(input, output, row, col, i, j + 1);
    int y = minCostPathHelper(input, output, row, col, i + 1, j + 1);
    int z = minCostPathHelper(input, output, row, col, i + 1, j);
    
    int ans = min(x, min(y, z)) + input[i][j];
    // store the ans for future use
    output[i][j] = ans;
    return ans;
}

int minCostPath(int **input, int m, int n){
    int **output = new int*[m];
    for(int i = 0; i < m; i++)
        output[i] = new int[n];
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            output[i][j] = -1;
    }
    
    return minCostPathHelper(input, output, m, n, 0, 0);
}

int main()
{
    int **arr, n, m;
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}