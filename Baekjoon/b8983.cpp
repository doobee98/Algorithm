#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m, n, l;
vector<int> shooter;


bool isCatchable(int animal_x, int animal_y) {
	// 최대 거리보다 멀리 있으면 바로 아웃
	if (animal_y > l) return false;

	// 오른쪽에서 가장 가까운 사대
	auto right_iter = lower_bound(shooter.begin(), shooter.end(), animal_x);
	int right_x = right_iter != shooter.end() ? *right_iter : 2000000000;

	// 왼쪽에서 가장 가까운 사대
	auto left_iter = upper_bound(shooter.begin(), shooter.end(), animal_x);
	int lower_x = left_iter != shooter.begin() ? *(--left_iter) : -2000000000;

	// 둘 중 가까운 곳과의 거리
	int dx = min(right_x - animal_x, animal_x - lower_x);

	return animal_y <= l - dx;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> l;

	// 사대 입력받기
	int input;
	for (int i = 0; i < m; i++) {
		cin >> input;
		shooter.push_back(input);
	}

	sort(shooter.begin(), shooter.end());

	// 동물 입력받으면서 잡을 수 있는지 계산
	int animal_x, animal_y;
	int catch_count = 0;
	for (int i = 0; i < n; i++) {
		cin >> animal_x >> animal_y;

		if (isCatchable(animal_x, animal_y)) {
			catch_count++;
		}
	}

	cout << catch_count << endl;
}


// 배열 길이 초과
//int m, n, l;
//vector<int> shooter_x;
//vector<int> shooter_range(1000000001, 0);
//
//
//void updateShooterRange(int x, int from) {
//	for (int dx = from - x; dx < l; dx++) {
//		shooter_range[x + dx] = l - abs(dx);
//	}
//}
//
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> m >> n >> l;
//
//	// 사대 입력받기
//	int input;
//	for (int i = 0; i < m; i++) {
//		cin >> input;
//		shooter_x.push_back(input);
//	}
//
//	sort(shooter_x.begin(), shooter_x.end());
//
//	// 사대 위치별 사거리 계산하기
//	int before_x = shooter_x[0];
//	updateShooterRange(shooter_x[0], 1);
//
//	for (int i = 1; i < shooter_x.size(); i++) {
//		auto& x = shooter_x[i];
//
//		bool is_overlapped = x - before_x < 2 * (l - 1);
//		int from = is_overlapped ? (x + before_x + 1) / 2 : x - l;
//		updateShooterRange(x, from);
//		before_x = x;
//	}
//
//	// 동물 입력받으면서 잡을 수 있는지 계산
//	int animal_x, animal_y;
//	int catch_count = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> animal_x >> animal_y;
//
//		if (animal_y <= shooter_range[animal_x]) {
//			catch_count++;
//		}
//	}
//
//	cout << catch_count << endl;
//}
