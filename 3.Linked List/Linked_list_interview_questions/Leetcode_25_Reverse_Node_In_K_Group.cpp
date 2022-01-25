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
	ListNode* reverseKGroup(ListNode* head, int k) {

		if (head == nullptr or head->next == nullptr or k == 1) {
			return head;
		}

		ListNode* p = nullptr;// Last pointer of reversed list

		ListNode* temp1 = head;

		int cnt = 0;

		ListNode* prev = nullptr, *curr = nullptr, *end = nullptr;

		while (temp1 != nullptr) {

			if (cnt == 0) {
				end = temp1;
			}

			cnt += 1;

			if (cnt == k) {

				cnt = 0;

				ListNode*temp2 = temp1;

				temp1 = temp1->next;

				temp2->next = nullptr;

				// Reverse of linked list
				prev = nullptr;
				curr = end;
				while (curr != nullptr) {
					ListNode* temp = curr->next;
					curr->next = prev;
					prev = curr;
					curr = temp;
				}

				if (p == nullptr) { // If prev of the order list is null
					head = prev;
					p = end;
					end = nullptr;
				} else {
					p->next = prev;
					p = end;
					end = nullptr;
				}
			} else {
				temp1 = temp1->next;
			}
		}

		if (p == nullptr) {
			return head;
		}

		if (end == nullptr) {
			return head;
		}

		p->next = end;

		return head;
	}
};