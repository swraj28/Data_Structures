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

	int post_idx;

	TreeNode* build_Tree(vector<int>& postorder, vector<int>& inorder, int s, int e) {

		if (s > e) {
			return NULL;
		}

		TreeNode* root = new TreeNode(postorder[post_idx--]);

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

		root->right = build_Tree(postorder, inorder, idx + 1, e);
		root->left = build_Tree(postorder, inorder, s, idx - 1);

		return root;
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

		if (postorder.size() == 1) {
			TreeNode* root = new TreeNode(postorder[0]);

			return root;
		}

		post_idx = inorder.size() - 1;

		return build_Tree(postorder, inorder, 0, inorder.size() - 1);
	}
};