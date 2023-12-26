#include<iostream>
using namespace std;

int array[8] = { 1,5,14,7,8,4,99,4 };
int i,j;
int l,r;
int K;
int partition(int l, int r) { 
    int pivot = array[r], i = l; 
    for (int j = l; j <= r - 1; j++) if (array[j] <= pivot) { 
            swap(array[i], array[j]); 
            i++; 
        } 
    swap(array[i], array[r]); 
    return i; 
}

int quickSelect(int l, int r, int k){
	if(k > 0 && k <= r +1){
		int index = partition(l,r);
		if(index == k - 1) return array[index]; // npr. 4-0 == 5-1(pivot je 4 u nizu tako da je 5 najmanji(0,1,2,3,4))
		if(index > k-1) return quickSelect(l, index-1, k); // ako je index veci onda znaci da je k-ti element u levom delu
		return quickSelect(index +1, r, k); // k-ti element je u desnom delu i tu
	}
}


main(){
	K = 3;
	cout << quickSelect(0,7,K);
}

