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

// Definition for singly-linked list.

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:

	// Recursive:- ((Merge Two sorted Linked List))

	ListNode* merge(ListNode* a, ListNode* b) {

		if (a == NULL) {
			return b;
		}

		if (b == NULL) {
			return a;
		}

		ListNode*c;

		if (a->val <= b->val) {
			c = a;
			c->next = merge(a->next, b);
		} else {
			c = b;
			c->next = merge(a, b->next);
		}

		return c;
	}

	// Iterative (Merge Two sorted Linked List)

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		if (l1 == NULL) {
			return l2;
		}

		if (l2 == NULL) {
			return l1;
		}

		ListNode*head = NULL;
		ListNode*prev = NULL;

		if ((l1->val) <= (l2->val)) {
			head = l1;
			prev = l1;
			l1 = l1->next;
		} else {
			head = l2;
			prev = l2;
			l2 = l2->next;
		}

		while ((l1 != NULL) and (l2 != NULL)) {

			if ((l1->val) <= (l2->val)) {
				ListNode*temp = l1;
				l1 = l1->next;
				prev->next = temp;
				prev = temp;
			} else {
				ListNode*temp = l2;
				l2 = l2->next;
				prev->next = temp;
				prev = temp;
			}
		}

		if (l1 != NULL) {
			prev->next = l1;
		}

		if (l2 != NULL) {
			prev->next = l2;
		}

		return head;
	}

	ListNode* merge_sort(vector<ListNode*>& lists, int si, int ei) {

		if (si > ei) {
			return NULL;
		}

		if (si == ei) {
			return lists[si];
		}

		int mid = (si + ei) / 2;

		ListNode* l1 = merge_sort(lists, si, mid);
		ListNode* l2 = merge_sort(lists, mid + 1, ei);

		return mergeTwoLists(l1, l2);
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0) {
			return NULL;
		}

		if (lists.size() == 1) {
			return lists[0];
		}

		return merge_sort(lists, 0, lists.size() - 1);
	}
};