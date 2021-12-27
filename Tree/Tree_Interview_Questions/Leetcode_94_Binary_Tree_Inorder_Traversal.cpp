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

	vector<int> res;

	void in_order_itr(TreeNode*root) {

		stack<TreeNode*>s;
		TreeNode*curr = root;

		while (!s.empty() or curr != nullptr) {

			while (curr != NULL) {
				s.push(curr);
				curr = curr->left;
			}
			curr = s.top();
			res.pb(curr->val);
			s.pop();

			curr = curr->right;
		}
	}

	vector<int> inorderTraversal(TreeNode* root) {

		in_order_itr(root);

		return res;
	}
};