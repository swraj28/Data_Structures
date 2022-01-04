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

	pair<int, int> dfs(TreeNode* root) {
		if (root == nullptr) {
			return { 0, 0};
		}

		auto l = dfs(root->left);
		auto r = dfs(root->right);

		int temp_ans = max(l.ff, l.ss) + max(r.ff, r.ss);

		ans = max(ans, temp_ans);

		return {max(l.ff, l.ss) + 1, max(r.ff, r.ss) + 1};
	}

	int diameterOfBinaryTree(TreeNode* root) {

		auto x = dfs(root);

		return ans;
	}
};