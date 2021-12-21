#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

class Solution {
public:
	//Function to remove duplicates from unsorted linked list.

	Node * removeDuplicates( Node *head) {

		unordered_set<int> s;

		Node* temp = head;
		Node*temp1 = head;

		while (temp != NULL) {
			int x = temp->data;

			if (s.find(x) == s.end()) {
				s.insert(x);
				temp1 = temp;
				temp = temp->next;
			} else {
				Node* temp2 = temp;
				temp = temp->next;
				temp1->next = temp;
				delete temp2;
			}
		}

		return head;
	}
};