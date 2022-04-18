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
	ListNode* reverseEvenLengthGroups(ListNode* head) {

		if (head->next == nullptr) {
			return head;
		}

		ListNode* p = head, *c = head->next;

		int group = 2;

		ListNode* cur = head->next, *cur_p = head;

		while (cur != nullptr) {

			int x = 0;

			while (cur != nullptr && x < group) {
				x++;
				cur_p = cur;
				cur = cur->next;
			}

			if (x % 2 == 0) {

				p->next == nullptr;
				cur_p->next = nullptr;

				ListNode* h1 = c, *p1 = nullptr;

				while (h1 != nullptr) {
					ListNode* temp = h1->next;
					h1->next = p1;
					p1 = h1;
					h1 = temp;
				}

				p->next = p1;
				c->next = cur;

				p = c;
				c = cur;
			} else {
				p = cur_p;
				c = cur;
			}

			group++;
		}

		return head;
	}
};