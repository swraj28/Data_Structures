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

// 1. Difference Methode:-

class Solution {
public:
	int lengthOfLL(ListNode *node) {
		if (node == nullptr) {
			return 0;
		}

		int len = 0;
		while (node != nullptr) {
			node = node->next;
			len++;
		}

		return len;
	}

	ListNode *IntersectionNodeInTwoLL(ListNode *headA, ListNode *headB) {

		if (headA == nullptr || headB == nullptr) {
			return nullptr;
		}

		int l1 = lengthOfLL(headA);
		int l2 = lengthOfLL(headB);

		ListNode *biggerList = l1 > l2 ? headA : headB;
		ListNode *smallerList = l1 > l2 ? headB : headA;

		int diff = max(l1, l2) - min(l1, l2);

		while (diff-- > 0) {
			biggerList = biggerList->next;
		}

		while (biggerList != smallerList) {
			biggerList = biggerList->next;
			smallerList = smallerList->next;
		}

		return biggerList;
	}

	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

		return IntersectionNodeInTwoLL(headA, headB);
	}
};

// 2. Using Floyd Cycle Detection Algorithm:-

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


	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

		if (headA == nullptr or headB == nullptr) {
			return nullptr;
		}

		ListNode* temp = headB;

		while ((temp->next) != nullptr) {
			temp = temp->next;
		}

		// We will create the cycle by connecting the tail node by headB.

		temp->next = headB;  // Cycle Is created

		// Now we can use the Floyd cycle detection Algorithm to find the starting point of the loop. (Starting Point will be the intersection Point).

		// Using Leetcode 142 as reference:-

		ListNode* ans = detectCycle(headA);

		temp->next = nullptr; // Earlier we have modified the list.Therefore we are backtracking the changes that we have done in original list.

		return ans;
	}
};