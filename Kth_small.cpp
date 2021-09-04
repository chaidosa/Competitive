#include<cmath>
#include<bits/stdc++.h>
using namespace std;
void swap(int* x, int* y);
 
class Minheap{
	int* harr; //pointer to array elements
	int capacity; //maximum size of head
	int heap_size; //current number of element in the heap

public:
	Minheap(int arr[], int size);//constructor
	void MinHeapify(int i);// index from which it is to be heapified
	int parent(int i){ return (i-1)/2;}
	int left(int i){ return (2*i+1);}
	int right(int i){ return (2*i+2);}

	int extractMin();
	int getMin(){ return harr[0];}
};

Minheap::Minheap(int arr[], int size)
{
	heap_size = size;
	harr = arr;
	int i =(heap_size-1)/2;

	while(i>=0){
		MinHeapify(i);
		i--;
	}

}

void Minheap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest =i;
	if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i) {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

int Minheap::extractMin()
{
    if (heap_size == 0)
        return INT_MAX;
 
    // Store the minimum vakue.
    int root = harr[0];
 
    // If there are more than 1 items, move the last item to root
    // and call heapify.
    if (heap_size > 1) {
        harr[0] = harr[heap_size - 1];
         heap_size--;
        MinHeapify(0);
    }
   
 
    return root;
}

int Kthsmall(int arr[],int n, int k){
	Minheap mh(arr, n);
	for (int i = 0; i < k - 1; i++)
        mh.extractMin();
 
    // Return root
    return mh.getMin();


}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n,k;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	cin>>k;
	cout<<"Kth smallest element is "<<Kthsmall(arr,n,k);

	return 0;
}
