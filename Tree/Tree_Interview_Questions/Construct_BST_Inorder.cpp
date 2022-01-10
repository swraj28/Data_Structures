#include <iostream>
#include <vector>
using namespace std;

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

TreeNode* build_Tree(vector<int> &in, int s, int e) {

    if (s > e) {
        return nullptr;
    }

    int mid = (s + (e - s) / 2);

    TreeNode* root = new TreeNode(in[mid]);

    root->left = build_Tree(in, s, mid - 1);
    root->right = build_Tree(in, mid + 1, e);

    return root;
}

TreeNode *constructFromInOrder(vector<int> &in) {

    if (in.size() == 1) {
        TreeNode* root = new TreeNode(in[0]);

        return root;
    }
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
    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = constructFromInOrder(in);
    display(root);
}

int main()
{
    solve();
    return 0;
}