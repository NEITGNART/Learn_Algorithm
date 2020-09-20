#include <bits/stdc++.h>

using namespace std;


int Brute_Force_String(char str[], char pattern[], int n, int m) {
	
	for (int i = 0; i < n-m+1; ++i){
		bool flag = true;
		for (int j = 0; j < m && flag == true; ++j){
			if (pattern[j] != str[i+j]) flag = false;
		}
		if (flag) return 1;
	}
	return 0;
}

int main(void) {
	char str[] = "anhtiendeptrai";
	char pattern[] = "depasftrai";
	if (Brute_Force_String(str, pattern, strlen(str), strlen(pattern))) cout << "Found\n";
	else cout << "Not Found\n";
	return 0;
}
