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

// Brute Force:-

class CustomStack {
public:

	int mx_size;
	vector<int> v;

	int c_sze = 0;

	CustomStack(int maxSize) {
		mx_size = maxSize;
	}

	void push(int x) {
		if (c_sze < mx_size) {
			v.pb(x);
			c_sze++;
		}
	}

	int pop() {

		if (c_sze > 0) {
			int x = v[c_sze - 1];

			v.pop_back();
			c_sze -= 1;

			return x;
		}

		return -1;
	}

	void increment(int k, int val) {  // Everytime Here we are consuming the time of min(k,c_sze).

		for (int i = 0; i < min(k, c_sze); i++) {
			v[i] += val;
		}
	}
};

// Optimized :-  We will use the technique of lazy increment.

/*

			Lazy Increment:- What ever increment is done on the first k elements, we will store all the increment on the top element itself.
							 And Whenever we are popping the top element we will pas the increment to its predecessors (The previous Element)

*/

class CustomStack {
public:

	int mx_size;
	vector<int> Stack;

	vector<int> cnt;

	int c_sze = 0;

	CustomStack(int maxSize) {
		mx_size = maxSize;

		cnt.assign(mx_size, 0);
	}

	void push(int x) {
		if (c_sze < mx_size) {
			Stack.pb(x);
			c_sze++;
		}
	}

	int pop() {

		if (c_sze > 0) {

			int x = Stack[c_sze - 1];
			Stack.pop_back();

			x += cnt[c_sze - 1];

			if ((c_sze - 2) >= 0) {
				cnt[c_sze - 2] += cnt[c_sze - 1];
			}

			cnt[c_sze - 1] = 0;

			c_sze -= 1;

			return x;
		}

		return -1;
	}

	void increment(int k, int val) {

		int idx = min(k, c_sze) - 1;

		if (idx >= 0) {
			cnt[idx] += val;
		}
	}
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */