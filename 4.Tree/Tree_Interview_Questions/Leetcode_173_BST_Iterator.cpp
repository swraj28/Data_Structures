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

// The Brute force approach to store the inorder traversal of the tree in a vector and every time the next() function is called we will print the value
// and move the pointer forward and if the pointer becomes equal to the number of nodes the hasNext() function will return false otherwise true.


// Optimized Approach:-  Use of an explict stack.

/*
    1. First of all in the stack we will store all the left child from the root node.

    2. After that for every node present at the top of the stack we will store the right child of that node. Let the right child of that node be node1.
       Now will will store all the left child of node1 .


    The element at the top of the stack will be printed and popped and whenever the stack gets empty it means all the elements have been processed.
*/

class BSTIterator {
public:

	vector<TreeNode*> Stack;

	int sze = 0;

	BSTIterator(TreeNode* root) {
		while (root != nullptr) {
			Stack.pb(root);
			root = root->left;
			sze++;
		}
	}

	int next() {
		int ans = Stack[sze - 1]->val;

		TreeNode* root = Stack[sze - 1];

		Stack.pop_back();
		sze -= 1;

		if (root->right) {
			root = root->right;

			while (root != nullptr) {
				Stack.pb(root);
				root = root->left;
				sze++;
			}
		}

		return ans;
	}

	bool hasNext() {
		return sze > 0;
	}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */