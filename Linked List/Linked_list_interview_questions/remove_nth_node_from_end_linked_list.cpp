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

// Delete the node in single pass.

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		ListNode* slow = head, *fast = head;

		while ((n > 0) and fast != NULL) {
			fast = fast->next;
			n--;
		}

		if (fast == NULL) { // We have to delete the head node itself
			ListNode* temp = head;
			head = head->next;
			delete temp;
			return head;
		}

		while (fast->next) {
			slow = slow->next;
			fast = fast->next;
		}

		ListNode* to_be_deleted = slow->next;
		slow->next = slow->next->next;

		delete to_be_deleted;

		return head;
	}
};