#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	Node* next;
	Node* prev;
	int data;
	Node() = default;
	Node (int x) {
		next = nullptr;
		data = x;
		prev = nullptr;
	}
};


class DoubleList {

	Node* head;

public:

	DoubleList() {
		head = nullptr;
	}
	void addHead(int x) {
		Node* p = new Node(x);
		if (head == nullptr) {
			head = p;
			return;
		}
		else {
			p->next = head;
			head->prev = p;
			head = p;
		}
	}
	void addTail(int x) {
		Node* temp = new Node(x);
		if (head == nullptr) {
		
			head = temp;
			
		} else {

			Node *p = head;
			while (p->next) {
				p = p->next;
			}
			p->next = temp;
			temp->prev = p;			
		}
	}

	
	
	void Print() const {
		Node* p = head;
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
	}
	friend istream& operator >>(istream& fin, DoubleList& l) {
		while (fin.good()) {
			int x;
			fin >> x;
			if (x == 0) break;
			l.addTail(x);
		}
		return fin;
	}
};


/*
 *  TẠO RA MÔ HÌNH CHÈN VÀ XÓA NODE Ở DOUBLE LINKLIST
 *
 *   _____________    _________________
 *  |PREV|DATA|NEXT|    |PREV|DATA|NEXT|
 *
 *	có 2 trường hợp xảy ra đó là có Empty hoặc là Atleast 1 phần tử 
 *	TH1: gán head = p   với điều kiện tiên quyết p->prev = nullptr | p->next = nullptr
 *	TH2:
 *	 2 khả năng xảy ra : Chèn Trước và Chèn Sau
 *	    TH1:  p->next = head
 *			  head->prev = p
 *			  head = p
 *	    TH2:  while loops chạy cho đến cuối node
 *			  ends->next = p
 *			  p->prev = ends
 *
 *
 *
 *						J                   K
 *				|PREV|DATA|NEXT|    |PREV|DATA|NEXT|
 *				       |						 |	
 *				       |						 |
 *				       |____|PREV|DATA|NEXT|_____|
 *
 *
 *	Trong Trường Hợp Insert thì chúng ta làm như sau:
 *	gọi p là node cần insert Khi đó:
 *
 *							p->next = J->next
 *							p->prev = J
 *							J->next = p
 *							p->next->prev = p
 *						Another way
 *						   ptr->data = item;  
						   ptr->next = temp->next;  
						   ptr -> prev = temp;  
						   temp->next = ptr;  
						   temp->next->prev=ptr;  
 *							
 *			Xóa ở đầu
 *			chỉ cần dịch thằng head = qua vị trí kế tiếp delete node đầu
 *			Xóa cuối
 *			while loops đến vị trí kế cuối
 *			kếcuối->next = nullptr delete node cuối
 */


int main(void) {

	fstream fin("C:/Users/Administrator/source/repos/StackAndQueue/StackAndQueue/input.txt", ios_base::in);
	if (fin.fail()) {
		cout << "Error occured when you attemping open the file\n";
		return 0;
	}
	
	DoubleList dl;
	fin >> dl;
	dl.Print();
	
	
	return 0;
}
