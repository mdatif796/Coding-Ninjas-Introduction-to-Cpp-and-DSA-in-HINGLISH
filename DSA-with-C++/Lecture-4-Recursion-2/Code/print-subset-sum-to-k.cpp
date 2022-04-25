/*
Print Subset Sum to K

Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.

Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 

Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output:
3 3
5 1
*/

#include <iostream>
using namespace std;

void helper(int input[], int inputSize, int output[], int outputSize, int k){
    if(inputSize == 0){
        int sum = 0; 
        // find sum of output array
        for(int i = 0; i < outputSize; i++)
            sum += output[i];
        // check if sum is equal to zero
        if(sum == k){
            // if equal print the output array
            for(int i = 0; i < outputSize; i++){ 
                cout << output[i];
                // because we haven't print space after last element
                if(i != outputSize-1)
                    cout << " ";
            }
            cout << endl;
        }
        return;
    }
    // let's not include the input[0]
    helper(input+1, inputSize-1, output,outputSize, k);
    // create new array
    int newOutput[outputSize+1];
    // copy the element to new array
    for(int i = 0; i < outputSize; i++)
        newOutput[i] = output[i];
    // put input[0] to last index of new array
    newOutput[outputSize] = input[0];
    // let's include the input[0] to the array
    helper(input+1, inputSize-1, newOutput, outputSize+1, k);
}
void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int output[0];
    helper(input, size, output, 0, k);
}

int main()
{
    int input[1000], length, k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    cin >> k;
    printSubsetSumToK(input, length, k);
}
