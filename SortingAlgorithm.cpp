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
kiểm tra phần tử đằng sau nếu mà phần tử đằng sau mà lớn hơn saved thì ta sẽ gán a[j] = a[j-1];
tức là gán phần tử đằng sau cho phần tử đằng trước cứ tiếp tục cho đến khi mà phần tử j = 0;
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
	int p = h; // pivot element index
	int firsthigh = l; // divider position for pivot 
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




/*

	Bắt đầu từ mảng [6, 5, 4, 3, 2, 1]
	            	 0  1   2  3  4  5   
			6
		       
		    5	     4
			
		3     2        1

Buiding MIN_HEAP tree ROOT = (i - 1)/2
		    LEFT CHILD = (2*i + 1)
 		    RIGHT CHILD = (2*i + 2)

đầu tiên bắt đầu ở vị trí là n / 2 -1 có nghĩa là vị ở ở giữa 
chúng ta có 6 phần tử đó đó a[i] = a[mid] = a[6/2-1] = a[2] = 4 <i> =2 
khởi tạo saved = a[i]   =  a[n/2 -1] = 4 |  <saved = 4>
trong vòng while chỉ chạy đến n / 2 
do đó child = 2 * (n / 2 -1) + 1  = 2 *2 = 5; 
if (child < n - 1) rồi kiểm tra tiếp là a[child] có lớn hơn a[child+1] hay không
nghĩa là 5 so với 5 thì false 
-> child = 5
kiểm tra saved <= a[5] hay không . Thì saved = 4   <= 1 là sai nên ko break
gán a[i] = a[child] có nghĩa là gán a[2] = a[5] 
 <a[2] = 1>
 <i = 5>
check 5 < 3 false thoát while

xuống dưới gán a[5] = 4 => <a[5] = 4>

Do đó mảng trở thành [6, 5, 1, 3, 2, 4]
		    0   1   2  3  4  5

-- --->
    			        6

 		            5      1

		        3     2     4

----->>


tiếp theo đi dần xuống phía bên trái của mảng 
do đó ở trên i = 2 thì vòng lặp tiếp theo thì i = 1
saved = a[1] = 5
child = 2 * i + 1 = 3 

xét xem child có phải là kế cuối hay chưa
3 < 5 và a[3] = 3 có lớn hơn a[4] hay không thì 3 > 2
do đó child = 4
xét xem 5 <= 2 hay ko thì là false
do đó <a[1] = 2>
và i = child và i = 4

4 < 3 là sai nên break while loops

ra ngoài thì gán <a[4] = 5>

Do đó mảng trở thành [6, 2, 1, 3, 5, 4]
		    0   1   2  3  4  5
  			       6
	
 		            2     1

		        3      5       4


------>>>

cuối cùng là xét đến nút gốc thì kiểm tra xem là
bên trái và bên phải thằng nào lơn hơn thì lấy thằng 2 > 1 thì lấy thằng 1
tại do làm MIN HEAP
do 6 nó lớn 5 nên 
gán a[1] = 1
 i = 2 
saved = 6
child = 2 


<a[0] = 1>  và i = 2 
Do đó mảng trở thành [1, 2, 1, 3, 5, 4]
		    0   1   2  3  4  5


			       1
	
 		            2     1

		        3     5       4


tiếp tục do 2 < 3 nên tiếp tục vòng while thì 
child = 5


saved = 6 <= 4 là sai nên 
 
<a[2] = a[5] = 4>

i = 5 

a[5] = 6

Do đó mảng trở thành [1, 2, 4, 3, 5, 6]
		    0   1   2  3  4  5
  
			       1 
	
 		            2     4

		        3     5       6

Build Heap đã xong


Bây giờ chuyển qua sort 

Tư tưởng giống như là selection sert mỗi lần sort xong thì chèn vào cuối mảng
làm tương tự như vậy cho đến khi hết phần tử 
có thể xem trên geekforgeek

Mỗi lần mà Heapify thì chắc chắn là phần tử nhỏ nhất sẽ nằm ở root
khi đó chỉ cần swap root với phần tử cuối cùng lần lượt thu hẹp đến đầu mảng
thì hoàn thành


Muốn trở thành Max Heap thì khi mà so sánh 2 nodes con thì 
ta sẽ lấy thằng nào mà lớn là ok.




*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*
 * 
 */
