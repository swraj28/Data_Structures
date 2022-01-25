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

	int ans = 0;

	int dfs(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}

		int l = dfs(root->left);
		int r = dfs(root->right);

		if ((root->left) and (root->val == (root->left->val))) {
			l++;
		} else {
			l = 0;
		}

		if ((root->right) and (root->val == (root->right->val))) {
			r++;
		} else {
			r = 0;
		}

		int temp_ans = (l + r);

		ans = max(ans, temp_ans);

		return max(l, r);
	}

	int longestUnivaluePath(TreeNode* root) {

		auto x = dfs(root);

		return ans;
	}
};