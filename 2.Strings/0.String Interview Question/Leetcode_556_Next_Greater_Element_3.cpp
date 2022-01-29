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

// 1. O(nlog(n))

class Solution {
public:
	int nextGreaterElement(int n) {

		string s = to_string(n);

		n = s.length();

		multiset<int> st;

		bool f = true;

		for (int i = 1; i < n; i++) {
			if (s[i] > s[i - 1]) {
				f = false;
				break;
			}
		}

		if (f) {
			return -1;
		}

		for (int i = n - 1; i >= 0; i--) {
			int x = s[i] - '0';

			if (st.size()) {
				auto itr = st.upper_bound(x);

				if (itr == st.end()) {
					st.insert(x);
					continue;
				}

				int y = (*itr);

				st.erase(itr);

				s[i] = (y + '0');

				st.insert(x);

				for (int j = i + 1; j < n; j++) {
					int val = (*st.begin());
					st.erase(st.begin());
					s[j] = (val + '0');
				}
				break;
			} else {
				st.insert(x);
			}
		}

		ll x = stoll(s);

		if (x > INT_MAX) {
			return -1;
		}

		return (int)x;
	}
};

// ref: https://www.geeksforgeeks.org/find-next-greater-number-set-digits/

// Time: O(n), n is the length of the digits

int nextGreaterElement(int n) {

	string s = to_string(n);
	int i = s.size() - 2;

	// start from right
	// find the number x which is smaller than the next one

	for (; i >= 0; i--) {
		if (s[i] < s[i + 1]) break;
	}

	// if it doesn't exist, return -1
	if (i < 0) return -1;

	// find the number x' in the right side which is just greater than x

	for (int j = s.size() - 1; j > i; j--) {
		if (s[j] > s[i]) {
			swap(s[i], s[j]);
			break;
		}
	}

	// reverse right side to make it in increasing order
	reverse(s.begin() + i + 1, s.end());

	long res = stol(s);
	return res > INT_MAX ? -1 : res; // check if the result is longer than 32-bits
}