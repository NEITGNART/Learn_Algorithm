
#include <bits/stdc++.h>

using namespace std;

vector<int> PRE(const string& pattern) {
	int m = pattern.size();
	vector<int> next(m);

	int i = 0;
	int j = next[0] = -1;

	/*
	string text = "AAAAATTAAA";
	string pattern = "AAAT";
	*/
	//i = 1 và j = 0
	//next[0] = -1;'
	while (i < m -1) {
		if (j > -1 && pattern[i] != pattern[j]) j = next[j];
		++i;
		++j;
		next[i] = j;
	}
	return next;
	
/*
i = 1 và j = 0 thì  next[0] = -1 và next[1] = 0; (bất biến lúc nào cũng xảy ra)

	pattern[1] có bằng pattern[0] hay không (có bằng) thì i = 2 và j = 1 và next[2] = 1;

	pattern[2] có bằng pattern[1] hay không (có bằng) i = 3 j = 2 vậy next[3] = 2;

	pattern[3] có bằng pattern[2] hay không (không bằng) thì lúc này j = next[j] (có nghĩa là nhảy vào vị trí thích hợp)
	thì lúc này j = next[2] = 1 thì j = 1;
	i = 4  và j = 2 next[4] = 2;


		
	next[4] = 2;

	VẬY KẾT LUẬN RÚT RA LÀ NẾU MÀ VIỆC SO KHỚP VỚI BẢN THÂN MÀ TRÙNG NHAU thì bảng next[i] = j
	còn nếu không thì j = next[j] có nghĩa là là lùi về 1 vị trí thích hợp để tiếp tục việc so khớp
	CẢI TIẾN KHI MÀ thay vì next[j] phải backtrack lùi về vị trí mismatch thêm 1 lần nữa thì ta sẽ tiết kiệm ít nhất ít lần so
	khi đó chỉ cần thêm dòng lệnh if (pattern[i] == pattern[j]) next[i] = next[j];
		else next[i] = j;
*/
}

int KMP(const string& text, const string& pattern) {
	vector<int> next(PRE(pattern));


	int i = 0, j = 0, n = text.size(), m = pattern.size();
	cout << "m: " << m << endl;
	while (i < n) {
		// cout << "i: " << i << "   j: " << j << endl;
		while (j > -1 && text[i] != pattern[j]) {
			j = next[j];
			//cout << "       j: " << j << " ";
		}
		++i; ++j;
		if (j == m) return i - j;
	}
	return 0;
	/*
	m: 4
	i: 0   j: 0
	i: 1   j: 1
	i: 2   j: 2
	i: 3   j: 3
        	j: 2 i: 4   j: 3
       		j: 2 i: 5   j: 3
	Pattern: AAAT found at index = 2
	*/
}

int main(void) {

	string text = "AAAAATTAAA";
	string pattern = "AAAT";

	int x = KMP(text, pattern);

	if (x != 0) {
		cout << "Pattern: " << pattern << " found at index = " << x << endl;
	}
	else {
		cout << "Pattern: " << pattern << " not found.\n";
	}

	return 0;
}