void Heapify(int a[], int n, int i) {
//	cout << "initialize i: " << i << endl;
	int saved = a[i]; 
	
	while (i < n/2) { 
		int child = 2 * i + 1;
	//	cout << "child: " << child << endl;
		if (child < n - 1)
		if (a[child] > a[child + 1]) { /*cout << "child++" << endl; */++child; }
		if (saved <= a[child]) break;
		a[i] = a[child];
	//	cout << "a[i]: " << a[i] << " ";
		i = child;
	//	cout << "i: " << i <<  " " <<  endl;
	}
	a[i] = saved;
//	cout << "a[i]: outter loops: " << a[i] << endl;
	
}

void BuildHeap(int a[], int n) {
	for (int i = n / 2 - 1; i >= 0; --i) {    
		Heapify(a, n, i);
	}
}

void HeapSort(int a[], int n) {
	BuildHeap(a, n);
	for (int i = n-1; i >= 0; --i) {
		swap(a[0], a[i]);
		Heapify(a, i, 0);
		
	}
	
}

int main(void) {

	const int n = 6;
	int a[n] = {6,5,4,3,2,1};

	HeapSort(a, n);
	for (int i = 0; i < 6; ++i) {
			cout << a[i] << " ";
		}
		cout << endl;
	return 0;
}

// ********************** Merge Sort using devide and conquer like quicksort but quicksort using randomize
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void merge(int a[], int l, int m, int h) {

	// tạo 2 mảng tạm

	int n1 = m - l + 1;
	int n2 = h - m;

	vector<int> b(n1), c(n2);
	
	
	for (int i = 0; i < n1; ++i) {
		b[i] = a[l + i];  // chạy đến mid
	}

	for (int j = 0; j < n2; ++j) {
		c[j] = a[m + j + 1] ; // chạy từ mid + 1 trở đi
	}
	
	
	int i = 0, j = 0, k = l;
	// dùng 3 while để merge
	//   5 2 3  
	//   7 4 1 4

	while (i < n1 && j < n2) {
		if (b[i] < c[j]) {
			a[k] = b[i];
			++i; ++k;
		}
		else {
			a[k] = c[j];
			++j; ++k;
		}
	}
	while (i < n1) {
		a[k] = b[i];
		++i; ++k;
	}
	while (j < n2) {
		a[k] = c[j];
		++j; ++k;
	}
}

void MergeSort(int a[], int l, int h) {
	if (h-l > 0) {
		int mid = (l + h )/ 2;
		MergeSort(a, l, mid);
		MergeSort(a, mid + 1, h);
		merge(a, l, mid, h);
	}
}


int main(void) {

	const int n = 6;
	int a[n] = {6,5,4,3,2,1};

	MergeSort(a, 0, n - 1);
	
	for (int i = 0; i < 6; ++i) {
			cout << a[i] << " ";
	}
	
	return 0;
}


// ** Counting Sort sử dụng 1 mảng tạm để lưu trữ tần xuất xuất hiện rồi duyệt mảng từ 0 -> max + 1 ( với max là phần tử lớn nhất trong mảng)
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, n) for (int i = 0; i < n; ++i)

int main(void) {

  vector<int> a = {123,12,1,2,3,1};
  int max  = *max_element(a.begin(), a.end());
  vector<int> T(max);
  FOR(i, max) T[i] = 0;

  FOR(i, a.size()) T[a[i]]++;

  int i = 0;
  FOR(j, max) {
    while (T[j] > 0) {
      a[i++] = j;
      T[j]--;
    }
  }
  for (auto x : a) {
    cout << x << " ";
  }
 
}

// ** Radix sort sắp theo hàng đơn vị hàng chục hàng trăm ... phụ thuộc vào số lượng chữ số
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

void RadixSort(vector<int>& a) {
	const int radix = 10; // xét hệ cơ số 10 chạy từ 0->9
	const int digits = (int)log10(*max_element(a.begin(), a.end())) + 2;
	// digits là số lượng chữ số
	int factor, k;
	queue<long> queues[radix];
	for (int i = 0, factor = 1; i < digits; factor *= radix, ++i) {
		for (int j = 0; j < a.size(); ++j) {
			queues[(a[j] / factor) % radix].push(a[j]); // đẩy vào trong từng tầng của queue
		}
		// (a[j] / factor) % radix  chia cho 1 rồi 10 rồi 100 . Mod để lấy chữ số cuối cùng
		int tmp = 0;
		for (k = 0; k < radix; ++k) {
			while (!queues[k].empty()) {
				a[tmp++] = queues[k].front(); queues[k].pop(); 
			}
		}
	}
	
}

int main(void) {

	vector<int> a{ 3,1,231,5,6 };
	RadixSort(a);
	for (auto x : a) {
		cout << x << " ";
	}
	
	return 0;
}

