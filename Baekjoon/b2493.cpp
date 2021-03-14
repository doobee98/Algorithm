#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int n;
vector<pair<int, int>> towers;	// (id, height)
vector<int> result;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	result.assign(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		int input;
		cin >> input;

		towers.push_back(make_pair(i, input));
	}

	reverse(towers.begin(), towers.end());

	vector<pair<int, int>> stack;
	for (auto tower : towers) {
		int tower_id = tower.first;
		int tower_height = tower.second;

		// 스택 안에 있는 타워중 이 타워가 그 레이저를 받아준다면, 빼서 처리함
		while (stack.size() > 0 && stack.back().second < tower_height) {
			result[stack.back().first] = tower_id;
			stack.pop_back();
		}

		stack.push_back(tower);
	}

	for (int i = 1; i <= n; i++) {
		cout << result[i] << " ";
	}
	cout << endl;
}
