#include <bits/stdc++.h>

using namespace std;

int main(void) {

   int a[4] = {5,2,3,14};
  int saved;

  // Selection Sort
  for (int i = 0; i < 4; ++i){

    int index = i;

    for (int j = i + 1; j < 4; ++j){
      if (a[j] > a[index]) {
        index = j;
      }
    }
    if (i != index) {
        swap(a[i], a[index]);
    }
    
  }
  /*
  2 3 5 

  5,3,2,14,1


  5 3 2 14 1 

  3 5 

    2 3 5

	      14 		

  1 2 3 5 14 

** kết luận
luôn luôn bắt đầu tại ví trí thứ 2 

đặt saved  là phần tử hiện tại  saved = a[i];
kiểm tra phần tử đằng trước nếu mà phần tử đằng trước mà lớn hơn saved thì ta sẽ gán a[j] = a[j-1];
tức là gán phần tử đằng trước cho phần tử đằng sau cứ tiếp tục cho đến khi mà phần tử j = 0;
cuối cùng thì ta sẽ gán phần tử saved cho vị trí a[j]
  
  */
  // Insertion sort 
  for (int i = 1; i < 4; ++i) {
    saved = a[i];
    int j;
    for (j = i; j > 0 && a[j-1] > saved; --j) { 
      a[j] = a[j-1];
    }

    a[j] = saved; 
  }
  
/*
**SHELL SORT
  tư tưởng giống như insertion sort thay vì mỗi lần check inner loops chỉ
  dịch có 1 phần tử rồi tiếp tục làm như vậy thì
  shell sort mỗi lần dịch chuyển thì nó sẽ dịch n / 2 khoảng trống và mỗi lần giảm n / 2 ...tức là giảm theo loga tự nhiên
  cho đến khi = 0 và có nhiều cách cài đặt cho nên độ phức tạp của nó là một vấn đề mở có những cách đề xuất như sau:
  Shell đề xuất
    h1 = n
    hi+1 = h2i
  Hibbard đề nghị
    hi = 2i − 1
  Knuth đưa ra
    h1 = 1; hi+1 = 3hi + 1
  Pratt đề xuất
    h1 = 1; hi = 2p3q

  */
  for (int gap = n/2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; ++i) {
      int j;
      saved = a[i];
      for (j = i; j >= gap && a[j-gap] > saved; j -= gap)
          a[j] = a[j-gap];
      a[j] = saved;
    }	
  }
	
	
  for (int i = 0; i < 4; ++i){
    cout << a[i] << endl;
  }
}



// **phần bài về quicksort
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int partition(int s[], int l, int h) {
	int p; // pivot element index
	int firsthigh; // divider position for pivot
	
	p = h;
	firsthigh = l;
	for (int i = l; i < h; ++i) {
		if (s[i] < s[p]) {
			swap(s[i], s[firsthigh]);
			firsthigh++;
		}
			
		/*                                  0  1  2 3 4 5  6  7 8 9
		 * MẢNG BAN ĐẦU                     12 31 1 2 5 56 7 89 9 33
		 * đầu tiên chúng ta sẽ chọn 1 phần tử chốt đó là p = h = 33
		 * sau đó chọn firsthigh = l; chẳng hạn như trường hợp này
		 * thì l = 0 , tiếp tục vào vòng for
		 * 12 done thì firsthigh tăng 1 đơn vị thì sẽ thành 1
		 * cứ như vậy cho đến firsthigh =  5 thì if không thỏa 
		 *  khi đó thì s[i] = 7 < 33 cho nên nó sẽ swap nó với cả s[firsthigh]
		 *  mảng của chúng ta sẽ trở thành  12 31 1 2 5 7 56 89 9 33
		 *  có nghĩa là sẽ sẽ swap i = 6 với cả firsthigh = 5
		 *  khi swap xong thì firshigh sẽ thành firsthigh = 6
		 *  và i lúc này thành 7
		 *  9 < 33 cho nên sẽ swap i = 8 với firsthigh = 6 sẽ thành
		 *									12 31 1 2 5 7 9 89 56 33
		 * lúc này thì firsthigh sẽ thành 7
		 * 
		 */
		
	}
	swap(s[p], s[firsthigh]);
	/*
	 * cuối cùng là swap với cả p thì thằng 9 sẽ swap với thằng 7
	 *
	 *										12 31 1 2 5 7 9 33 56 89
	 * ok lặp lại tương tự
	 *
	 * mục đích của hàm partition là phân tách phần tử pivot
	 * những phần tử nhỏ hơn chốt sẽ được dịch qua bên trái của pivot
	 * còn những phần tử lớn hơn sẽ được dịch qua bên phải
	 */
	
	
	// trả về index của phần tử chốt
	return firsthigh;
}

void quicksort(int s[], int l, int h) {
	if (h - l > 0) {
		int p = partition(s, l, h);
		quicksort(s, l, p - 1);
		quicksort(s, p + 1, h);
	}
	/*
	 * khi chạy hết  quicksort(s, l, p - 1);
	 * thì nó đã được sắp xếp nằm bên trái của pivot
	 * còn phần bên phải của quicksort(s, p + 1, h);
	 * sẽ sắp xếp phần còn lại của mảng
	 */
}


int main(void) {

	int s[10] = {12,23,1,2,5,56,7,89,9,33 };
	for (int i = 0; i < 10; ++i) {
		cout << s[i] << " ";
	}
	cout << endl;
	cout << "Partition: "; partition(s, 0, 9);
	for (int i = 0; i < 10; ++i) {
		cout << s[i] << " ";
	}
	return 0;
}
