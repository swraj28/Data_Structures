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

// Link:- https://practice.geeksforgeeks.org/problems/vertical-sum/1

// We can even use dfs to solve the question. Only requirement is to maintain the angle with every node.

struct Node {
	int data;
	Node* left, * right;
};

class Solution {
public:
	vector <int> verticalSum(Node *root) {

		vector<int> ans;
		if (root == nullptr) {
			return ans;
		}

		map<int, int> m;

		queue<pair<Node*, int>> q;
		q.push({root, 0});

		while (!q.empty()) {

			auto p = q.front();
			q.pop();

			int val = p.first->data;
			int angle = p.second;

			m[angle] += val;

			if (p.first->left) {
				q.push({p.first->left, angle - 1});
			}

			if (p.first->right) {
				q.push({p.first->right, angle + 1});
			}
		}

		for (auto ele : m) {
			ans.push_back(ele.ss);
		}

		return ans;
	}
};