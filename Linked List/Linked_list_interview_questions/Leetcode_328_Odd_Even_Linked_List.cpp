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
	ListNode* oddEvenList(ListNode* head) {

		if (head == nullptr or head->next == nullptr) {
			return head;
		}

		ListNode*h1 = nullptr;
		ListNode*p1 = nullptr;
		ListNode*h2 = nullptr;
		ListNode*p2 = nullptr;

		bool f = true;

		while (head != nullptr) {
			if (f) {
				if (h1 == nullptr) {
					h1 = head;
					p1 = h1;
				} else {
					p1->next = head;
					p1 = p1->next;
				}
				f = false;
			} else {
				if (h2 == nullptr) {
					h2 = head;
					p2 = h2;
				} else {
					p2->next = head;
					p2 = p2->next;
				}
			}

			head = head->next;
		}

		// If we have reached here it means the LL has min of length 2.

		p1->next = h2;
		p2->next = nullptr;  //very very imp.

		return h1;
	}
};