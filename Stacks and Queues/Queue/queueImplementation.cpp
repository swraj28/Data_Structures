#include <bits/stdc++.h>
using namespace std;

class Queue {
	int *arr;
	int front;  //deque
	int rear;   //enque
	int currSize;
	int maxSize;

public:
	Queue(int defaultSize = 6) {
		this->maxSize = defaultSize;
		this->arr = new int[this->maxSize];
		this->front = 0; //deque (pop)
		this->rear = -1; //enque (push)
		this->currSize = 0;
	}

	bool empty() {
		return this->currSize == 0;
	}

	int size() {
		return this->currSize;
	}

	void push(int data) {                       //enqueue always takes place at rear pointer
		if (this->currSize == this->maxSize) {
			cout << "Queue is full" << endl;
			return;
		}

		this->rear = (this->rear + 1) % this->maxSize;
		arr[this->rear] = data;
		this->currSize++;
	}

	void pop() {                               //dequeue always takes place at front pointer
		if (empty()) {
			cout << "Queue is empty" << endl;
			return;
		}

		this->front = (this->front + 1) % this->maxSize;
		this->currSize--;
	}

	int getFront() {
		return this->arr[this->front];
	}
};

int main() {

	Queue q(10);//initializing the default size to 10;

	// q.push(1);
	// q.push(2);
	// q.push(3);
	// q.push(4);
	// q.push(5);

	// cout<<q.getFront()<<endl;

	// cout<<q.size()<<endl;


	// q.pop();
	// q.pop();
	// q.pop();

	// cout<<q.getFront()<<endl;

	// q.pop();
	// q.pop();
	// q.pop();

	for (int i = 1; i <= 6; i++) {
		q.push(i);
	}

	q.pop();
	q.push(8);

	while (!q.empty()) {
		cout << q.getFront() << " ";
		q.pop();
	}

	return 0;
}