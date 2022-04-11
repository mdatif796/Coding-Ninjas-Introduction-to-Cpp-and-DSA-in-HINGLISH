/*
Rotate array

You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).
 Note:
Change in the input array/list itself. You don't need to return or print the elements.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains the value of 'D' by which the array/list needs to be rotated.
Output Format :
For each test case, print the rotated array/list in a row separated by a single space.


Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^4
0 <= N <= 10^6
0 <= D <= N
T
ime Limit: 1 sec

Sample Input 1:
1
7
1 2 3 4 5 6 7
2
Sample Output 1:
3 4 5 6 7 1 2

Sample Input 2:
2
7
1 2 3 4 5 6 7
0
4
1 2 3 4
2
Sample Output 2:
1 2 3 4 5 6 7
3 4 1 2
*/

#include <iostream>
using namespace std;

void rotate(int *input, int d, int n)
{
    //Write your code here
    
    // 3rd Approach
    // reverse the whole array
    int start = 0;
    int end = n - 1;
    while(start < end) {
        int temp = input[start];
        input[start] = input[end];
        input[end] = temp;
        start++;
        end--;
    }
    
    // reverse the n-d elements of an array
    start = 0;
    end = n - d - 1;
    while(start < end) {
        int temp = input[start];
        input[start] = input[end];
        input[end] = temp;
        start++;
        end--;
    }
    
    // Now reverse the last d elements of an array
    start = n - d;
    end = n - 1;
    while(start < end) {
        int temp = input[start];
        input[start] = input[end];
        input[end] = temp;
        start++;
        end--;
    }
    
    
    
//     // 2nd Approach
//     // copy the first d element in temp array
//     int temp[d];
//     for(int i = 0; i < d; i++) {
//         temp[i] = input[i];
//     }
    
//     // Now shift our input array left by d position
//     for(int i = d; i < n; i++) {
//         input[i-d] = input[i];
//     }
    
//     // copy the first d elements from temp array to input array
//     int k = 0;
//     for(int i = n-d; i < n; i++) {
//         input[i] = temp[k];
//         k++;
//     }
    
    // 1st Approch
    // while(d--) {
    //     int k = input[0];
    //     for(int i = 1; i < n; i++) {
    //         input[i-1] = input[i];
    //     }
    //     input[n-1] = k;
    // }
}

// This comment is for 1st Approach
/*
 take 0 index element and store it in k.
 now run a loop from index 1 and shift an array by one position to left.
 and put the value of k into last index.
 Run this all by 2 because here we shift left by 2 position
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

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}