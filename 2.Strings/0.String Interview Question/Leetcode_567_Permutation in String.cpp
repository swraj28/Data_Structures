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
	bool checkInclusion(string s1, string s2) {

		if (s1 == s2) {
			return true;
		}

		int n = s2.length(), m = s1.length();

		if (n < m) {
			return false;
		}

		vector<int> cnt1(26, 0);
		vector<int> cnt2(26, 0);

		for (int i = 0; i < m; i++) {
			cnt1[s1[i] - 'a']++;
		}

		for (int i = 0; i < m; i++) {
			cnt2[s2[i] - 'a']++;
		}

		bool f = true;

		for (int i = 1; i <= (n - m); i++) {

			for (int i = 0; i < 26; i++) {
				if (cnt1[i] != cnt2[i]) {
					f = false;
					break;
				}
			}

			if (f) {
				return true;
			}

			f = true;

			cnt2[s2[i - 1] - 'a']--;

			cnt2[s2[(i + m) - 1] - 'a']++;
		}

		for (int i = 0; i < 26; i++) {
			if (cnt1[i] != cnt2[i]) {
				return false;
			}
		}

		return true;
	}
};