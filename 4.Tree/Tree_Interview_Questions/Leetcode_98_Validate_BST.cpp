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

/*
     Important Points:-

     1. Inorder Traversal Of BST gives sorted array. The Brute force solution is that find the inorder traversal of the BT and if it is sorted
        then it will be BST. (Extra Space :- O(nodes))

     2. We can even solve this without any Extra Space.
        --> If we would obtained the inorder Traversal then we would have use used Two Pointer Technique to check whether the array is sorted or not.
        --> But we cannot store the inorder Traversal, we will use similar Two Pointer Technique to validate the BST.

        ---> How?

        ---> we will use a prev pointer that points to the prev node and the curr pointer is pointed by the root and we can make make comparisons like
             this.

*/

class Solution {
public:

	TreeNode* prev = nullptr;

	bool dfs(TreeNode* root) {
		if (root == nullptr) {
			return true;
		}

		bool left_bst = dfs(root->left);

		if (left_bst == false) {
			return false;
		}

		if ((prev != nullptr) and (prev->val) >= (root->val)) {
			return false;
		}

		prev = root;

		bool right_bst = dfs(root->right);

		if (right_bst == false) {
			return false;
		}

		return true;
	}

	bool isValidBST(TreeNode* root) {


		return dfs(root);
	}
};