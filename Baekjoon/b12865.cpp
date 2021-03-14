#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, max_weight;
vector<pair<int, int>> items;
vector<vector<int>> dp;


int solve(int item_index, int remain_weight) {
	if (remain_weight == 0) return 0;
	if (remain_weight < 0) return -100000000;

	if (item_index >= n) return 0;
	if (dp[item_index][remain_weight] != -1)
		return dp[item_index][remain_weight];


	auto item = items[item_index];
	int w = item.first;
	int v = item.second;

	int use_this = solve(item_index + 1, remain_weight - w) + v;
	int unuse_this = solve(item_index + 1, remain_weight);

	dp[item_index][remain_weight] = max(use_this, unuse_this);
	return dp[item_index][remain_weight];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> max_weight;
	dp.assign(n + 1, vector<int>(max_weight + 1, -1));

	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;

		items.push_back(make_pair(w, v));
	}

	cout << solve(0, max_weight) << endl;
}


// DP 적용 불가 (2^100)
//int n, max_weight;
//vector<pair<int, int>> items;
//
//
//int solve(int weight, vector<bool> item_used) {
//	auto identity_f = [](bool used) { return used; };
//	if (all_of(item_used.begin(), item_used.end(), identity_f)) {
//		return 0;
//	}
//
//	int max_value = 0;
//	for (int i = 0; i < item_used.size(); i++) {
//		// 이미 쓴 아이템은 못씀
//		if (item_used[i]) continue;
//
//		int w = items[i].first;
//		int v = items[i].second;
//
//		// weight가 오버되면 못씀
//		if (weight + w > max_weight) continue;
//
//		auto vec = item_used;
//		vec[i] = true;
//		int new_value = solve(weight + w, vec) + v;
//
//		if (max_value < new_value) {
//			max_value = new_value;
//		}
//	}
//
//	return max_value;
//}
//
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n >> max_weight;
//
//	for (int i = 0; i < n; i++) {
//		int w, v;
//		cin >> w >> v;
//
//		if (v == 0) continue;
//		items.push_back(make_pair(w, v));
//	}
//
//	cout << solve(0, vector<bool>(n, false)) << endl;
//}
