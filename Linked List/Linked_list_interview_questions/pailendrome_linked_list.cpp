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
	bool isPalindrome(ListNode* head) {

		// O(n)time and O(1)space

		if (head == NULL or head->next == NULL) {
			return true;
		}

		ListNode* slow = head;
		ListNode* fast = head;

		while ((fast->next) and (fast->next->next)) {
			slow = slow->next;
			fast = fast->next->next;
		}

		// Reversing the second part of the linked list

		ListNode* head1 = slow->next;
		ListNode* prev = NULL;

		while (head1 != NULL) {
			ListNode* curr = head1->next;
			head1->next = prev;
			prev = head1;
			head1 = curr;
		}

		slow->next = prev;  // combining the two halves of the linked list.

		head1 = slow->next;  //head1=prev

		while (head1 != NULL) {
			if ((head->val) != (head1->val)) {
				return false;
			}
			head1 = head1->next;
			head = head->next;
		}

		return true;
	}
};