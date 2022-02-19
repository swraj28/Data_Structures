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
	string removeKdigits(string num, int k) {

		int n = num.length();

		if (n <= k) {
			return "0";
		}

		stack<char> s;

		for (int i = 0; i < n; i++) {

			while (k > 0 && (!s.empty()) && (s.top() > num[i])) {
				k -= 1;
				s.pop();
			}

			s.push(num[i]);
		}

		while (k > 0) {
			s.pop();
			k -= 1;
		}

		num = "";

		while (!s.empty()) {
			num += s.top();
			s.pop();
		}

		reverse(all(num));

		int idx = 0;

		while (idx < num.length()) {
			if (num[idx] != '0') {
				break;
			}
			idx++;
		}

		if (idx == num.length()) {
			return "0";
		}

		num = num.substr(idx);

		return num;
	}
};