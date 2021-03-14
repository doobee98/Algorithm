#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int d = 1000000000;

vector<vector<int>> dp(201, vector<int>(201, -1));

int solve(int n, int k) {
	if (k == 1) return 1;
	if (dp[n][k] != -1) return dp[n][k];

	int sum = 0;
	for (int i = 0; i <= n; i++) {
		if (n - i < 0) break;

		sum = (sum + solve(n - i, k - 1)) % d;
	}
	dp[n][k] = sum;
	return dp[n][k];
}


int main() {
	int n, k;
	cin >> n >> k;

	cout << solve(n, k) << endl;
}