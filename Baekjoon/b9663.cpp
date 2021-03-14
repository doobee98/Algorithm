#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int n_queen_count = 0;


bool check_upper(int x, int y, vector<int>& path) {	
	for (int i = 0; i < path.size(); i++) {
		int j = path[i];

		// 세로
		if (y == j) return false;

		// 왼대각
		if (i - j == x - y) return false;

		// 오른대각
		if (i + j == x + y) return false;
	}

	return true;
}

void explore(vector<int> path) {
	int depth = path.size();

	if (depth == n) {
		n_queen_count++;
		return;
	}

	for (int y = 0; y < n; y++) {
		if (check_upper(depth, y, path)) {
			vector<int> next_path = path;
			next_path.push_back(y);
			explore(next_path);
		}
	}
}

int main() {
	cin >> n;

	explore(vector<int>());
	cout << n_queen_count << endl;
}