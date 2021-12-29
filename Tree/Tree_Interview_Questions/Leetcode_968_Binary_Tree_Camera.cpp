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
    Some Important observations:-

    1. If the tree has Single node then we will place the camera on the root node otherwise let recursion decide whether we require
       to place the Camera on the root node or not.

    2. It is not ideal to place the Camera on the leaf node. As the Camera Covers its child as well its Parent, but the leaf node doesn't
       have any child node. Leaf Nodes will always be covered by some of its Parents.

    3. We will Perform Post Order Traversal.

    4. If some node returns Covered (i.e., 1) then that node is not under the cover of some Camera. That Node will ask its Parent to place a Camera.
       If Parent is there (i.e., root) then we will place the camera on that particular node itself.

*/

class Solution {
public:

#define Need_Camera -1  // If a node returns -1 then a Camera must be placed at its parent node.
#define Has_Camera 0   // If a camera is placed on a particular node then it will return 0.
#define Covered 1      // If the parent of the node has camera then its returns 1.  

	int ans = 0;

	int dfs(TreeNode* root) {
		if (root == nullptr) {
			return Covered;
		}

		if ((root->left == nullptr) and (root->right == nullptr)) {
			return Need_Camera;
		}

		int l = dfs(root->left);
		int r = dfs(root->right);

		if (l == Need_Camera or r == Need_Camera) {
			ans++;
			return Has_Camera;
		}

		if (l == Has_Camera or r == Has_Camera) {
			return Covered;
		}

		return Need_Camera;
	}


	int minCameraCover(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}

		if ((root->left == nullptr) and (root->right == nullptr)) {
			return 1;
		}

		int x = dfs(root);

		if (x == -1) { // Needed to place the caemera on the root.
			ans++;
		}

		return ans;
	}
};