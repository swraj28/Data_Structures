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
	vector<ListNode*> Partition(ListNode* head, int pivotIdx) {

		vector<ListNode*> v;

		int idx = 0;

		ListNode* curr = head;

		int Val = -1;

		while (curr != nullptr) {
			if (idx == pivotIdx) {
				Val = curr->val;
				break;
			}
			curr = curr->next;

			idx++;
		}

		ListNode* smaller = new ListNode(-1);
		ListNode* p_s = smaller;

		ListNode* gre_equal = new ListNode(Val);
		ListNode * p_g = gre_equal;

		curr = head;

		idx = 0;

		while ((curr) != nullptr) {
			if (idx == pivotIdx) {
				curr = curr->next;
				idx++;
				continue;
			}

			if ((curr->val) <= Val) {
				p_s->next = curr;
				p_s = p_s->next;
			} else {
				p_g->next = curr;
				p_g = p_g->next;
			}

			curr = curr->next;
			idx++;
		}

		p_g->next = nullptr;
		p_s->next = nullptr;

		ListNode* pivot = gre_equal;  // The elements left to the pivot are smaller and the elements right to the pivot are larger.

		gre_equal = gre_equal->next;

		pivot->next = nullptr;

		v.pb(smaller->next);
		v.pb(pivot);
		v.pb(gre_equal);

		return v;
	}

	int Length(ListNode* head) {

		int len = 0;

		ListNode* curr = head;

		while (curr != nullptr) {
			len++;
			curr = curr->next;
		}

		return len;
	}

	vector<ListNode*> merge_sorted_list(vector<ListNode*> left_sorted, ListNode* pivot, vector<ListNode*> right_sorted ) {

		ListNode* head = nullptr, *tail = nullptr;

		if (left_sorted[0] != nullptr and right_sorted[0] != nullptr) {
			left_sorted[1]->next = pivot;
			pivot->next = right_sorted[0];

			head = left_sorted[0];
			tail = right_sorted[1];
		} else if (left_sorted[0] == nullptr and right_sorted[0] != nullptr) {
			head = pivot;
			pivot->next = right_sorted[0];
			tail = right_sorted[1];
		} else if (left_sorted[0] != nullptr and right_sorted[0] == nullptr) {
			tail = pivot;
			left_sorted[1]->next = pivot;
			head = left_sorted[0];
		} else {
			head = pivot;
			tail = pivot;
		}

		return {head, tail};
	}

	vector<ListNode*> quick_Sort(ListNode *head) {  //{head,tail}

		if (head == nullptr or head->next == nullptr) {
			return {head, head};
		}

		int len = Length(head);

		int pivotIdx = (len / 2);

		vector<ListNode*> v = Partition(head, pivotIdx);

		vector<ListNode*> left_sorted = quick_Sort(v[0]);
		vector<ListNode*> right_sorted = quick_Sort(v[2]);

		return merge_sorted_list(left_sorted, v[1], right_sorted);
	}

	ListNode *quickSort(ListNode *head) {

		return quick_Sort(head)[0];
	}


	ListNode* sortList(ListNode* head) {

		return quickSort(head);
	}
};