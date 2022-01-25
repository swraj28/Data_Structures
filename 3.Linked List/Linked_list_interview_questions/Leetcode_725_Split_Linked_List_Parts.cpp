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
	vector<ListNode*> splitListToParts(ListNode* head, int k) {

		int len = 0;
		ListNode* cur = head;

		while (cur != nullptr) {
			len++;
			cur = cur->next;
		}

		vector<ListNode*> ans;

		if (len < k) {

			int idx = 0;
			cur = head;

			while (cur != nullptr) {
				ListNode* temp = cur;
				cur = cur->next;
				temp->next = nullptr;
				ans.pb(temp);
				idx++;
			}

			while (idx < k) {
				ans.pb(nullptr);
				idx++;
			}

			return ans;
		}

		// It is similar to the pegion Hole principle where we require to place the Linked List node in the holes.

		int mn = (len / k);

		int rem = (len - (mn * k));

		cur = head;
		ListNode* p1 = cur;

		for (int i = 0; i < rem; i++) {
			int Val = (mn);

			while (mn > 0) {
				cur = cur->next;
				mn -= 1;
			}

			ListNode* temp = cur;
			cur = cur->next;
			temp->next = nullptr;

			ans.pb(p1);

			p1 = cur;
		}

		while (cur != nullptr) {
			int Val = (mn - 1);
			while (Val > 0) {
				cur = cur->next;
				Val -= 1;
			}

			ListNode* temp = cur;
			cur = cur->next;
			temp->next = nullptr;

			ans.pb(p1);

			p1 = cur;
		}

		return ans;
	}
};