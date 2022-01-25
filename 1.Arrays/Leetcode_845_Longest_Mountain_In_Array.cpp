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

// Sliding Window:-  (Two Pointers)

class Solution {
public:
	int longestMountain(vector<int>& arr) {

		int n = arr.size();

		if (n < 3) {
			return false;
		}

		bool inc = false, dec = false;

		int st = 0;

		int mx = INT_MIN;

		for (int i = 1; i < n; i++) {
			if (arr[i] == (arr[i - 1])) {
				if (inc == 1 and dec == 1) {
					int dif = ((i - 1) - st) + 1;
					mx = max(mx, dif);
				}
				st = i;
				inc = false, dec = false;
			} else if (arr[i] > arr[i - 1]) {
				if (inc == 1 and dec == 1) {
					int dif = ((i - 1) - st) + 1;
					mx = max(mx, dif);

					st = (i - 1);
					inc = true, dec = false;
				} else {
					if (inc == false) {
						inc = true;
						st = (i - 1);
					}
				}
			} else {
				if (inc) {
					if (dec == false) {
						dec = true;
					}
				}
			}
		}

		if (inc == 1 and dec == 1) {
			int dif = ((n - 1) - st) + 1;
			mx = max(mx, dif);
		}

		return (mx == INT_MIN) ? 0 : mx;
	}
};