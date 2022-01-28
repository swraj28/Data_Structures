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
	Video Link:- https://www.youtube.com/watch?v=B89In5BctFA&list=TLGGmXFc5cG2IQIyODAxMjAyMg&ab_channel=Pepcoding

    Key Concept:-
    			1. Find all the Nodes in (Target Node to Root) Path and store in a vector.
    			2. Taking the target node level as zero level iterte over the vector that contains Nodes to Root Path and find the node
    				which are (k- level) below that node ((k-level)>=0).

    			3. We Need to Add a Blocker (See Video For More Details).
*/

class Solution {
public:

	vector<TreeNode*> nodeToRootPath_(TreeNode* root, int data) {

		if (root == nullptr) {
			return {};
		}

		if (root->val == data) {

			vector<TreeNode*> v;
			v.pb(root);

			return v;
		}

		vector<TreeNode*> left = nodeToRootPath_(root->left, data);

		if (left.size()) {
			left.pb(root);
			return left;
		}

		vector<TreeNode*> right = nodeToRootPath_(root->right, data);

		if (right.size()) {
			right.pb(root);
			return right;
		}

		return {};
	}

	vector<int> ans;

	void Nodes_Below_Target(TreeNode* root, int k, int blocker) {
		if (root == nullptr) {
			return;
		}

		if ((root->val) == blocker) {
			return;
		}

		if (k == 0) {
			ans.pb(root->val);
			return;
		}

		Nodes_Below_Target(root->left, k - 1, blocker);
		Nodes_Below_Target(root->right, k - 1, blocker);
	}

	vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

		if (k == 0) {
			ans.pb(target->val);
			return ans;
		}

		vector<TreeNode*> Node_To_Root_Path = nodeToRootPath_(root, target->val);

		// for (auto Node : Node_To_Root_Path) {
		// 	cout << Node->val << " ";
		// }
		// cout << endl;

		for (int i = 0; i < Node_To_Root_Path.size(); i++) {
			if ((i - 1) >= 0) {
				Nodes_Below_Target(Node_To_Root_Path[i], k - i, Node_To_Root_Path[i - 1]->val);
			} else {
				Nodes_Below_Target(Node_To_Root_Path[i], k - i, -1);
			}
		}

		return ans;
	}
};