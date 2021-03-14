#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int from, to;
vector<bool> visited;


int solve() {
	if (from == to) return 0;

	int result;
	bool flag = false;
	queue<int> work_list;
	work_list.push(from);
	visited[from] = true;

	for (result = 0; !flag; result++) {
		int size = work_list.size();
		for (int i = 0; i < size; i++) {
			int cur = work_list.front();
			work_list.pop();

			// 앞으로 갈 곳 work_list에 넣기
			for (int next : {cur - 1, cur + 1, cur * 2}) {
				// 좌표가 이상한 곳
				if (next < 0 || next >= 100005) continue;
				// 이미 가 본곳
				if (visited[next]) continue;

				if (next == to) {
					flag = true;
					break;
				}

				visited[next] = true;
				work_list.push(next);
			}

			if (flag) break;
		}
	}

	return result;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> from >> to;
	visited.assign(100005, false);

	cout << solve() << endl;
}
