// STACK BY USING QUEUE (POP EFFICIENT)

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Stack {
	queue<int> q1, q2;
	int curr_size;
public:
	Stack() {
		curr_size = 0; //both the queues are empty initially
	}

	void push(int data) {
		curr_size++;

		//push data first in empty q2
		q2.push(data);

		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}

		//swap the name
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
	}

	void pop() {
		if (q1.empty()) {
			return ;
		}

		q1.pop();
		curr_size--;
	}

	int top() {
		if (q1.empty()) {
			return -1;
		}

		return q1.front();
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