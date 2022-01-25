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


//Definition for a binary tree Node.

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

	vector<int>res;

	// 1. Recursion:-

	// T.c:- O(nodes) and S.c:- Space Occupied while building recursion Stack--> In worst case O(node)--> skew Tree(Left Skew)
	void preOrder_rec(TreeNode* root) {
		if (root == nullptr) {
			return;
		}

		res.pb(root->val);
		preOrder_rec(root->left);
		preOrder_rec(root->right);
	}

	// 2. Iterative Using an Explicit Stack:-

	/*
	   T.c:- O(nodes)
	   S.c:- O(nodes)--> If we consider a left skew tree
	*/

	void preOrder_itr(TreeNode* root) {
		if (root == nullptr) {
			return;
		}

		stack<TreeNode*> s;
		s.push(root);

		while (!s.empty()) {
			TreeNode* curr = s.top();
			s.pop();

			res.pb(curr->val);

			// First Put the right child in the stack then push the left child in the stack.

			if (curr->right) {
				s.push(curr->right);
			}

			if (curr->left) {
				s.push(curr->left);
			}
		}
	}

	// 3. Morris Traversal For Preorder Traversal:-

	/*
	    T.c:- O(nodes)
	    S.c:- O(1)

	*/

	void preOrder_morris(TreeNode* root) {
		if (root == nullptr) {
			return;
		}

		TreeNode* curr = root;

		while (curr != nullptr) {

			if (curr->left == nullptr) {
				res.pb(curr->val);
				curr = curr->right;
			} else {

				TreeNode* pred = curr->left;

				while ((pred->right != nullptr) and (pred->right != curr)) {
					pred = pred->right;
				}

				if (pred->right == nullptr) {
					pred->right = curr;
					res.pb(curr->val);
					curr = curr->left;
				} else {
					pred->right = nullptr;
					curr = curr->right;
				}
			}
		}
	}

	vector<int> preorderTraversal(TreeNode* root) {

		preOrder_morris(root);

		return res;
	}
};