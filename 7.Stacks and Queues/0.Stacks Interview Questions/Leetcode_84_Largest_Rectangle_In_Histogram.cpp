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
	int largestRectangleArea(vector<int>& heights) {

		int n = heights.size();

		// We will maintain two arrays (NSR--> Next Smaller to Right) and (NSL--> Next Smaller to left)

		vector<int> nsl(n, 0);
		vector<int> nsr(n, 0);

		stack<int> s;

		for (int i = n - 1; i >= 0; i--) {
			while (!s.empty() && heights[s.top()] >= heights[i]) {
				s.pop();
			}

			nsr[i] = s.empty() ? n : s.top();

			s.push(i);
		}

		stack<int> s1;

		for (int i = 0; i < n; i++) {
			while (!s1.empty() && heights[s1.top()] >= heights[i]) {
				s1.pop();
			}

			nsl[i] = s1.empty() ? -1 : s1.top();

			s1.push(i);
		}

		// for (int i = 0; i < n; i++) {
		// 	cout << nsr[i] << " ";
		// }
		// cout << endl;

		// for (int i = 0; i < n; i++) {
		// 	cout << nsl[i] << " ";
		// }
		// cout << endl;

		int mx = INT_MIN;

		for (int i = 0; i < n; i++) {
			int d = (nsr[i] - nsl[i]) - 1;

			int x = (d * heights[i]);

			mx = max(mx, x);
		}

		return mx;
	}
};