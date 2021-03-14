#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int height, width;
vector<vector<int>> cheese;
vector<vector<int>> path;

vector<int> dx = { 0, 0, 1, -1 };
vector<int> dy = { 1, -1, 0, 0 };


int count_cheese() {
	int sum = 0;
	for (int j = 0; j < height + 2; j++) {
		for (int i = 0; i < width + 2; i++) {
			sum += cheese[j][i];
		}
	}
	return sum;
}

int main() {
	cin >> height >> width;
	cheese.assign(height + 2, vector<int>(width + 2, 0));

	for (int j = 1; j <= height; j++) {
		for (int i = 1; i <= width; i++) {
			cin >> cheese[j][i];
		}
	}

	int iter = 0;
	int last_cheese_count = 0;
	while (count_cheese() != 0) {
		last_cheese_count = count_cheese();
		path.assign(height + 2, vector<int>(width + 2, 0));
		queue<pair<int, int>> worklist;

		path[0][0] = 1;
		worklist.push(make_pair(0, 0));

		while (!worklist.empty()) {
			pair<int, int> pos = worklist.front();
			worklist.pop();

			int i = pos.first;
			int j = pos.second;

			// 치즈가 있는 곳이면 더 이상 들어가지 않음
			if (cheese[j][i] == 1) continue;

			// 치즈가 없는 곳이면 상하좌우를 worklist에 넣기
			for (int d = 0; d < 4; d++) {
				int i_dx = i + dx[d];
				int j_dy = j + dy[d];

				bool valid_index = 
					j_dy >= 0
					&& j_dy < cheese.size()
					&& i_dx >= 0 
					&& i_dx < cheese[0].size();
				if (!valid_index) continue;

				// 이미 가봤거나 갈 곳이라고 마킹해 둔 곳이면 worklist에 넣지 않는다.
				if (path[j_dy][i_dx] == 1) continue;

				// 여기 갈거야 라고 마킹하고 worklist에 넣음
				path[j_dy][i_dx] = 1;
				worklist.push(make_pair(i_dx, j_dy));
			}
		}

		// 치즈 업데이트
		for (int j = 1; j < height; j++) {
			for (int i = 1; i < width; i++) {
				int is_unvisited = (path[j][i] + 1) % 2;
				cheese[j][i] = cheese[j][i] & is_unvisited;
			}
		}

		iter++;
	}

	cout << iter << endl;
	cout << last_cheese_count << endl;
}