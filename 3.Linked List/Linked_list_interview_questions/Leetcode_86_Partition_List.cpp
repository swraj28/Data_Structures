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
	ListNode* partition(ListNode* head, int x) {

		ListNode* l1 = nullptr; //value less than x
		ListNode* l2 = nullptr; // value greater than equal to x;

		ListNode* p1 = nullptr, *p2 = nullptr;

		ListNode* cur = head, *prev = nullptr;

		while (cur != nullptr) {
			prev = cur;
			cur = cur->next;

			if (prev->val < x) {
				if (l1 == nullptr) {
					l1 = prev;
					p1 = prev;
				} else {
					p1->next = prev;
					p1 = prev;
				}
			} else {
				if (l2 == nullptr) {
					l2 = prev;
					p2 = prev;
				} else {
					p2->next = prev;
					p2 = prev;
				}
			}

			prev->next = nullptr;
		}

		if (l1 == nullptr) {
			return l2;
		}

		p1->next = l2;

		return l1;
	}
};