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

// 1. Brute force

class Solution {
public:

	void dfs(TreeNode* root, int targetSum, int &c, vector<int> &v) {
		if (root == nullptr) {
			return;
		}

		v.pb(root->val);
		dfs(root->left, targetSum, c, v);
		dfs(root->right, targetSum, c, v);

		// Prefix Sum:-

		// Redundant Calling

		int s = 0;
		for (int i = (v.size() - 1); i >= 0; i--) {
			s += v[i];

			if (s == targetSum) {
				c++;
			}
		}

		v.pop_back();
	}

	int pathSum(TreeNode* root, int targetSum) {

		int cnt = 0;
		vector<int> v;

		dfs(root, targetSum, cnt, v);

		return cnt;
	}
};

// 2. Optimized:- (This Question is very similar to Number of subarrays whose sum is equal to K).

class Solution {
public:

	unordered_map<int, int> m;
	int cnt = 0;

	void dfs(TreeNode* root, int targetSum, int sm) {
		if (root == nullptr) {
			return;
		}

		sm += (root->val);

		if (sm == targetSum) {
			cnt++;
		}

		// (sum-x)= targetSum---> x=(sm- targetSum)

		if (m.find(sm - targetSum) != m.end()) {
			cnt += m[sm - targetSum];
		}
		m[sm]++;

		dfs(root->left, targetSum, sm);
		dfs(root->right, targetSum, sm);

		m[sm]--;
	}

	int pathSum(TreeNode* root, int targetSum) {

		dfs(root, targetSum, 0);

		return cnt;
	}
};