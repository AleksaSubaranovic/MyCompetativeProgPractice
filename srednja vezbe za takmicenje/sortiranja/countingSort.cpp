
// Counting SORT:
// first we make 2 arrays one for values other one for how many times every value repeats(unique)
// example: 1, 4, 1, 2, 7, 5, 2
// max is 7, min is 1
// value: 1 2 3 4 5 6 7
// count: 2 2 0 1 1 0 1
// now kinda fibanachi this by making every element of count array sum of itself and previous element
// count: 2 4 4 5 6 6 7
// now use value array and store result in empty array or array that wont be used anymore and has needed length
// current arrays:

// array: 1 4 1 2 7 5 2

// value: 1 2 3 4 5 6 7
// count: 2 4 4 5 6 6 7

// check space for 1(its 2)then decrease count spase
// check space for 4(space 5, will decrease to 4)
// check for 1(space is 1)
// current count: 0 4 4 4 6 6 7
// current array: 1 1 X X 4 X X
// then space for 2 is 4, space for 7 is 7, space for 5 is 6, space for 2 is 3(previous 2 reduced space from 4 to 3)
// new  : 1 1 2 2 4 5 7 

// counting sort uses all element values, makes array of all values between min and max element(float problem)
// makes array for counting how many times values repeat
// by using kinda fibanachi it gets positions for every element sorted , max will be biggest position(last) and min will be smallest
// then use positions to store values from original array but for every usage of same value reduce position, that way 2 same values are next to eachother

// C++ Program for counting sort 
#include<bits/stdc++.h> 
#include<string.h> 
using namespace std; 
#define RANGE 255 

// The main function that sort 
// the given string arr[] in 
// alphabatical order 
void countSort(char arr[]) 
{ 
	// The output character array 
	// that will have sorted arr 
	char output[strlen(arr)]; 

	// Create a count array to store count of inidividul 
	// characters and initialize count array as 0 
	int count[RANGE + 1], i; 
	memset(count, 0, sizeof(count)); 

	// Store count of each character 
	for(i = 0; arr[i]; ++i) 
		++count[arr[i]]; 

	// Change count[i] so that count[i] now contains actual 
	// position of this character in output array 
	for (i = 1; i <= RANGE; ++i) 
		count[i] += count[i-1]; 

	// Build the output character array 
	for (i = 0; arr[i]; ++i) 
	{ 
		output[count[arr[i]]-1] = arr[i]; 
		--count[arr[i]]; 
	} 

	/* 
	For Stable algorithm 
	for (i = sizeof(arr)-1; i>=0; --i) 
	{ 
		output[count[arr[i]]-1] = arr[i]; 
		--count[arr[i]]; 
	} 
	
	For Logic : See implementation 
	*/

	// Copy the output array to arr, so that arr now 
	// contains sorted characters 
	for (i = 0; arr[i]; ++i) 
		arr[i] = output[i]; 
} 

// Driver code 
int main() 
{ 
	char arr[] = "geeksforgeeks"; 

	countSort(arr); 

	cout<< "Sorted character array is " << arr; 
	return 0; 
} 

// This code is contributed by rathbhupendra 

