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
	ListNode* swapPairs(ListNode* head) {

		if (head == nullptr or head->next == nullptr) {
			return head;
		}

		ListNode* h1 = nullptr;
		ListNode* p1 = nullptr;

		ListNode* cur = head->next;
		ListNode* prev = head;

		ListNode* temp = cur->next;

		cur->next = nullptr;
		prev->next = nullptr;

		h1 = cur;
		h1->next = prev;
		p1 = prev;
		p1->next = nullptr;

		while (temp and temp->next) {
			cur = temp->next;
			prev = temp;

			temp = cur->next;

			cur->next = nullptr;
			prev->next = nullptr;

			p1->next = cur;
			cur->next = prev;

			p1 = p1->next->next;
			p1->next = nullptr;
		}

		if (temp) {
			p1->next = temp;
		}

		return h1;
	}
};