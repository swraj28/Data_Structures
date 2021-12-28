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

	int dfs(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}

		int l = 0, r = 0;

		// If i decided to place the camera on the root node

		if (root->left) {
			l += dfs(root->left->left);
			l += dfs(root->left->right);
		}

		if (root->right) {
			r += dfs(root->right->left);
			r += dfs(root->right->right);
		}

		int sm = 1 + l + r;

		return sm;
	}

	int minCameraCover(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}

		if (root->left == nullptr and root->right == nullptr) {
			return 1;
		}

		int val1 = dfs(root);
		int val2 = dfs(root->left) + dfs(root->right);

		return min({val2, val1});
	}
};