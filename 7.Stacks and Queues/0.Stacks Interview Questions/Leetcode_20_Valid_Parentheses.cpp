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

		stack<char> st;

		for (int i = 0; i < n; i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				st.push(s[i]);
			} else {
				if (st.empty() == true) {
					return false;
				}

				if (s[i] == ')') {
					if (st.top() != '(') {
						return false;
					}

					st.pop();
				} else if (s[i] == '}') {
					if (st.top() != '{') {
						return false;
					}

					st.pop();
				} else if (s[i] == ']') {
					if (st.top() != '[') {
						return false;
					}

					st.pop();
				}
			}
		}

		return ((int)st.size() == 0);
	}
};