#ifndef SORT
#define SORT




#include<iostream>
#include<algorithm>
#include "SortHelper.h"


using namespace std;


template <typename T>
void selectionSort(T arr[], int n) {

	for (int i = 0; i < n; i++) {
		int minindex = i;
		for (int j = i; j < n; j++) {
			if (arr[j] < arr[minindex]) {
				minindex = j;
			}
		}
		swap(arr[i], arr[minindex]);
	}
}





template <typename T>
void insectionSort(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j - 1 >= 0 && arr[j] < arr[j - 1]; j--) {
			swap(arr[j], arr[j-1]);
		}
	}
}

template <typename T>
void Merge(T arr[], int l,int mid, int r) {
	T* aux = new T[r - l + 1];
	for (int i = l; i <= r; i++) {
		aux[i - l] = arr[i];
	}
	int i = l;
	int j = mid + 1;
	for (int k = l; k <= r; k++) {
		if (i > mid) {
			arr[k] = aux[j - l];
			j++;
		}
		else if(j > r){
			arr[k] = aux[i - l];
			i++;
		}
		else if (aux[i-l] < aux[j-l]) {
			arr[k] = aux[i - l];
			i++;
		}
		else{
			arr[k] = aux[j - l];
			j++;
		}
	}


}

template <typename T>
void _Mergesort(T arr[], int l, int r) {

	if (l >= r) {
		return;
	}
	int mid = l + (r - l)/2;
	_Mergesort(arr, l, mid);
	_Mergesort(arr, mid + 1, r);
	if (arr[mid] > arr[mid + 1]) {
		Merge(arr, l, mid, r);
	}
}





template <typename T>
void MergeSort(T arr[],int n) {
	_Mergesort(arr, 0, n-1);
}


template <typename T>
void MergeSortBU(T arr[], int n) {
	for (int sz = 1; sz < n; sz += sz) {
		for (int i = 0; i + sz < n; i += sz + sz) {
			if (arr[i + sz - 1] > arr[i + sz]) {
				Merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
			}
			
		}
	}
}




template <typename T>
int _partition(T arr[], int l, int r) {
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	int i = l + 1;
	int j = r;
	while (true)
	{
		while (i <= j && arr[i] < arr[l]) {
			i++;
		}
		while (i <= j && arr[j] > arr[l]) {
			j--;
		}
		if (i >= j) {
			break;
		}
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	swap(arr[l], arr[j]);
	return j;
}



template <typename T>
void _QuickSort2Way(T arr[], int l, int r) {
	if (l >= r) {
		return;
	}
	int p = _partition(arr, l, r);
	_QuickSort2Way(arr, l, p - 1);
	_QuickSort2Way(arr, p + 1, r);
	
}

template <typename T>
void _QuickSort3Way(T arr[], int l, int r) {
	if (l >=r) {
		return;
	}
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	int gt = r + 1;
	int i = l + 1;
	int lt = l;
	while (i < gt)
	{
		if (arr[l] > arr[i]) {
			lt++;
			swap(arr[i], arr[lt]);
			i++;
		}
		else if (arr[l] < arr[i]) {
			gt--;
			swap(arr[i] , arr[gt]);
		}
		else {
			i++;
		}
	}
	swap(arr[l], arr[lt]);

	/*for (int i = l; i < r; i++)
		cout << arr[i]<<"  ";
	cout << endl;*/

	_QuickSort3Way(arr, l, lt - 1);
	_QuickSort3Way(arr, gt, r);
}


template <typename T>
void QuickSort2Way(T arr[], int n) {
	_QuickSort2Way(arr, 0, n - 1);
}



template <typename T>
void QuickSort3Way(T arr[], int n) {
	_QuickSort3Way(arr, 0, n - 1);
}

template <typename T>
void siftDown(T arr[], int k, int n) {
	while (2 * k + 1 < n) {
		int j = 2 * k + 1;
		if (j + 1 < n && arr[j] < arr[j + 1]) {
			j++;
		}

		if (arr[k] >= arr[j]) {
			break;
		}
		swap(arr[k], arr[j]);
		k = j;
	}
}


//‘≠µÿ∂—≈≈–Ú
template <typename T>
void HeapSort(T arr[], int n) {

	if (n <= 1) {
		return;
	}

	for (int i = (n - 2) / 2; i >= 0; i--) {
		siftDown(arr, i, n);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		siftDown(arr, 0, i);
	}
}





template<typename T>
void ShellSort(T arr[], int n) {
	int h = n / 2;
	while (h>=1)
	{
		for (int start = 0; start < h; start++) {
			for (int i = start + h; i < n; i += h) {
				T t = arr[i];
				int j;
				for (j = i; j - h >= 0 && t < arr[j - h]; j -= h) {
					arr[j] = arr[j - h];
				}
				arr[j] = t;
			}
		}
		h /= 2;
	}
}


#endif // SORT