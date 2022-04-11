/*
Second Largest

Take input a stream of n integer elements, find the second largest element present.
The given elements can contain duplicate elements as well. If only 0 or 1 element is given, the second largest should be INT_MIN ( - 2^31 ).
Input format :

Line 1 : Total number of elements (n)

Line 2 : N elements (separated by space)

Sample Input 1:
 4
 3 9 0 9
Sample Output 1:
 3
Sample Input 2 :
 2
 4 4
Sample Output 2:
 -2147483648
Sample Output Explanation:
Since both the elements are equal here, hence second largest element is INT_MIN i.e. ( -2^31 )
*/

#include<iostream>
using namespace std;
#include <climits>


int main(){
    
    // Write your code here
  int n, max;
  int equal = 0;
  cin >> n;
  int arr[n] = {};
  for (int i = 0; i < n;i++){
    cin >> arr[i];
  }
  for (int i = 0; i < n;i++){
    max = arr[i];
    for (int j = i; j < n; j++){
      if(max<arr[j]){
        max=arr[j];
        arr[j] = arr[i];
        arr[i] = max;
      }
    }
  }
  if(n<1){
    cout << INT_MIN;
  }
  else{
    max = arr[0];
    for (int i = 0; i < n; i++)
    {
      if(arr[i]<max){
        cout << arr[i];
        break;
      }
      equal++;

    }
    if (equal == n )
    {
      cout << INT_MIN;
    }
  }
    
}
