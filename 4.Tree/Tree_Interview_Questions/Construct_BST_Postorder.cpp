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

int post_idx;

TreeNode* build_tree(vector<int> &postorder, int l, int r) {

    if (post_idx < 0) {
        return nullptr;
    }

    if ((postorder[post_idx] >= l) and (postorder[post_idx] <= r)) {

    } else {
        return nullptr;
    }

    TreeNode* root = new TreeNode(postorder[post_idx--]);

    root->right = build_tree(postorder, (root->val), r);
    root->left = build_tree(postorder, l, (root->val));

    return root;
}

TreeNode *bstFromPostorder(vector<int> &postorder) {

    post_idx = postorder.size() - 1;

    return build_tree(postorder, INT_MIN, INT_MAX);
}

// input_Section_====================================================================

void display(TreeNode *node)
{
    if (node == nullptr)
        return;

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
    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    TreeNode *root = bstFromPostorder(pre);
    display(root);
}

int main()
{
    solve();
    return 0;
}