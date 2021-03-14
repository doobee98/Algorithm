#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, l;
vector<pair<int, int>> to_right_line;
vector<pair<int, int>> to_left_line;


// return pair(id, last_drop_time)
pair<int, int> solve() {
	if (to_left_line.size() == 0) {
		auto leftmost_to_right = to_right_line.front();
		return make_pair(leftmost_to_right.second, l - leftmost_to_right.first);
	}

	if (to_right_line.size() == 0) {
		auto rightmost_to_left = to_left_line.back();
		return make_pair(rightmost_to_left.second, l - rightmost_to_left.first);
	}

	// cur_iter: 현재 주 탐색 대상인 방향의 ant
	// op_iter : 매칭되는 반대방향의 ant를 찾기 위한 이터레이터
	auto& cur_line = to_left_line.front().first < to_right_line.front().first
		? to_left_line
		: to_right_line;
	auto& op_line = cur_line == to_left_line ? to_right_line : to_left_line;
	auto cur_iter = cur_line.begin();
	auto op_iter = op_line.begin();

	int last_drop_time = l - (*cur_iter).first;

	while (true) {
		bool no_remain_ant = cur_iter == cur_line.end() || op_iter == op_line.end();
		if (no_remain_ant) break;

		bool is_ant_crossed = (*cur_iter).first + (*op_iter).first > l;
		if (is_ant_crossed) break;

		cur_iter++;
		swap(cur_line, op_line);
		swap(cur_iter, op_iter);
	}

	int last_drop_ant_id = (*cur_iter).second;
	return make_pair(last_drop_ant_id, last_drop_time);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l;

	for (int i = 1; i <= n; i++) {
		int input;
		cin >> input;

		(input > 0 ? to_right_line : to_left_line).push_back(make_pair(input, i));
	}

	// 1 2 3 5 (7)
	sort(to_right_line.begin(), to_right_line.end());
	// -5 -4 -2 (7) -> 2 3 5
	sort(to_left_line.begin(), to_left_line.end());
	transform(to_left_line.begin(), to_left_line.end(), to_left_line.begin(), [](auto ant) {
		return make_pair(l + ant.first, ant.second);
	});

	auto result = solve();
	cout << result.first << " " << result.second << endl;
}
