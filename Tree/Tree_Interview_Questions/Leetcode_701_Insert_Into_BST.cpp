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

// 1. Recursive Implementation:-

class Solution {
public:

	TreeNode* build_tree(TreeNode* root, int val) {

		if (root == nullptr) {
			root = new TreeNode(val);
			return root;
		}

		if ((root->val) > val) {

			root->left = build_tree(root->left, val);
		} else {
			root->right = build_tree(root->right, val);
		}

		return root;
	}

	TreeNode* insertIntoBST(TreeNode* root, int val) {

		return build_tree(root, val);
	}
};

// 2. Iterative Implementation:-

