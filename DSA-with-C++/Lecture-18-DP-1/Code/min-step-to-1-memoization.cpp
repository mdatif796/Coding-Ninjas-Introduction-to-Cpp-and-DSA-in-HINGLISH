#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

// Memoization
int countStepsToOneHelper(int n, int *ans){
    if(n <= 1)
        return 0;
    if(ans[n] != -1)
        return ans[n];
    int x = INT_MAX, y = INT_MAX, z = INT_MAX;
    x = countStepsToOneHelper(n - 1, ans);
    if(n % 2 == 0)
        y = countStepsToOneHelper(n / 2, ans);
    if(n % 3 == 0)
        z = countStepsToOneHelper(n / 3, ans);
    ans[n] = min(x, min(y, z)) + 1;
    return ans[n];
}

int countStepsToOne(int n)
{
	//Write your code here
    int *ans = new int[n + 1];
    for(int i = 0; i <= n; i++)
        ans[i] = -1;
    return countStepsToOneHelper(n, ans);
    
}

int main(){
    cout << countStepsToOne(10);
}