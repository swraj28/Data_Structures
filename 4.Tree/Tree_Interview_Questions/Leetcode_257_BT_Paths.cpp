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
	vector<string> ans;

	void dfs(TreeNode* root, string s) {

		if (root == NULL) {
			return;
		}

		if (root->left == NULL and root->right == NULL) { // we are at the leaf node
			s += to_string(root->val);
			ans.pb(s);

			return;
		}

		s += to_string(root->val);
		s += "->";

		dfs(root->left, s);
		dfs(root->right, s);
	}

	vector<string> binaryTreePaths(TreeNode* root) {

		if (root == NULL) {
			return ans;
		}

		string s = "";

		dfs(root, s);

		return ans;
	}
};