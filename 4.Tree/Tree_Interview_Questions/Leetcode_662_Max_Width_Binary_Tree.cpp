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

       The Idea here is to use to use level Order Traversal and during the traversal we maintain a idx at which the node value is stored
       in an array if we consider the tree as a perfect binary tree.

       The tree given in the question may not be perfect but at that particualr index we will store the null value.
*/

class Solution {
public:
	int widthOfBinaryTree(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}

		if (root->left == nullptr and root->right == nullptr) {
			return 1;
		}

		queue<pair<TreeNode*, ull>> q;

		q.push({root, 1});

		int mx = 0;

		while (true) {

			ull s = q.size();

			if (s == 0) {
				break;
			}

			ull sze = (q.back().ss - q.front().ss) + 1;

			mx = max(mx, (int)sze);

			while (s--) {

				auto node = q.front();
				q.pop();

				ull idx = node.ss;

				if (node.ff->left) {
					q.push({node.ff->left, (2 * (ull) idx)});
				}

				if (node.ff->right) {
					q.push({node.ff->right, ((2 * (ull) idx) + 1)});
				}
			}
		}

		return mx;
	}
};