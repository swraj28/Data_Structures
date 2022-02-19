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

// Sliding Window + Hashmaps:-

class Solution {
public:
	string minWindow(string s, string t) {

		if (s == t) {
			return s;
		}

		int n = s.length(), m = t.length();

		unordered_map<char, int> cnt2, cnt1;

		for (int i = 0; i < m; i++) {
			cnt2[t[i]]++;
		}

		int mn = INT_MAX;
		string ans = "";

		int st = 0;

		for (int i = 0; i < n; i++) {

			cnt1[s[i]]++;

			bool f = true;

			for (int j = 0; j < 26; j++) {
				char ch = 'a' + j;
				if (cnt2[ch] != 0) {
					if (cnt2[ch] > cnt1[ch]) {
						f = false;
						break;
					}
				}
			}

			if (f) {
				for (int j = 0; j < 26; j++) {
					char ch = 'A' + j;
					if (cnt2[ch] != 0) {
						if (cnt2[ch] > cnt1[ch]) {
							f = false;
							break;
						}
					}
				}
			}

			if (f) {
				while (st < i) {
					if (cnt2[s[st]] == 0) {
						st++;
					} else {
						if (cnt1[s[st]] > cnt2[s[st]]) {
							cnt1[s[st]]--;
							st++;
						} else {
							break;
						}
					}
				}

				int d = (i - st) + 1;

				if (d < mn) {
					mn = d;
					ans = s.substr(st, d);
				}
			}
		}

		return ans;
	}
};