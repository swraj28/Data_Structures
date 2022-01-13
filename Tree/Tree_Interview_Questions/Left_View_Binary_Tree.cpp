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

// Link:- https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;

	Node(int x) {
		data = x;
		left = right = NULL;
	}
};

//Function to return a list containing elements of left view of the binary tree.

/*
     Expected Time Complexity: O(N).
	 Expected Auxiliary Space: O(Height of the Tree).
*/

// 1. Using Extra Space:- (Brute Force)--> Using Level Order Traversal:-

vector<int> leftView(Node *root) {

	vector<int> v;

	if (root == nullptr) {
		return v;
	}

	queue<Node*> q;
	q.push(root);

	while (true) {

		int s = q.size();
		if (s == 0) {
			break;
		}

		bool f = true;

		while (s--) {
			auto node = q.front();
			q.pop();

			if (f) {
				v.push_back(node->data);
				f = false;
			}

			if (node->left) {
				q.push(node->left);
			}

			if (node->right) {
				q.push(node->right);
			}
		}
	}

	return v;
}

// Optimized :- Using DFS:- (Auxiliary Space--> Stack Frame Created Equals to the Height Of the Tree).

vector<int> v;

int first_view = 1;

void dfs(Node *root, int curr_level) {
	if (root == NULL)return;

	if (first_view == curr_level) {
		v.push_back(root->data);
		first_view++;
	}

	dfs(root->left, curr_level + 1);
	dfs(root->right, curr_level + 1);
}

vector<int> leftView(Node *root) {

	if (root == NULL)return v;

	int curr_level = 1;
	dfs(root, curr_level);

	return v;
}