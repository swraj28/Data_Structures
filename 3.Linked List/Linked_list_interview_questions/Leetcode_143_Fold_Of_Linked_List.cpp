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

/*
       The Key Idea here is to reverse the list from mid to end and start connecting.

       1->2->3->4->5->6->7->nullptr

       a.)1->2->3->4->null   5->6->7->null

       b.)1->5->2->6->3->7->4->null.
*/

class Solution {
public:
	void fold(ListNode *head) {

		//Uptill length 2 we do not need to do anything

		if (head == nullptr) {
			return;
		}

		if (head->next == nullptr) {
			return;
		}

		if (head->next->next == nullptr) {
			return;
		}

		ListNode* slow = head;
		ListNode*fast = head;

		while ((fast->next != nullptr) and (fast->next->next != nullptr)) {
			slow = slow->next;
			fast = fast->next->next;
		}

		//Reverse the second part of the Linked List.

		ListNode*prev = nullptr;

		ListNode* curr = slow->next;

		while (curr != NULL) {
			ListNode* temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}

		slow->next = NULL;

		ListNode*temp = head;

		while (prev != nullptr) {

			ListNode*temp1 = temp->next;

			temp->next = prev;
			ListNode* temp2 = prev->next;
			prev->next = temp1;
			temp = temp1;
			prev = temp2;
		}
	}
	void reorderList(ListNode* head) {

		fold(head);
	}
};