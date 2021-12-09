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

	// Tail Call Optimized Recursive Function:-
	// TCO applys to a special case of recursion. The gist of it is, if the last thing you do in a function is call itself (e.g. it is calling itself from the "tail" position),
	// this can be optimized by the compiler to act like iteration instead of standard recursion

	void recur(ListNode* head, ListNode* &prev) {
		if (head == NULL) {
			return;
		}

		ListNode* cur = head->next;
		head->next = prev;
		prev = head;
		head = cur;

		recur(head, prev);
	}

	ListNode* reverseList(ListNode* head) {

		if (head == NULL or head->next == NULL) {
			return head;
		}

		// Without the tail call optimized recursive function

		// The concept is that we will ask recursion to reverse the entire linked list except the first node and recursion will also return us the new haed

		ListNode* new_head = reverseList(head->next);

		ListNode* cur = head;

		cur->next->next = cur;
		cur->next = NULL;

		return new_head;
	}

	//Iterative.

	ListNode* reverseList_iterative(ListNode* head) {

		if (head == NULL or head->next == NULL) {
			return head;
		}

		ListNode* prev = NULL;

		while (head != NULL) {
			ListNode* temp = head->next;
			head->next = prev;
			prev = head;
			head = temp;
		}

		return prev;
	}
};