/*
1. Given a singly linklist, Segregate Node of LinkedList over lastindex and return pivot node of linkedlist.
2. pivot is always be last index of linkedlist.
3. After segregation pivot Element should have to be present at correct position as in sorted linkedlist.
Input Format
1->5->2->9->5->14->11->1->10->10->1->3->null
Output Format
3->5->9->5->14->11->10->10->null
*/

// nodes smaller than or equal to last index remains in the left part and nodes larger than last index element remains in the
// right part.

#include <iostream>
using namespace std;

class ListNode
{
public:
	int val = 0;
	ListNode *next = nullptr;

	ListNode(int val)
	{
		this->val = val;
	}
};

ListNode *segregateOnLastIndex(ListNode *head) {

	if (head == nullptr or head->next == nullptr) {
		return head;
	}

	ListNode* curr = head;

	int Val = -1;

	while (curr->next != nullptr) {
		curr = curr->next;
	}

	Val = curr->val;

	ListNode* smaller = new ListNode(-1);
	ListNode* p_s = smaller;

	ListNode* gre_equal = new ListNode(Val);
	ListNode * p_g = gre_equal;

	curr = head;

	while ((curr->next) != nullptr) {
		if ((curr->val) <= Val) {
			p_s->next = curr;
			p_s = p_s->next;
		} else {
			p_g->next = curr;
			p_g = p_g->next;
		}

		curr = curr->next;
	}

	p_g->next = nullptr;

	return gre_equal;
}

void printList(ListNode *node)
{
	ListNode *curr = node;
	while (curr != nullptr)
	{
		cout << curr->val << " ";
		curr = curr->next;
	}
	cout << endl;
}

ListNode *createList(int n)
{
	ListNode *dummy = new ListNode(-1);
	ListNode *prev = dummy;
	while (n-- > 0)
	{
		int val;
		cin >> val;
		prev->next = new ListNode(val);
		prev = prev->next;
	}
	return dummy->next;
}

int main()
{
	int n;
	cin >> n;
	ListNode *h1 = createList(n);
	h1 = segregateOnLastIndex(h1);
	printList(h1);

	return 0;
}