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

/*
       The Key Idea of insertion sort is that the left part of the array or the linked list is maintained sorted while an element from the
       right part of the linked list is picked and placed at its correct position in the left part

       e.g:-
       		4->3->2->1->5->null

       	Step 1:-	4->null  3->2->1->5->null

       	Step 2:-	3->4->null  2->1->5->null

       	Step 3:-	2->3->4->null  1->5->null

       	Step 4:-	1->2->3->4->null   5->null

       	Step 5:-	1->2->3->4->5->null  {}
*/

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {

		if (head == nullptr or head->next == nullptr) {
			return head;
		}

		ListNode* ls = head;

		ListNode* curr = head->next;

		ls->next = nullptr;

		while (curr != nullptr) {

			ListNode* temp = curr;

			curr = curr->next;

			temp->next = nullptr;

			ListNode* h1 = ls;
			ListNode* p1 = nullptr;

			bool f = false;

			while (h1 != nullptr) {
				if ((h1->val) < (temp->val)) {
					p1 = h1;
					h1 = h1->next;
				} else {
					if (p1 == nullptr) {
						temp->next = h1;
						ls = temp;
					} else {
						p1->next = temp;
						temp->next = h1;
					}
					f = true;
					break;
				}
			}

			if (f == false) {
				p1->next = temp;
			}
		}

		return ls;
	}
};