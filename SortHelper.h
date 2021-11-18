#ifndef SORTHELPER
#define SORTHELPER




#include<iostream>
#include<cassert>
using namespace std;


namespace SortHelper {

	int* generatRandomArray(int n, int rangeL, int rangeR) {
		assert(rangeR >= rangeL);
		int* arr = new int[n];
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}
		return arr;
	}

	template<typename T>

	bool isSorted(T arr[], int n) {
		for (int i = 0; i < n-1; i++) {
			if (arr[i]>arr[i + 1]){
				return false;
			}
		}
		return true;
	}

	template<typename T>
	void testSort(string sortname, void(*sort)(T[], int), T arr[] ,int n) {
		clock_t startime = clock();
		sort(arr,n);
		clock_t endtime = clock();
		/*for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
		}*/
		assert(isSorted(arr,n));
		cout << sortname << ":" << double(endtime - startime) / CLOCKS_PER_SEC << endl;

		//
		return;
	}


}

#endif // SORTHELPER