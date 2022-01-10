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

class TreeNode
{
public:
	int val = 0;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val)
	{
		this->val = val;
	}
};

TreeNode* build_Tree(vector<int> &inorder, vector<int> levelorder, int s, int e) {

	if (s > e) {
		return nullptr;
	}

	if (levelorder.size() == 0) {
		return nullptr;
	}

	TreeNode* root = new TreeNode(levelorder[0]);

	if (levelorder.size() == 1) {
		return root;
	}

	if (s == e) {
		return root;
	}

	int idx;
	for (int i = s; i <= e; i++) {
		if (inorder[i] == (root->val)) {
			idx = i;
			break;
		}
	}

	unordered_set<int> st;

	for (int i = s; i < idx; i++) {
		st.insert(inorder[i]);
	}

	vector<int> l_left, l_right;

	for (int i = 0; i < levelorder.size(); i++) {

		if (levelorder[i] == (root->val)) {
			continue;
		}

		if (st.find(levelorder[i]) != st.end()) {
			l_left.pb(levelorder[i]);
			st.erase(levelorder[i]);
		} else {
			l_right.pb(levelorder[i]);
		}
	}

	root->left = build_Tree(inorder, l_left, s, idx - 1);
	root->right = build_Tree(inorder, l_right, idx + 1, e);

	return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int> &levelorder) {

	if (levelorder.size() == 1) {
		TreeNode* root = new TreeNode(levelorder[0]);

		return root;
	}

	return build_Tree(inorder, levelorder, 0, (inorder.size() - 1));
}

// input_Section_====================================================================

void display(TreeNode *node)
{
	if (node == nullptr) {
		return;
	}

	string str = "";
	str += ((node->left != nullptr ? to_string(node->left->val) : "."));
	str += (" -> " + to_string(node->val) + " <- ");
	str += ((node->right != nullptr ? to_string(node->right->val) : "."));

	cout << str << endl;

	display(node->left);
	display(node->right);
}

void solve()
{
	int n;
	cin >> n;

	vector<int> in(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> in[i];
	}

	vector<int> level(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> level[i];
	}

	TreeNode *root = buildTree(in, level);

	display(root);
}

int main()
{
	solve();
	return 0;
}