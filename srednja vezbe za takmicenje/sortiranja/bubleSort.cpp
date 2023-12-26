
// example: 2 1 5 4 3
//			2->1 = 1 2 => 1 2 5 4 3 => 1 2 5->4 => 1 2 4 5 3 => 1 2 4 3 5
//	second loop (n - i) 1 2 4->3 5 => 1 2 3 4 5
// last loop if no swap break
// from 0 to n-1-i loop swap if element[i],element[i+1]
// last element will always be maximum and rest will sort in next loops
// bubble sort will sort by swaping elements by pushing max at end and wont have to check max in next loops

// Optimized implementation of Bubble sort 
#include <stdio.h> 
  
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// An optimized version of Bubble Sort // 
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   bool swapped; 
   for (i = 0; i < n-1; i++) 
   { 
     swapped = false; 
     for (j = 0; j < n-i-1; j++) 
     { 
        if (arr[j] > arr[j+1]) 
        { 
           swap(&arr[j], &arr[j+1]); 
           swapped = true; 
        } 
     } 
  
     // IF no two elements were swapped by inner loop, then break 
     if (swapped == false) 
        break; 
   } 
} 
  
/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("n"); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    bubbleSort(arr, n); 
    printf("Sorted array: \n"); 
    printArray(arr, n); 
    return 0; 
} 
