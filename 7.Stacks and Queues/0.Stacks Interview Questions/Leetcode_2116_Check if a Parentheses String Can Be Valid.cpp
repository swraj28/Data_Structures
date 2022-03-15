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


// Space Optimization Can be Done:-

// Extra Space:-

class Solution {
public:
	bool canBeValid(string s, string locked) {

		int n = s.length();

		if (n % 2) {
			return false;
		}

		vector<int> v_1, v_0;

		for (int i = 0; i < n; i++) {
			if (s[i] == '(') {
				if (locked[i] == '0') {
					v_0.pb(i);
				} else {
					v_1.pb(i);
				}
			} else {
				if (locked[i] == '0') {
					v_0.pb(i);
				} else {
					if ((int)v_1.size() > 0) {
						v_1.pop_back();
					} else if ((int)v_0.size() > 0) {
						v_0.pop_back();
					} else {
						return false;
					}
				}
			}
		}

		int a = v_0.size(), b = v_1.size();

		int total = (a + b);

		if (total % 2) {
			return false;
		}

		for (int i = b - 1; i >= 0; i--) {
			if (a > 0 && v_0[a - 1] > v_1[i]) {
				v_0.pop_back();
				a -= 1;
			} else {
				return false;
			}
		}

		if (a % 2) {
			return false;
		}

		return true;
	}
};