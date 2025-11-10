#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted subarrays arr[l..m] and arr[m+1..r]
void merge(vector<int>& arr, int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	vector<int> L(n1), R(n2);
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k++] = L[i++];
		} else {
			arr[k++] = R[j++];
		}
	}
	while (i < n1) arr[k++] = L[i++];
	while (j < n2) arr[k++] = R[j++];
}

// Recursive merge sort function
void mergeSort(vector<int>& arr, int l, int r) {
	if (l >= r) return;
	int m = l + (r - l) / 2;
	// Recursively sort first and second halves
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);
	// Merge the sorted halves
	merge(arr, l, m, r);
}

int main() {
	vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
	int n = arr.size();
	cout << "Original array: ";
	for (int x : arr) cout << x << " ";
	cout << endl;
	mergeSort(arr, 0, n - 1);
	cout << "Sorted array:   ";
	for (int x : arr) cout << x << " ";
	cout << endl;
	return 0;
}
