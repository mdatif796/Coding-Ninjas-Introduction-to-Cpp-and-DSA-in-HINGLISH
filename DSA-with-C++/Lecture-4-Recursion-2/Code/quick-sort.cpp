/*
Quick Sort Code

Sort an array A using Quick Sort.
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
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 
*/

#include <iostream>
using namespace std;

int partition(int input[], int si, int ei){
        int count = 0;
        int pivot = input[si];
        for(int i = si+1; i <= ei; i++){
                if(input[i] <= pivot)
                        count++;
        }
        input[si] = input[si+count];
        input[si+count] = pivot;
        int i = si;
        int j = ei;
        while(i < j){
                if(input[i] <= pivot)
                        i++;
                else if(input[j] > pivot)
                        j--;
                else {
                        int temp = input[i];
                        input[i] = input[j];
                        input[j] = temp;
                        i++;
                        j--;
                }
        }
        return si + count;
}

void quickSort(int input[], int si, int ei){
        if(si >= ei)
                return;
        int midIndex = partition(input, si, ei);
        quickSort(input, si, midIndex-1);
        quickSort(input, midIndex+1, ei);                                                                                                                   
}  
void quickSort(int input[], int size) {
  quickSort(input, 0, size-1);

}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    quickSort(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}
