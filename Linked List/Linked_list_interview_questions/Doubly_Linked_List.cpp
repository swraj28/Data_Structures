#include<iostream>
using namespace std;
#include<vector>


class DoublyLinkedList {
public : class Node {
	public:
		int data = 0;
		Node* prev = nullptr;
		Node* next = nullptr;

		Node(int data) {
			this->data = data;
		}

	};

	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;

	string toString() {
		string sb;
		Node* curr = this->head;
		sb += "[";
		while (curr != nullptr) {
			sb += (to_string)(curr->data);
			if (curr->next != nullptr)
				sb += ", ";
			curr = curr->next;
		}
		sb += "]";

		return sb;
	}

	// Exceptions========================================

private: bool ListIsEmptyException() {
		if (this->size == 0) {
			cout << "ListIsEmpty: ";
			return true;
		}
		return false;
	}
private: bool indexIsInvalidException(int index, int leftrange, int rightrange) {
		if (index < leftrange || index > rightrange ) {
			cout << "IndexIsInValid: ";
			return true;
		}
		return false;
	}

	// BasicFunctions======================================

public: int Size() {

		return size;
	}

public: bool isEmpty() {

		return size == 0;
	}
	// getFunctions======================================
public: int getFirst() {
		if (ListIsEmptyException()) {
			return -1;
		}
		return head->data;

	}

public: int getLast() {

		if (ListIsEmptyException()) {
			return -1;
		}
		return tail->data;
	}

public : Node* getNodeAt(int index) {
		Node *curr = this->head;
		while (index-- > 0) {
			curr = curr->next;
		}
		return curr;

	}
public : int getAt(int index) {
		if (ListIsEmptyException())return -1;
		else if (indexIsInvalidException(index, 0, this->size - 1)) {
			return -1;
		}
		Node *node = getNodeAt(index);
		return node->data;
	}
	// AddFunctions======================================

public: void addFirstNode(Node* node) {
		if (this->size == 0)
			this->head = this->tail = node;
		else {
			node->next = this->head;
			this->head->prev = node;
			this->head = node;
		}
		this->size++;
	}

public: void addFirst(int val) {
		Node* node = new Node(val);
		addFirstNode(node);
	}

public: void addLastNode(Node* node) {
		if (this->size == 0)
			this->head = this->tail = node;
		else {
			this->tail->next = node;
			node->prev = this->tail;
			this->tail = node;
		}
		this->size++;
	}

public: void addLast(int val) {
		Node* node = new Node(val);
		addLastNode(node);
	}

public: void addNodeAt(int index, Node *node) {
		if (index == 0)addFirstNode(node);
		else if (index == this->size)addLastNode(node);
		else {
			Node *frwrd = getNodeAt(index);
			Node *prev = frwrd->prev;

			prev->next = node;
			node->prev = prev;


			node->next = frwrd;
			frwrd->prev = node;

			this->size++;
		}
	}
public: void addAt(int index, int data) {
		if (indexIsInvalidException(index, 0, this->size)) {
			cout << -1 << endl;
		} else {
			Node *node = new Node(data);
			addNodeAt(index, node);
		}

	}
	// RemoveFunctions======================================

public: Node *removeFirstNode() {
		Node* node = this->head;
		if (this->size == 1)
			this->head = this->tail = nullptr;
		else {
			Node* nextNode = this->head->next;
			nextNode->prev = nullptr;
			node->next = nullptr;

			this->head = nextNode;
		}

		this->size--;
		return node;
	}

public: int removeFirst() {
		if (ListIsEmptyException())
			return -1;
		Node* node = removeFirstNode();
		return node->data;
	}

public: Node* removeLastNode() {
		Node* node = this->tail;
		if (this->size == 1)
			this->head = this->tail = nullptr;
		else {
			Node* prevNode = this->tail->prev;
			prevNode->next = nullptr;
			node->prev = nullptr;

			this->tail = prevNode;
		}

		this->size--;
		return node;
	}

public: int removeLast() {
		if (ListIsEmptyException())
			return -1;
		Node* node = removeLastNode();
		return node->data;
	}

public: int removeNodeAt(int index) {
		if (index == 0) {
			return removeFirst();
		} else if (index == (this->size - 1)) {
			return removeLast();
		} else {
			Node *frwrd = getNodeAt(index);
			Node *prev = frwrd->prev;

			prev->next = prev->next->next;

			if (frwrd->next) {
				frwrd->next->prev = prev;
			}

			frwrd->next = nullptr;
			frwrd->prev = nullptr;

			this->size--;

			return frwrd->data;
		}
	}

public: int removeAt(int index) {

		//write your code here
		if (ListIsEmptyException()) {
			return -1;
		} else if (indexIsInvalidException(index, 0, this->size - 1)) {
			return -1;
		} else {
			return removeNodeAt(index);
		}
	}
};


int main() {
	DoublyLinkedList *dll = new DoublyLinkedList();

	string str;
	cin >> str;

	while (str != "stop") {
		int data, index;
		if (str == ("addFirst")) {
			cin >> data;
			dll->addFirst(data);
		}
		else if (str == ("addLast")) {
			cin >> data;
			dll->addLast((data));
		}
		else if (str == ("removeFirst"))
			cout << (dll->removeFirst()) << endl;
		else if (str == ("removeLast"))
			cout << (dll->removeLast()) << endl;
		else if (str == ("getFirst"))
			cout << (dll->getFirst()) << endl;
		else if (str == ("getLast"))
			cout << (dll->getLast()) << endl;
		else if (str == ("size"))
			cout << (dll->Size()) << endl;
		else if (str == ("isEmpty")) {
			if ((dll->isEmpty())) {
				cout << "true" << "\n";
			} else cout << "false" << endl;
		}

		else if (str == ("getAt")) {
			cin >> data;
			cout << dll->getAt(data) << endl ;
		}
		else if (str == ("addAt")) {
			cin >> index; cin >> data;
			dll->addAt(index, data);
		}
		else if (str == ("removeAt")) {
			cin >> data;
			dll->removeAt(data);
		}

		cin >> str;
	}

	cout << dll->toString();

	return 0;
}