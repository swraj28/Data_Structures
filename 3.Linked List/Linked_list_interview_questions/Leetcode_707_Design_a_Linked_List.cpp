#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()
#define ms(arr, v) memset(arr, v, sizeof(arr))

class node {
public:
	int data;
	node* next;

	node(int newData) {
		this->data = newData;
		this->next = NULL;
	}
};

class MyLinkedList {
public:
	/** Initialize your data structure here. */
	node *head;
	int size;

	MyLinkedList() {
		this->head = NULL;
		this->size = 0;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */

	// Zero Based Indexing

	int get(int index) {
		if (index >= this->size) {
			return -1;
		}

		node*temp = head;
		int pos = 0;
		while (pos != index) {
			temp = temp->next;
			pos++;
		}

		return temp->data;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		node* n = new node(val);
		if (head == NULL) {
			head = n;
			size++;
		} else {
			n->next = head;
			head = n;
			size++;
		}
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		if (head == NULL) {
			addAtHead(val);
			return;
		}

		node*temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}

		node* n = new node(val);

		temp->next = n;
		size++;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index == size) {
			addAtTail(val);
			return;
		}

		if (index == 0) {
			addAtHead(val);
			return ;
		}

		if (index > size) {
			return;
		}

		int pos = 0;
		node*temp = head;

		while ((index - pos) > 1) {
			temp = temp->next;
			pos++;
		}

		node* n = new node(val);
		n->next = temp->next;
		temp->next = n;
		size++;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (head == NULL or index >= size) {
			return;
		}

		if (index == 0) {
			head = head->next;
			size--;
			return;
		}

		if (index == size - 1) {
			node* temp = head;
			while (temp->next->next != NULL) {
				temp = temp->next;
			}
			temp->next = NULL;
			size--;
			return;
		}

		int pos = 0;
		node*temp = head;

		while ((index - pos) != 1) {
			temp = temp->next;
			pos++;
		}

		node* to_be_deleted = temp->next;

		temp->next = temp->next->next;
		size--;

		delete to_be_deleted;
	}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */