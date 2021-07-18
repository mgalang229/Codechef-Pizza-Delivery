#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> h(n + 1);
		int mx = INT_MIN;
		for (int i = 1; i <= n; i++) {
			cin >> h[i];
			// find the maximum amount
			mx = max(mx, 2 * h[i]);
		}
		vector<int> k(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> k[i];
		}
		vector<vector<int>> dp(n + 1, vector<int>(mx + 1));
		// place 0 as the first element
		dp[0][0] = 0;
		// set all the elements with an arbitrary large value (initial)
		for (int j = 1; j <= mx; j++) {
			dp[0][j] = 1000000000;
		}
		// we will iterate every coin available and compute for the minimum
		// number of coins to produce values from 1 to the maximum amount
		for (int i = 1; i <= n; i++) {
			// test every coin to see the number of coins that it will use to produce
			// the values from 1 to the maximum amount
			for (int j = 0; j <= mx; j++) {
				// set the initial number of coins from the previous value
				dp[i][j] = dp[i - 1][j];
				// check if the current coin is less than or equal to the current
				// amount being iterated upon
				if (k[i] <= j) {
					// if yes, then find the minimum value between the original number of
					// coins and the new number of coins by using the current coin
					// note: we are adding 1 because we are using this current coin
					dp[i][j] = min(dp[i][j], 1 + dp[i][j - k[i]]);
				}
			}
			// repeat this process until all the coins have been used
		}
		// the answer can be found in 'dp[n][2 * h[i]]' (value after all coins have been used)
		int res = 0;
		for (int i = 1; i <= n; i++) {
			res = res + dp[n][2 * h[i]];
		}
		cout << res << '\n';
	}
	return 0;
}
