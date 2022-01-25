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

       The Key Idea is that either use DFS or BFS but we need to maintain the level. Earlier level nodes should not be processed after
       the levels below the given level.

*/

class Solution {
public:

	vector<vector<int>> verticalTraversal(TreeNode* root) {

		vector<vector<int> > ans;
		if (root == nullptr) {
			return ans;
		}

		queue<pair<TreeNode*, int>> q;
		q.push({root, 0});

		multiset<pair<int, int>> s;

		map<int, vector<int>> m;

		while (true) {

			int sze = q.size();
			if (sze == 0) {
				break;
			}

			s.clear();

			while (sze--) {

				auto p = q.front();
				q.pop();

				int val = p.ff->val;
				int angle = p.ss;

				s.insert({angle, val});

				if (p.ff->left) {
					q.push({p.ff->left, (angle - 1)});
				}

				if (p.ff->right) {
					q.push({p.ff->right, (angle + 1)});
				}
			}

			for (auto p : s) {
				int val = p.ss;
				int angle = p.ff;

				m[angle].pb(val);
			}
		}

		for (auto i : m) {
			ans.pb(i.ss);
		}

		return ans;
	}
};