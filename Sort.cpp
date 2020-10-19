#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


auto MinSort = [](auto& a) {
	int n = a.size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i] > a[j]) swap(a[i], a[j]);
		}
	}
};

auto print = [](int i) {
	cout << i << " ";
};

auto InsertionSort = [](auto& a) {

	int n = a.size();

	for (int i = 1; i < n; ++i) {

		int saved = a[i];
		int j;
		for (j = i; j > 0 && a[j-1] > saved; --j) {
			a[j] = a[j - 1];
		}
		a[j] = saved;
		
	}
	
};

auto SelectionSort = [](auto& a) {

	int n = a.size();
	
	for (int i = 0; i < n; ++i) {

		int saved = a[i];
		int index = i;
		
		for (int j = i + 1; j < n; ++j) {

			if (a[j]  < saved) {
				saved = a[j];
				index = j;
			}
		}
		if (i != index) swap(a[i], a[index]);
	}
};


auto ShellSort = [](auto &a) {
	int n = a.size();

	for (int gap = n/2; gap > 0; gap /=2) {
		for (int i = gap; i < n; ++i) {
			int saved = a[i];
			int j;
			for (j = i; j >= gap && a[j-gap] > saved; j -= gap) {
				a[j] = a[j - gap];
			}
			a[j] = saved;
		}
	}
	
};

auto Partition = [](auto& a, auto& l, auto& h) -> int{

	int p = h;
	int firsthigh = l;
	for (int i = l; i < h; ++i) {
		if (a[i] < a[p]) {
			swap(a[i], a[firsthigh++]);
		}
	}
	swap(a[p], a[firsthigh]);

	return firsthigh;
};

auto Partition_R = [](auto& a, int low, int high) -> int {
	srand(time(NULL));
	int random = low + rand() % (high - low);
	swap(a[random], a[high]);
	return Partition(a, low, high);
};

auto QuickSort = [](auto& a, int l, int h) -> void{
	if (h - l > 0) {
		int p = Partition_R(a, l, h);
		QuickSort(a, l, p - 1);
		QuickSort(a, p + 1, h);
	}
};

auto Heapify = [](auto& a, int n, int i) {
	int saved = a[i];
	while (i < n / 2) {

		int leftchild = 2 * i + 1;
		
		if (leftchild < n - 1) {
			if (a[leftchild] < a[leftchild + 1]) {
				leftchild++;
			}
		}
		if (saved >= a[leftchild]) break;
		a[i] = a[leftchild];
		i = leftchild;
	}
	a[i] = saved;
};

auto BuildHeap = [](auto& a) {
	int n = a.size();

	for (int i = n / 2 - 1; i >= 0; --i) {
		Heapify(a, n, i);
	}

};

auto HeapSort = [](auto& a) {
	int n = a.size();

	BuildHeap(a);
	for (int i = n-1; i >= 0; --i) {
		swap(a[0], a[i]);
		Heapify(a, i,0);
	}
	
};

auto BubbleSort = [](auto& a) {
	int n = a.size();

	for (int i = 0; i < n; ++i) {
		for (int j = n-1; j > i; --j) {
			if (a[i] > a[j]) swap(a[i], a[j]);
		}
	}
};

#define rep(i, n) for (int i = 0; i < (n); ++i)

auto Merge = [](auto& a, int low, int mid, int high) ->void {

	int n1 = mid - low + 1;
	int n2 = high - mid;

	vector<int> tmp1(n1);
	vector<int> tmp2(n2);

	rep(i, n1) tmp1[i] = a[i + low];
	rep(i, n2) tmp2[i] = a[i + mid + 1];

	int i(0), j(0), k = low;

	while (i < n1 && j < n2) {
		if (tmp1[i] < tmp2[j]) {
			a[k++] = tmp1[i++];
		} else {
			a[k++] = tmp2[j++];
		}
	}
	while (i < n1) a[k++] = tmp1[i++];
	while (j < n2) a[k++] = tmp2[j++];
	
};

auto MergeSort = [](auto& a, int low, int high) ->void {
	if (high - low > 0) {
		int mid = (low + high) / 2;
		MergeSort(a, low, mid);
		MergeSort(a, mid + 1, high);
		Merge(a, low, mid, high);
	}
};

auto CountingSort = [](auto& a) {
	int N = *max_element(a.begin(), a.end());
	int n = a.size();
	vector<int> T(N + 1);
	rep(i, N + 1) T[i] = 0;
	rep(i, n) T[a[i]]++;

	int k = 0;
	rep(i, N + 1) {
		while (T[i] > 0) {
			a[k++] = i;
			T[i]--;
		}
	}

};

int main(void) {

	vector<int> a{ 4,123,21,3,1,3,2,1,1 };

	MinSort(a);
	for_each(a.begin(), a.end(), print);  cout << endl;
	InsertionSort(a);
	for_each(a.begin(), a.end(), print); cout << endl;
	SelectionSort(a);
	for_each(a.begin(), a.end(), print); cout << endl;
	ShellSort(a);
	for_each(a.begin(), a.end(), print); cout << endl;
	QuickSort(a, 0, a.size() - 1);
	for_each(a.begin(), a.end(), print); cout << endl;
	HeapSort(a);
	for_each(a.begin(), a.end(), print); cout << endl;
	 BubbleSort(a);
	 for_each(a.begin(), a.end(), print); cout << endl;
	MergeSort(a, 0, a.size() -1);
	for_each(a.begin(), a.end(), print); cout << endl;
	 CountingSort(a);
	// RadixSort(a);
	for_each(a.begin(), a.end(), print); cout << endl;
	
	
	return 0;
}
