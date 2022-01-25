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
	unordered_map<TreeNode*, int> dp;

	int dfs(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}

		if (dp.find(root) != dp.end()) {
			return dp[root];
		}

		int l = 0, r = 0;

		// If i plan to rob the root node after that i cannot rob any value present in the left and right of the root node in the next level.

		// Inclusion Exclusion Technique.

		if (root->left) {
			l += dfs(root->left->left);
			l += dfs(root->left->right);
		}

		if (root->right) {
			r += dfs(root->right->left);
			r += dfs(root->right->right);
		}

		int sm = (root->val) + l + r;

		return dp[root] = max({sm, (dfs(root->left) + dfs(root->right))});
	}

	int rob(TreeNode* root) {

		return dfs(root);
	}
};