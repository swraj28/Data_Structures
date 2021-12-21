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
	ListNode *detectCycle(ListNode *head) {

		if (head == NULL or head->next == NULL)return NULL;

		ListNode*slow = head;
		ListNode*fast = head;
		bool flag = false;

		while (fast->next != NULL and fast->next->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast) {
				flag = true;
				break;
			}
		}

		if (flag == false) {
			return NULL;
		}
		slow = head;
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};