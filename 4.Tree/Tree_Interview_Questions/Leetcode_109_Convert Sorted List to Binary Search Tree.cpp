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

//Definition for a binary tree node.

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Definition for singly-linked list.

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// A single Pass Solutin :-

class Solution {
public:

	TreeNode* build_tree(ListNode*head, ListNode* tail) {

		if (head == tail) {
			return nullptr;
		}

		if (head->next == tail) {
			TreeNode* root = new TreeNode(head->val);

			return root;
		}

		ListNode* slow = head, *fast = head;

		while (fast->next != tail && fast->next->next != tail) {
			slow = slow->next;
			fast = fast->next->next;
		}

		TreeNode* root = new TreeNode(slow->val);

		root->left = build_tree(head, slow);
		root->right = build_tree(slow->next, tail);

		return root;
	}

	TreeNode* sortedListToBST(ListNode* head) {

		return build_tree(head, nullptr);
	}
};