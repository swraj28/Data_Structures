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

	vector<vector<int>> ans;

	void dfs(TreeNode* root, int targetSum, vector<int> &v) {
		if (root == nullptr) {
			return;
		}

		if ((root->left == nullptr) and (root->right == nullptr)) {
			if (targetSum == (root->val)) {
				v.pb(root->val);

				ans.pb(v);

				v.pop_back();

				return;
			}
		}

		v.pb(root->val);

		dfs(root->left, (targetSum - root->val), v);
		dfs(root->right, (targetSum - root->val), v);

		v.pop_back();
	}

	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

		vector<int> v;

		dfs(root, targetSum, v);

		return ans;
	}
};