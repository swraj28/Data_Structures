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

class Solution {
public:
	bool isValid(string s) {

		int n = s.length();

		if (n < 3) {
			return false;
		}

		if (s[0] != 'a' || s[n - 1] != 'c') {
			return false;
		}

		vector<char> v;

		int sze = 0;

		for (int i = 0; i < n; i++) {
			if (s[i] == 'c') {
				if (sze >= 2) {
					if (v[sze - 1] == 'b' && v[sze - 2] == 'a') {
						v.pop_back(), v.pop_back();
						sze -= 2;
					} else {
						return false;
					}
				} else {
					return false;
				}
			} else {
				v.pb(s[i]);
				sze++;
			}
		}

		return ((int)v.size() == 0);
	}
};