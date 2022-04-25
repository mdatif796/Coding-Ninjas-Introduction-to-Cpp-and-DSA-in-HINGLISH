/*
Stock Span
Afzal has been working with an organization called 'Money Traders' for the past few years. The organization is into the money trading business. His manager assigned him a task. For a given array/list of stock's prices for N days, find the stock's span for each day.
The span of the stock's price today is defined as the maximum number of consecutive days(starting from today and going backwards) for which the price of the stock was less than today's price.
For example, if the price of a stock over a period of 7 days are [100, 80, 60, 70, 60, 75, 85], then the stock spans will be [1, 1, 1, 2, 1, 4, 6].

Explanation:
On the sixth day when the price of the stock was 75, the span came out to be 4, because the last 4 prices(including the current price of 75) were less than the current or the sixth day's price.

Similarly, we can deduce the remaining results.
Afzal has to return an array/list of spans corresponding to each day's stock's price. Help him to achieve the task.

Input Format:
The first line of input contains an integer N, denoting the total number of days.

The second line of input contains the stock prices of each day. A single space will separate them.

Output Format:
The only line of output will print the span for each day's stock price. A single space will separate them.

Note:
You are not required to print the expected output explicitly. It has already been taken care of. 

Constraints:
0 <= N <= 10^7
1 <= X <= 10^9
Where X denotes the stock's price for a day.

Time Limit: 1 second

Sample Input 1:
4
10 10 10 10
Sample Output 1:
1 1 1 1 

Sample Input 2:
8
60 70 80 100 90 75 80 120
Sample Output 2:
1 2 3 4 1 1 2 8 
*/

#include <iostream>
#include <stack>
using namespace std;

#include<stack>

int* stockSpan(int *price, int size)  {
	// Write your code here
    int *output = new int[size];
    stack<int> s;
    // push first index into the stack
    s.push(0);
    // first day stock has always span 1
    output[0] = 1;
    // iterating from first index
    for(int i = 1; i < size; i++){
        // pop from the stack until we find the greater value index than present index or stack becomes empty
        while(!s.empty() && price[s.top()] < price[i])
            s.pop();
        // if stack is empty then the span has value index + 1 , and push that index to stack
        if(s.empty()){
            output[i] = i + 1;
            s.push(i);
        // if stack is not empty then the span has value difference between them and again push that index to stack
        } else {
            output[i] = i - s.top();
            s.push(i);
        }
    }
    return output;
    
    

    
    
    // int *output = new int[size];
    // int count;
    // int k = 0;
    // for(int i = 0; i < size; i++){
    //     count = 1;
    //     for(int j = i; j >= 0; j--){
    //         if(i != j && price[i] == price[j])
    //             break;
    //         if(price[j] < price[i])
    //             count++;
    //         else if(price[j] > price[i])
    //             break;
    //     }
    //     output[k++] = count;
    // }
    // return output;
}

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}