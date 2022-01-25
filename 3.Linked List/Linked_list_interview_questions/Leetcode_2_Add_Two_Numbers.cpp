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


// 1. Extra Space:-

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode* h1 = nullptr;
		ListNode* p1 = nullptr;

		int carry = 0;

		while (l1 != nullptr and l2 != nullptr) {
			int sum = (l1->val) + (l2->val) + carry;

			carry = (sum / 10);
			sum = (sum % 10);

			ListNode * n = new ListNode(sum);

			if (h1 == nullptr) {
				h1 = n;
				p1 = n;
			} else {
				p1->next = n;
				p1 = p1->next;
			}

			l1 = l1->next;
			l2 = l2->next;
		}

		while (l1 != nullptr) {
			int sum = (l1->val) + carry;

			carry = (sum / 10);

			sum = (sum % 10);

			ListNode * n = new ListNode(sum);

			if (h1 == nullptr) {
				h1 = n;
			} else {
				p1->next = n;
				p1 = p1->next;
			}

			l1 = l1->next;
		}

		while (l2 != nullptr) {
			int sum = (l2->val) + carry;

			carry = (sum / 10);

			sum = (sum % 10);

			ListNode * n = new ListNode(sum);

			if (h1 == nullptr) {
				h1 = n;
			} else {
				p1->next = n;
				p1 = p1->next;
			}

			l2 = l2->next;
		}

		while (carry > 0) {

			int x = carry % 10;
			carry /= 10;

			ListNode * n = new ListNode(x);

			if (h1 == nullptr) {
				h1 = n;
			} else {
				p1->next = n;
				p1 = p1->next;
			}
		}

		return h1;
	}
};

// Without Extra Space:-

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode* h1 = nullptr;
		ListNode* p1 = nullptr;

		int carry = 0;

		while (l1 != nullptr and l2 != nullptr) {
			int sum = (l1->val) + (l2->val) + carry;

			carry = (sum / 10);
			sum = (sum % 10);

			l1->val = sum;

			if (h1 == nullptr) {
				h1 = l1;
				p1 = l1;
			} else {
				p1 = l1;
			}

			l1 = l1->next;
			l2 = l2->next;
		}

		while (l1 != nullptr) {
			int sum = (l1->val) + carry;

			carry = (sum / 10);

			sum = (sum % 10);

			l1->val = sum;

			if (h1 == nullptr) {
				h1 = l1;
				p1 = l1;
			} else {
				p1 = l1;
			}

			l1 = l1->next;
		}

		while (l2 != nullptr) {
			int sum = (l2->val) + carry;

			carry = (sum / 10);
			sum = (sum % 10);

			l2->val = sum;

			if (h1 == nullptr) {
				h1 = l2;
				p1 = h1;
			} else {
				p1->next = l2;
				p1 = p1->next;
			}

			l2 = l2->next;
		}

		while (carry > 0) {

			int x = carry % 10;
			carry /= 10;

			ListNode * n = new ListNode(x);

			if (h1 == nullptr) {
				h1 = n;
				p1 = n;
			} else {
				p1->next = n;
				p1 = p1->next;
			}
		}

		return h1;
	}
};