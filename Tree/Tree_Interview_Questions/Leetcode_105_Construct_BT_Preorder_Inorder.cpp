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

	TreeNode* build_Tree(vector<int>& preorder, vector<int>& inorder, int s, int e) {

		if (s > e) {
			return NULL;
		}

		TreeNode* root = new TreeNode(preorder[pre_idx++]);

		if (s == e) {
			return root;
		}

		int idx;

		for (int i = s; i <= e; i++) {
			if (inorder[i] == (root->val)) {
				idx = i;
				break;
			}
		}

		root->left = build_Tree(preorder, inorder, s, idx - 1);
		root->right = build_Tree(preorder, inorder, idx + 1, e);

		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

		if (preorder.size() == 1) {
			TreeNode* root = new TreeNode(preorder[0]);

			return root;
		}

		return build_Tree(preorder, inorder, 0, inorder.size() - 1);
	}
};