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
	bool canArrange(vector<int>& arr, int k) {

		int n = arr.size();

		unordered_multiset<int> s;

		int cnt = 0;

		for (int i = 0; i < n; i++) {

			int x = ((arr[i] % k) + k) % k; // This is done to handle to negative number modulo.

			if (x == 0) {
				auto itr = s.find(x);

				if (itr == s.end()) {
					s.insert(x);
				} else {
					cnt++;
					s.erase(itr);
				}
			} else {
				auto itr = s.find(k - x);

				if (itr == s.end()) {
					s.insert(x);
				} else {
					cnt++;
					s.erase(itr);
				}
			}
		}

		return (cnt == (n / 2));
	}
};