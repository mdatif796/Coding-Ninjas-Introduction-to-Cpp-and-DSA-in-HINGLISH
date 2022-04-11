/*
Minimum Length Word

Given a string S (that can contain multiple words), you need to find the word which has minimum length.
Note : If multiple words are of same length, then answer will be first minimum length word in the string.
Words are seperated by single space only.

Input Format :
String S

Output Format :
Minimum length word

Constraints :
1 <= Length of String S <= 10^5

Sample Input 1 :
this is test string
Sample Output 1 :
is

Sample Input 2 :
abc de ghihjk a uvw h j
Sample Output 2 :
a
*/

#include <iostream>
#include<cstring>
using namespace std;

/* input - Input String
*  output - Save the result in the output array (passed as argument). You don’t have to 
*  print or return the result
*/
void minLengthWord(char input[], char output[]){
		
	// Write your code here	
    int count = 100;
    int len = strlen(input);
    int j  = 0;
    for(int i = 0; input[i] != '\0'; i++) {
        int x = 0;
        while(input[i] != ' ' || input[i] != '\0') {
            x++;
            i++;
        }
        if(x < count) {
            count = x;
            j = i - count;
        }
    }
    int k = 0;
    for(int i = j; input[i] != ' '; i++) {
        output[k] = input[i];
        k++;
    }
    output[k] = '\0';
    
// int length = strlen(input);
//  int index=0;

//  /* Initially set some large value to min */
//  int min = 100; // This is important
// 	int i,j,count=0;
//  /* Finding length of shortest word and starting index */
//  for( i = 0 ; i< length ; i++)
//  {
//   if(input[i] != ' ')
//   {
//    count++;
//   }
//   else
//   {
//    if(count < min)
//    {
//     min = count;
//     index = i-min;
//    }
//    count = 0;
//   }
//  }

//  /* Checking if last word is shortest */
//  if(count< min)
//  {
//   min = count;
//   index = length-min;
//  }

//  /* Using length and index copying shortest word */
//  j=0;
//  for(i=index;i< index+min;i++)
//  {
//   output[j] = input[i];
//   j++;
//  }

}

int main()
{
    char ch[10000], output[10000];
    cin.getline(ch, 10000);
    minLengthWord(ch, output);
    cout << output << endl;
}
