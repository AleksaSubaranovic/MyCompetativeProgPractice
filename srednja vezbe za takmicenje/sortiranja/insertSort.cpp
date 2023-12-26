
// example 2 1 5 4 3
// first loop 1->2 => 1 2 5 4 3
// secon loop 1 2 5, fine // third loop 1 2 5 4, 4->5 => 1 2 4 5
// forth loop 1 2 4 5 3, 3->5 => 1 2 4 3 5 => 1 2 3 4 5
// n-1 times check if element[i] is lower then element[j(j = i-1, j--)] if lower then element[j+1] = element[j]
// element[j+1] once j loop breaks = element[i(orig)]
// algorithm sorts by inserting, moving lower element behind and changing elements in front to stay sorted

// C++ program for insertion sort 
#include <bits/stdc++.h> 
using namespace std; 

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n) 
{ 
	int i, key, j; 
	for (i = 1; i < n; i++) 
	{ 
		key = arr[i]; 
		j = i - 1; 

		/* Move elements of arr[0..i-1], that are 
		greater than key, to one position ahead 
		of their current position */
		while (j >= 0 && arr[j] > key) 
		{ 
			arr[j + 1] = arr[j]; 
			j = j - 1; 
		} 
		arr[j + 1] = key; 
	} 
} 

// A utility function to print an array of size n 
void printArray(int arr[], int n) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

/* Driver code */
int main() 
{ 
	int arr[] = { 12, 11, 13, 5, 6 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	insertionSort(arr, n); 
	printArray(arr, n); 

	return 0; 
} 

// This is code is contributed by rathbhupendra 

