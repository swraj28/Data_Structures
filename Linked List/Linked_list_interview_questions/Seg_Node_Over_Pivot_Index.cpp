/*
1. Given a singly linklist, Segregate Node of LinkedList over pivot index and return starting node of linkedlist.
2. pivot will be any random index in range of 0 to length Of Linkedlist
3. After segregation pivot Element should have to be present at correct position as in sorted linkedlist.
Input Format
1->5->2->9->5->14->11->1->10->10->1->3->null
11
Output Format
1->2->1->1->3->5->9->5->14->11->10->10->null
*/


#include <iostream>
using namespace std;

class ListNode
{
public:
  int val = 0;
  ListNode* next = nullptr;

  ListNode(int val)
  {
    this->val = val;
  }
};

ListNode* segregate(ListNode* head, int pivotIdx) {

  if (head == nullptr or head->next == nullptr) {
    return head;
  }

  int idx = 0;

  ListNode* curr = head;

  int Val = -1;

  while (curr != nullptr) {
    if (idx == pivotIdx) {
      Val = curr->val;
      break;
    }
    curr = curr->next;

    idx++;
  }

  ListNode* smaller = new ListNode(-1);
  ListNode* p_s = smaller;

  ListNode* gre_equal = new ListNode(Val);
  ListNode * p_g = gre_equal;

  curr = head;

  idx = 0;

  while ((curr) != nullptr) {
    if (idx == pivotIdx) {
      curr = curr->next;
      idx++;
      continue;
    }

    if ((curr->val) <= Val) {
      p_s->next = curr;
      p_s = p_s->next;
    } else {
      p_g->next = curr;
      p_g = p_g->next;
    }

    curr = curr->next;
    idx++;
  }

  p_g->next = nullptr;
  p_s->next = gre_equal;

  return smaller->next;
}

void printList(ListNode* node)
{
  ListNode* curr = node;
  while (curr != nullptr)
  {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
}

ListNode* createList(int n)
{
  ListNode* dummy = new ListNode(-1);
  ListNode* prev = dummy;
  while (n-- > 0)
  {
    int val;
    cin >> val;
    prev->next = new ListNode(val);
    prev = prev->next;
  }
  return dummy->next;
}

int main()
{
  int n, pivotIdx;
  cin >> n;
  ListNode* h1 = createList(n);
  cin >> pivotIdx;
  h1 = segregate(h1, pivotIdx);
  printList(h1);

  return 0;
}