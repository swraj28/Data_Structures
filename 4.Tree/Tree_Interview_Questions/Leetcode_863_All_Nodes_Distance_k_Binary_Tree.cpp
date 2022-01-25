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


// Wrong Approach:-

class Solution {
public:

	vector<int> ans;

	void Nodes_Below_Target(TreeNode* root, int k) {
		if (root == nullptr) {
			return;
		}

		if (k == 0) {
			ans.pb(root->val);
			return;
		}

		Nodes_Below_Target(root->left, k - 1);
		Nodes_Below_Target(root->right, k - 1);
	}

	bool dfs(TreeNode* root, TreeNode* target) {
		if (root == nullptr) {
			return false;
		}

		if (root == target) {
			return true;
		}

		return dfs(root->left, target) or dfs(root->right, target);

	}

	vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

		if (k == 0) {
			ans.pb(target->val);
			return ans;
		}

		Nodes_Below_Target(target, k);

		int level = 0;
		queue<TreeNode*> q;

		q.push(root);

		bool f = false;

		while (true) {

			int sze = q.size();
			if (sze == 0) {
				break;
			}

			while (sze--) {
				TreeNode* fr = q.front();
				q.pop();

				if (fr == target) {
					f = true;
					break;
				}

				if (fr->left) {
					q.push(fr->left);
				}

				if (fr->right) {
					q.push(fr->right);
				}
			}

			if (f) {
				break;
			}

			level += 1;
		}


		bool l = false, r = false;

		l = dfs(root->left, target);
		r = dfs(root->right, target);

		// cout<<l<<" "<<r<<endl;

		// cout<<level<<endl;


		if (k <= level) {
			k = (level - k);
			if (k == 0) {
				ans.pb(root->val);
			} else if (l) {
				Nodes_Below_Target(root->left, k - 1);
			} else {
				Nodes_Below_Target(root->right, k - 1);
			}
		} else {
			k -= level;
			if (l) {
				Nodes_Below_Target(root->right, k - 1);
			} else {
				Nodes_Below_Target(root->left, k - 1);
			}
		}

		return ans;
	}
};