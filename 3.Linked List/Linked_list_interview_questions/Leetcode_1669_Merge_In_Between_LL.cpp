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
	ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

		ListNode* p = nullptr, *c = list1;

		int x = 0;

		ListNode* p_a = nullptr, *c_a = nullptr;

		while (x <= b) {
			if (x == a) {
				p_a = p;
				c_a = c;
			}

			x++;
			p = c;
			c = c->next;
		}

		ListNode* temp = list2;
		while (temp->next) {
			temp = temp->next;
		}

		p->next = nullptr;

		if (a == 0) {
			temp->next = c;
			return list2;
		}

		p_a->next = list2;
		temp->next = c;

		return list1;
	}
};