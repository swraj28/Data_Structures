//STACK BY USING TWO QUEUES (PUSH EFFICIENT)

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Stack {

	queue<int> q1, q2; //q1->primary queue and q2->secondary queue
	int curr_size;
public:
	Stack() {
		curr_size = 0;
	}

	void pop() {

		if (q1.empty()) {
			return;
		}

		while (q1.size() != 1) {
			q2.push(q1.front());
			q1.pop();
		}

		//pop the only left element from q1
		q1.pop();
		curr_size--;

		//swap the names of two queues;

		queue<int> q = q1;
		q1 = q2;
		q2 = q;
	}

	void push(int data) {
		q1.push(data);
		curr_size++;
	}

	int top() {

		if (q1.empty()) {
			return -1;
		}

		while (q1.size() != 1) {
			q2.push(q1.front());
			q1.pop();
		}
		// last element
		int temp = q1.front();

		//to empty the queue after the last operation
		q1.pop();
		// push the last element to q2
		q2.push(temp);

		//swap
		queue<int> q = q1;
		q1 = q2;
		q2 = q;

		return temp;
	}

	int size() {

		return curr_size;
	}

};

int main() {

// #ifndef ONLINE_JUDGE
// 	// for getting input from input.txt
// 	freopen("input.txt", "r", stdin);
// 	// for writing output to output.txt
// 	freopen("output.txt", "w", stdout);
// #endif

	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	cout << "current size: " << s.size()
	     << endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	cout << "current size: " << s.size()
	     << endl;
	return 0;




	return 0;
}