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

	bool dfs(TreeNode* root, TreeNode* subRoot) {

		if ((root == nullptr) and (subRoot == nullptr)) {
			return true;
		}

		if ((root == nullptr) or (subRoot == nullptr)) {
			return false;
		}

		if ((root->val) != (subRoot->val)) {
			return false;
		}

		return dfs(root->left, subRoot->left) & dfs(root->right, subRoot->right);
	}

	bool ans = false;

	void preorder(TreeNode* root, TreeNode* subRoot) {
		if (root == nullptr) {
			return;
		}

		if ((root->val) == (subRoot->val)) {
			ans |= dfs(root, subRoot);
			if (ans == true) {
				return;
			}
		}

		preorder(root->left, subRoot);
		preorder(root->right, subRoot);
	}

	bool isSubtree(TreeNode* root, TreeNode* subRoot) {

		preorder(root, subRoot);

		return ans;
	}
};