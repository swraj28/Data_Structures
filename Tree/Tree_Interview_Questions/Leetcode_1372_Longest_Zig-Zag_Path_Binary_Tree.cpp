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

	pair<int, pair<int, int>> dfs(TreeNode* root) {
		if (root == nullptr) {
			return { -1, { -1, -1}};
		}

		auto l = dfs(root->left);
		auto r = dfs(root->right);

		int temp_ans = max({(l.ss.ss) + 1, (r.ss.ff) + 1});

		temp_ans = max({l.ff, r.ff, temp_ans});

		return {temp_ans, {(l.ss.ss) + 1, (r.ss.ff) + 1}};
	}



	int longestZigZag(TreeNode* root) {

		return dfs(root).ff;
	}
};