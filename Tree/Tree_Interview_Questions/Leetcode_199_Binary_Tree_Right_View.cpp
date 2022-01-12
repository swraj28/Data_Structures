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

/*
     Expected Time Complexity: O(N).
	 Expected Auxiliary Space: O(Height of the Tree).
*/

// 1. Using Extra Space:- (Brute Force)

class Solution {
public:

	vector<int> View(TreeNode *root) {

		vector<int> v;

		if (root == nullptr) {
			return v;
		}

		queue<TreeNode*> q;
		q.push(root);

		while (true) {

			int s = q.size();
			if (s == 0) {
				break;
			}

			bool f = true;

			while (s--) {

				auto node = q.front();
				q.pop();

				if (f) {
					v.push_back(node->val);
					f = false;
				}

				if (node->right) {
					q.push(node->right);
				}

				if (node->left) {
					q.push(node->left);
				}
			}
		}

		return v;
	}

	vector<int> rightSideView(TreeNode* root) {

		return View(root);
	}
};