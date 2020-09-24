#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	Node* next;
	int data;
	Node() = default;
	Node (int x) {
		next = nullptr;
		data = x;
	}
};


class List {

	Node* head;
	Node* tail;

public:

	List();
	void addHead(int x);
	void addTail(int x);
	void Print() const;
	friend istream& operator >>(istream& fin, List& l);
	friend std::ostream& operator<<(std::ostream& os, const List& obj);
	void RemoveAllX(int x);
	void RemoveDuplicate();
	void BubbleSort();
	List Merge(List& l, List& k);

	void merge(int l, int m, int h) {

		int n1 = m - l + 1;
		int n2 = h - m;

		vector<int> b(n1), c(n2);

		Node* p = head;
		
		for (int i = 0; i < l - 1; ++i) {
			p = p->next;
		}
		
		for (int i = 0; i < n1 && p != nullptr; ++i, p = p->next) {
			b[i] = p->data; 
		}

		for (int j = 0; j < n2 && p != nullptr; ++j, p = p->next) {
			c[j] = p->data;
		}

		int i = 0, j = 0, k = l;

		Node* temp = head;

		for (int i = 0; i < l - 1; ++i) {
			temp = temp->next;
		}
		
		while (i < n1 && j < n2) {
			if (b[i] < c[j]) {
				temp->data = b[i];
				++i; temp = temp->next;
			}
			else {
				temp->data = c[j];
				++j; temp = temp->next;
			}
		}
		while (i < n1 && temp != nullptr) {
			temp->data = b[i];
			++i; temp = temp->next;
		}
		while (j < n2 && temp != nullptr) {
			temp->data = c[j];
			++j; temp = temp->next;
		}
		
	}

	void MergeSort(int l, int h) {
		if (h - l > 0) {
			int mid = (l + h) / 2;
			MergeSort(0, mid);
			MergeSort(mid + 1, h);
			merge(l, mid, h);
		}
	}

};


void List::RemoveDuplicate() {

	if (head == nullptr) return;

	Node* cur = head;

	while (cur) {

		Node* cur1 = cur;
		while (cur1->next) {
			 if (cur1->next->data == cur->data) {
				 Node* p = cur1->next;
				 cur1->next = p->next;
				 delete p;
			 } else {
				 cur1 = cur1->next;
			 }
		}
		cur = cur->next;
	}
	
}

void List::BubbleSort() {
	for (Node* i = head; i != nullptr; i = i->next) {

		for (Node* j = i->next; j != nullptr; j = j->next) {
			if (i->next == nullptr) break;
			if (i->data < j->data) {
				swap(i->data, j->data);
			}
		}
	}
}

List List::Merge(List& l, List& k) {
	List list;
	Node* curl = l.head;
	Node* curp = k.head;

	while (curl && curp) {
		if (curl->data > curp->data) {
			list.addTail(curp->data);
			curp = curp->next;
		}
		else {
			list.addTail(curl->data);
			curl = curl->next;
		}
	}
	while (curl) {
		list.addTail(curl->data);
		curl = curl->next;
	}
	while (curp) {
		list.addTail(curp->data);
		curp = curp->next;
	}
	return list;
}


std::ostream& operator<<(std::ostream& os, const List& obj) {

	Node* p = obj.head;

	while (p) {
		os << p->data << " ";
		p = p->next;
	}
	return os;
}


istream& operator >>(istream& fin, List& l) {
	while (fin.good()) {
		int x;
		fin >> x;
		if (x == 0) break;
		l.addTail(x);
	}
	return fin;
}

List::List() {
	tail = head = nullptr;
}

void List::addHead(int x) {
	Node* p = new Node(x);
	if (tail == nullptr) {
		tail = head = p;
	}
	else {
		p->next = head;
		head = p;
	}
}

void List::addTail(int x) {

	Node* p = new Node(x);

	if (head == nullptr) {
		head = tail = p;
	}
	else {
		Node* cur = head;
		while (cur->next) cur = cur->next;
		cur->next = p;
	}
}

void List::Print() const {

	Node* p = head;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}

}

void List::RemoveAllX(int x) {
	if (head == nullptr) return;

	while (head != nullptr && head->data == x) {
		Node* temp = head;
		head = temp->next;
		delete temp;
	}

	
	Node* cur = head;
	if (cur == nullptr) return;
	while (cur->next) {

		if (cur->next->data == x) {
			Node* p = cur->next;
			cur->next = cur->next->next;
			delete p;
		} else {
			cur = cur->next;
		}
	}

}



int main(void) {

	fstream fin("C:/Users/Administrator/source/repos/StackAndQueue/StackAndQueue/input.txt", ios_base::in);
	if (fin.fail()) {
		cout << "Error occured when you attemping open the file\n";
		return 0;
	}
	List l;
	fin >> l;

	l.MergeSort(0, 5);

	cout << l << endl;
	
	return 0;
}
