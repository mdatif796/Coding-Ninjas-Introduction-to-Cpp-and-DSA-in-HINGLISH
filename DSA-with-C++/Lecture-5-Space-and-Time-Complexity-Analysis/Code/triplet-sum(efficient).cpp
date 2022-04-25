/*
Triplet sum

You have been given a random integer array/list(ARR) and a number X. Find and return the triplet(s) in the array/list which sum to X.

Note :
Given array/list can contain duplicate elements.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains an integer 'X'.

Output format :
For each test case, print the total number of triplets present in the array/list.

Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
0 <= X <= 10^9

Time Limit: 1 sec

Sample Input 1:
1
7
1 2 3 4 5 6 7 
12
Sample Output 1:
5

Sample Input 2:
2
7
1 2 3 4 5 6 7 
19
9
2 -5 8 -6 0 5 10 11 -3
10
Sample Output 2:
0
5
Explanation for Input 2:
Since there doesn't exist any triplet with sum equal to 19 for the first query, we print 0.

For the second query, we have 5 triplets in total that sum up to 10. They are, (2, 8, 0), (2, 11, -3), (-5, 5, 10),
 (8, 5, -3) and (-6, 5, 11)
*/

#include <iostream>
#include <algorithm>
using namespace std;

int pairSum(int *arr, int n, int num){
    int startIndex = 0; 
    int endIndex = n - 1;
    int countPairs = 0;
    while(startIndex < endIndex){
        if(arr[startIndex] + arr[endIndex] < num)
            startIndex++;
        else if(arr[startIndex] + arr[endIndex] > num)
         endIndex--;   
        else {
            int temp1 = arr[startIndex];
            int temp2 = arr[endIndex];
            // if the array has same elements
            if(arr[startIndex] == arr[endIndex]){
                int totalElements = endIndex - startIndex + 1;
                countPairs += ((totalElements - 1) * totalElements)/2;
                return countPairs;
            }
            int count1 = 0;
            int count2 = 0;
            // if the array has duplicate elements
            while(startIndex <= endIndex && arr[startIndex] == temp1){
                count1++;
                startIndex++;
            }
            while(endIndex >= startIndex && arr[endIndex] == temp2){
                count2++;
                endIndex--;
            }
            countPairs += (count1 * count2);
        }
    }
    return countPairs;
}

int tripletSum(int *arr, int n, int num)
{
    sort(arr, arr + n);
    int tripletCount = 0;
	for(int i = 0; i < n-2; i++){
        tripletCount += pairSum(arr+i+1, n-i-1, num-arr[i]);
    }
    return tripletCount;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}