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

	map<int, multiset<int>> m;

	void dfs(TreeNode* root, int angle) {
		if (root == nullptr) {
			return;
		}

		m[angle].insert(root->val);
		dfs(root -> left, (angle - 1));
		dfs(root->right, (angle + 1));
	}

	vector<vector<int>> verticalTraversal(TreeNode* root) {

		vector<vector<int> > ans;
		if (root == nullptr) {
			return ans;
		}

		dfs(root, 0);

		vector<int> x;

		for (auto v : m) {
			x.clear();
			for (auto ele : v.ss) {
				x.pb(ele);
			}

			ans.pb(x);
		}

		return ans;
	}
};