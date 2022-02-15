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


// Two Pointer Approach:- (Sliding Window)

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {

		int n = s.length();

		int m = p.length();

		sort(all(p));

		unordered_set<char> st;

		for (int i = 0; i < m; i++) {
			st.insert(p[i]);
		}

		int idx = 0;

		vector<int> res;

		while (idx <= (n - m)) {

			if (st.find(s[idx]) != st.end()) {

				string x = s.substr(idx, m);
				sort(all(x));

				if (x == p) {
					res.pb(idx);

					int idx1 = (idx + m);

					while (idx1 < n) {
						if (s[idx1] == s[idx]) {
							idx += 1;
							res.pb(idx);
							idx1 += 1;
						} else {
							break;
						}
					}

					if (idx1 < n) {
						if (st.find(s[idx1]) == st.end()) {
							idx = idx1 + 1;
						} else {
							idx++;
						}
						continue;
					} else {
						break;
					}
				}
			}

			idx++;
		}



		return res;
	}
};