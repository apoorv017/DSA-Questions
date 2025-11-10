#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int lo, int hi) {
	int pivot = a[hi];
	int i = lo; // place for next smaller element
	for (int j = lo; j < hi; ++j) {
		if (a[j] <= pivot) {
			swap(a[i], a[j]);
			++i;
		}
	}
	swap(a[i], a[hi]);
	return i;
}

void quickSort(vector<int> &a, int lo, int hi) {
	if (lo >= hi) return;
	int p = partition(a, lo, hi);
	quickSort(a, lo, p - 1);
	quickSort(a, p + 1, hi);
}

int main() {
    int n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	quickSort(a, 0, n - 1);

	for (int i = 0; i < n; ++i) {
		if (i) cout << ' ';
		cout << a[i];
	}
	cout << '\n';
	return 0;
}
