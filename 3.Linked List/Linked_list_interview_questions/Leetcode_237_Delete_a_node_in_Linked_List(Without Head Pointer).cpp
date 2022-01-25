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
	void deleteNode(ListNode* node) {

		// We are not provided the head of the linked list. We are just provided the node that is to be deleted.

		ListNode* temp = node->next;

		// node->val = temp->val;
		// node->next=temp->next;

		(*node) = (*temp); // Derefrencing both node and temp and making node equals to temp

		delete temp;
	}
};