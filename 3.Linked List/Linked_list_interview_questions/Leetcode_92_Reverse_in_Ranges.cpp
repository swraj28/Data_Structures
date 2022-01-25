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

// Do it in single pass and o(1) space.

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {

		if (head == nullptr or head->next == nullptr) {
			return head;
		}

		ListNode*p1 = nullptr, *p2 = nullptr;


		ListNode*temp = head;

		int cnt = 1;

		while (cnt < left) {
			p1 = temp;
			temp = temp->next;
			cnt += 1;
		}

		ListNode*curr = temp;

		if (p1) {
			p1->next = nullptr;
		}

		while (cnt < right) {
			temp = temp->next;
			cnt += 1;
		}

		p2 = temp->next;

		temp->next = nullptr;

		ListNode*prev = nullptr;

		ListNode* end = nullptr;

		while (curr != nullptr) {
			ListNode*temp1 = curr->next;
			if (prev == nullptr) {
				end = curr;
			}
			curr->next = prev;
			prev = curr;
			curr = temp1;
		}

		if (p1 == nullptr) {
			head = prev;
		} else {
			p1->next = prev;
		}

		if (p2 == nullptr) {
			end->next = nullptr;
		} else {
			end->next = p2;
		}

		return head;
	}
};