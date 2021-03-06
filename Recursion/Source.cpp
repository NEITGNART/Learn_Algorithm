#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <iomanip>
// #include <bits/stdc++.h>

using namespace std;
int X(int n);
int Y(int n);
/*1. Fibonacci
f(0) = f(1) = 1
f(n) = f(n-1) + f(n-2), n>1*/

int Fibonacci(int n) {

	if (n <= 1) return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int Fibonacci_Kaisen(vector <int> &a) {
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i < a.size(); ++i) {
		a[i] = a[i - 1] + a[i - 2];
	}
	return a[a.size()-1];
}

/*2. x(n), y(n)
x(0) = 1
y(0) = 0
x(n) = x(n-1) + y(n-1)
y(n) = 3*x(n-1) + 2*y(n-1)*/
int X(int n) {
	if (n == 0) return 1;
	return X(n - 1) + Y(n - 1);

}

int Y(int n) {
	if (n == 0) return 0;
	return 3 * X(n - 1) + 2 * Y(n - 1);
}


/*

x(0) = 1
x(n) = n2
x(0) + (n-1)2

x(1) + ... + (n-i)2

x(i) + ... 22

x(n-2) + 12
x(n-1)

*/

int X_Kaisen(int n) {
	if (n == 0) return 1;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += pow((n - i), 2)*X_Kaisen(i);
	}
	return sum;
}

int C(int n, int k) {
	if (k > n) {
		cout << "Error syntax !";
		exit(0);
	}
	if (k == 0 || k == n) {
		return 1;
	}
	return C(n - 1, k) + C(n - 1, k - 1);
}

void toBinary(int x) {
	if (x == 0) return;
	toBinary(x / 2);
	cout << x % 2;
}

int sumOfDigits(int x) {
	if (x == 0) return 0;
	return x + sumOfDigits(x - 1);
}

void dfs(int idx, vector<int>& path, vector<vector<int>>& res,  vector<int>& nums) {

	res.push_back(path);
	
	for (int i = idx; i < nums.size(); ++i){
		path.push_back(nums[i]);
		dfs(i + 1, path, res, nums);
		path.pop_back();

	}
}

vector<vector<int>> subsets(vector<int> nums) {
	vector<vector<int>> res;
	vector<int> path;
	dfs(0, path, res, nums);
	return res;
}

void DFS(int var, vector<vector<int>>& res, vector<int>& path, vector<bool>& visited, vector<int> nums) {
	if (var == nums.size()) {
		res.push_back(path);
		return;
	}
	else {
		for (int i = 0; i < nums.size(); ++i) {
			if (visited[i] == false) {
				visited[i] = true;
				path.push_back(nums[i]);
				DFS(var + 1, res, path, visited, nums);
				path.pop_back();
				visited[i] = false;
			}
		}
	}
}


vector<vector<int>> permutation(vector<int> nums) {
	vector<vector<int>> res;
	vector<int> path;
	vector<bool> visited(nums.size(), false);
	DFS(0, res, path, visited, nums);
	return res;

}

signed main() {
	//Note, we use n is variant for solve all the problem- Maybe in eight quees problem we use 4*4
	
	
	
	/*Write the function/code to solve problem here(Fibonacci)*/
	//We use n is variant
	int n = 5; // answer is 5
//	cout << Fibonacci(n);
	/*vector <int> a(n);
	cout << Fibonacci_Kaisen(a);*/

	/*Write the function/code to solve problem here(x(n), y(n))*/
	// adjusted n = 1 answer is : X = 1, Y = 3; 
	//cout << X(n) << endl; 
	//cout << Y(n) << endl;

	/*Write the function/code to solve problem here(X(n))*/

	// cout << X_Kaisen(2);

	// 2^2*X(0) + 1^2*X(1)= 1^2*1*1*X(0), answer is 5 :>
	/*Write the function/code to solve problem here(C(n, k))*/
	//cout << C(n, 3);
	/*Write the function/code to solve problem here(toBinary)*/
//	toBinary(n);
	/*Write the function/code to solve problem here(sumofDigits)*/
	//cout << sumOfDigits(n);
	// Subset using dfs
	vector<vector<int>> a;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	/*a = subsets(nums);*/
	a = permutation(nums);
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a[i].size(); ++j) {
			cout << "[" << a[i][j] << "]";
		}
		cout << endl;
	}
	
}