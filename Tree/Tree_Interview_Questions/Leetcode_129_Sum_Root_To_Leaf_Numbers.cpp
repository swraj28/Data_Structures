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

	void dfs(TreeNode* root, string &s) {
		if (root == nullptr) {
			return;
		}

		s += ((root->val) + '0');

		if ((root->left == nullptr) and (root->right == nullptr)) {
			int x = stoi(s);

			ans += x;
		}

		dfs(root->left, s);
		dfs(root->right, s);

		s.pop_back();
	}

	int sumNumbers(TreeNode* root) {

		string s = "";
		dfs(root, s);

		return ans;
	}
};