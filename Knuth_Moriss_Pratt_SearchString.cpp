#include <bits/stdc++.h>

using namespace std;

void PREKMP(char *pattern, int next[], int m) {
	int i = 0; 
	int j = next[0] = -1;
	while (i < m) {
		while (j > -1 && pattern[i] != pattern[j]) j = next[j];
		++i; ++j;
		if (pattern[i] == pattern[j]) {
			next[i] = next[j];
		}
		else next[i] = j;
	}
}

int KMP(char *text, char *pattern) {
	int n = strlen(text);
	int m = strlen(pattern);
	int next[m];
	PREKMP(pattern, next, m);
	int i = 0, j = 0;
	while (i < n) {
		while (j > -1 && text[i] != pattern[j]) j = next[j];
		++i; ++j;
		if (j >= m) return (i - j);
	}
	return -1;
}

int main(void) {
	
	char text[100];
	strcpy(text, "Anhtiendeptrai");
	char pattern[100];
	strcpy(pattern, "tien");
	if (KMP(text, pattern) != -1) cout << "Found at index: " << KMP(text, pattern) << endl;
	else cout << "Not Found\n";
	return 0;
}
