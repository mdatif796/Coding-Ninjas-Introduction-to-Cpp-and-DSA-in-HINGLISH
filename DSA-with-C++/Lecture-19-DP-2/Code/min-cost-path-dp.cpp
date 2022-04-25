#include <bits/stdc++.h>
using namespace std;

#include<cmath>
// Dynamic Programming
int minCostPath(int **input, int m, int n){
    int **output = new int*[m];
    for(int i = 0; i < m; i++)
        output[i] = new int[n];
    
    // filling the destination
    output[m-1][n-1] = input[m-1][n-1];
    // filling the last row of output
    for(int j = n-2; j >= 0; j--){
        output[m-1][j] = output[m-1][j+1] + input[m-1][j];
    }
    // filling the last col of output
    for(int i = m-2; i >= 0; i--){
        output[i][n-1] = output[i+1][n-1] + input[i][n-1];
    }
    
    // filling rest of the output
    
    for(int i = m - 2; i >= 0; i--){
        for(int j = n - 2; j >= 0; j--){
            int a = output[i][j+1];
            int b = output[i+1][j];
            int c = output[i+1][j+1];
            output[i][j] = min(a, min(b,c)) + input[i][j];
        }
    }
    return output[0][0];
    
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