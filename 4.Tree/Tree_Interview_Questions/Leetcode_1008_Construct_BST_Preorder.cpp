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

class Solution {
public:

	int pre_idx = 0;

	TreeNode* build_tree(vector<int> &preorder, int l, int r) {

		if (pre_idx >= preorder.size()) {
			return nullptr;
		}

		if ((preorder[pre_idx] >= l) and (preorder[pre_idx] <= r)) {

		} else {
			return nullptr;
		}

		TreeNode* root = new TreeNode(preorder[pre_idx++]);

		root->left = build_tree(preorder, l, (root->val));
		root->right = build_tree(preorder, (root->val), r);

		return root;
	}

	TreeNode* bstFromPreorder(vector<int>& preorder) {

		return build_tree(preorder, INT_MIN, INT_MAX);
	}
};