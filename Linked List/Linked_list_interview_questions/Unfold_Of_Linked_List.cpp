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

/*

Given a singly linkedlist : l0 -> ln -> l1 -> ln-1 -> l2 -> ln-2 -> l3 -> ln-3 -> .....

reorder it :  l0 -> l1 -> l2 -> l3 -> l4 -> l5 -> l6 ..... -> ln-1 -> ln


Input Format
1->7->2->6->3->5->4->null
Output Format
1->2->3->4->5->6->7->null

*/

// 0 <= N <= 10^6

class ListNode {
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val) {
        this->val = val;
    }
};


void unfold(ListNode *head) {

    //Uptill length 2 we do not need to do anything

    if (head == nullptr) {
        return;
    }

    if (head->next == nullptr) {
        return;
    }

    if (head->next->next == nullptr) {
        return;
    }

    ListNode* slow = head;

    ListNode* head1 = head->next;

    ListNode* fast = head1;

    while ((fast != nullptr) and (fast->next != nullptr)) {

        slow->next = slow->next->next;
        fast->next = fast->next->next;

        slow = slow->next;
        fast = fast->next;
    }

    slow->next = nullptr;


    ListNode* prev = nullptr;
    ListNode* curr = head1;

    while (curr != nullptr) {
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    head1 = prev;

    slow->next = head1;
}

void printList(ListNode *node) {

    ListNode *curr = node;

    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0) {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }

    ListNode *head = dummy->next;
    unfold(head);
    printList(head);

    return 0;
}