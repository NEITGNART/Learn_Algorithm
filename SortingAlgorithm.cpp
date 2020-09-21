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
  shell sort mỗi lần dịch chuyển thì nó sẽ dịch n / 2 khoảng trống
  và có nhiều cách cài đặt cho nên độ phức tạp của nó là một vấn đề mở
  có những cách đề xuất như sau:
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
