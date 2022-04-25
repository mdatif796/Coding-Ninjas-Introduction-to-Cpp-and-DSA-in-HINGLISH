/*
Merge Sort Code

Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.

Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

Output format :
Array elements in increasing order (separated by space)

Constraints :
1 <= n <= 10^3

Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8

Sample Input 2 :
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
*/

#include <iostream>
using namespace std;

void helper(int input[], int si, int ei) {
    if(si >= ei)
        return;
    int mid = (si+ei)/2;
    // sort the first half of an array
    helper(input, si, mid);
    // sort the second half
    helper(input, mid+1, ei);
    // create a temp array
    int temp[ei+1];
    //int k = 0;
    int k = si;
    int i = si;
    int j = mid+1;
    // merge the two sorted array
    while(i <= mid && j <= ei){
        if(input[i] <= input[j]){
            temp[k] = input[i];
            i++;
            k++;
        } else {
            temp[k] = input[j];
            j++;
            k++;
        }
    }
    // input the remaining element
    while(i <= mid)
        temp[k++] = input[i++];
    while(j <= ei)
        temp[k++] = input[j++];
    // copy from temp to input array
    // for(int i = 0; i < k; i++)
    //     input[i+si] = temp[i];
    for(k = si; k <= ei; k++)
        input[k] = temp[k];
}

void mergeSort(int input[], int size){
	// Write your code here
    if(size <= 1)
        return;
     helper(input, 0, size-1);   
}



int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}