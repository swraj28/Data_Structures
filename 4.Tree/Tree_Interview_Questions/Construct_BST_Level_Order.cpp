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

class levelPair
{
public:
    TreeNode *par = nullptr;
    int lb = INT_MIN;
    int rb = INT_MAX;

    levelPair()
    {
    }

    levelPair(TreeNode *par, int lb, int rb)
    {
        this->par = par;
        this->lb = lb;
        this->rb = rb;
    }
};

/*

     The Key Idea here is to pass all the ranges of the left and the right subtree and attach every node at its right place.

*/

TreeNode *constructBSTFromLevelOrder(vector<int> &levelorder) {

    if (levelorder.size() == 0) {
        return nullptr;
    }

    int l_idx = 0;

    queue<levelPair> q;

    TreeNode* root = new TreeNode(levelorder[l_idx]);

    q.push(levelPair(root, INT_MIN, (root->val)));
    q.push(levelPair(root, (root->val), INT_MAX));

    l_idx += 1;

    while ((!q.empty()) and (l_idx < levelorder.size())) {

        auto lp = q.front();
        q.pop();

        int val = levelorder[l_idx];

        if ((val >= lp.lb) and (val <= lp.rb)) {
            if ((lp.par->val) > val) {
                TreeNode* n = new TreeNode(val);
                lp.par->left = n;

                q.push(levelPair(n, lp.lb, val));
                q.push(levelPair(n, val, lp.par->val));
            } else {
                TreeNode* n = new TreeNode(val);
                lp.par->right = n;

                q.push(levelPair(n, (lp.par->val), val));
                q.push(levelPair(n, val, lp.rb));
            }

            l_idx++;
        }
    }

    return root;
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

    TreeNode *root = constructBSTFromLevelOrder(pre);
    display(root);
}

int main()
{
    solve();
    return 0;
}