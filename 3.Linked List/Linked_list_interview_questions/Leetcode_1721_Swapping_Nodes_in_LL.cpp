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
	ListNode* swapNodes(ListNode* head, int k) {

		if (head->next == nullptr) {
			return head;
		}

		ListNode* slow = head, *fast = head;
		k -= 1;

		while (k > 0) {
			fast = fast->next;
			k -= 1;
		}

		ListNode* kthnode_beginning = fast;

		while (fast->next) {
			slow = slow->next;
			fast = fast->next;
		}

		ListNode* kthnode_end = slow;

		swap(kthnode_beginning->val, kthnode_end->val);

		return head;
	}
};