/*
Code Bubble Sort

Provided with a random integer array/list(ARR) of size N, you have been required to sort this array using 'Bubble Sort'.
Note:
Change in the input array/list itself. You don't need to return or print the elements.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Output format :
For each test case, print the elements of the array/list in sorted order separated by a single space.

Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^3

Time Limit: 1 sec

Sample Input 1:
1
7
2 13 4 1 3 6 28
Sample Output 1:
1 2 3 4 6 13 28

Sample Input 2:
2
5
9 3 6 2 0
4
4 3 2 1
Sample Output 2:
0 2 3 6 9
1 2 3 4
*/
#include <iostream>
using namespace std;

void bubbleSort(int *input, int size) {
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(input[j] > input[j+1]){
                int temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;
            }
        }
    }
}



/*
void bubbleSort(int *input, int size)
{
    //Write your code here
    int start = 0;
    int end = size - 1;
    while(end > start){
        // run a loop from 0 to end to check the greatest element
        for(int i = 0; i < end; i++){
            // Swap
            if(input[i] > input[i+1]){
                int temp = input[i];
                input[i] = input[i+1];
                input[i+1] = temp;
            }
        }
        end -= 1;
    }
}
*/

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int size;
        cin >> size;

        int *input = new int[size];

        for (int i = 0; i < size; ++i)
        {
            cin >> input[i];
        }

        bubbleSort(input, size);

        for (int i = 0; i < size; ++i)
        {
            cout << input[i] << " ";
        }

        delete[] input;
        cout << endl;
    }
}