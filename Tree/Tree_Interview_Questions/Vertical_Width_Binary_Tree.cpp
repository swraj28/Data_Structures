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

//Link:- https://practice.geeksforgeeks.org/problems/vertical-width-of-a-binary-tree/1/


struct Node {
	int data;
	struct Node* left;
	struct Node* right;

	Node(int x) {
		data = x;
		left = right = NULL;
	}
};


int verticalTraversal(Node* root) {

	if (root == nullptr) {
		return 0;
	}

	queue<pair<Node*, int>> q;
	q.push({root, 0});

	map<int, vector<int>> m;

	while (true) {

		int sze = q.size();
		if (sze == 0) {
			break;
		}

		while (sze--) {

			auto p = q.front();
			q.pop();

			int val = p.first->data;
			int angle = p.second;

			m[angle].push_back(val);

			if (p.first->left) {
				q.push({p.first->left, (angle - 1)});
			}

			if (p.first->right) {
				q.push({p.first->right, (angle + 1)});
			}
		}
	}

	return m.size();
}


int verticalWidth(Node* root) {

	return verticalTraversal(root);
}