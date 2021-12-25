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

	void inOrder(TreeNode*root) {
		if (root == NULL) {
			return;
		}

		inOrder(root->left);
		cout << root->val << " ";
		inOrder(root->right);
	}

	void in_order_itr(TreeNode*root) {

		stack<TreeNode*>s;
		TreeNode*curr = root;

		while (!s.empty() or curr != NULL) {

			while (curr != NULL) {
				s.push(curr);
				curr = curr->left;
			}
			curr = s.top();
			cout << curr->val << " ";
			s.pop();

			curr = curr->right;
		}
	}

	void inOrder_morris_traversal(TreeNode*root) {//t.c-o(nodes) and s.c-o(1)
		if (root == NULL)return;

		TreeNode*curr = root;

		while (curr != NULL) {

			if (curr->left == NULL) {
				cout << curr->val << " ";
				curr = curr->right;
			} else {
				//find the inorder predecessor of curr
				TreeNode*pred = curr->left;
				//To find predecessor keep going right till right TreeNode is not null or right TreeNode is not current.
				while (pred->right != NULL and pred->right != curr) {
					pred = pred->right;
				}
				//if right TreeNode is null then go left after establishing link from predecessor to current.
				if (pred->right == NULL) {
					pred->right = curr;
					curr = curr->left;
				} else { //left is already visit. Go right after visiting current.
					pred->right == NULL;
					cout << curr->val << " ";
					curr = curr->right;
				}
			}
		}
	}

	vector<int> inorderTraversal(TreeNode* root) {

	}
};