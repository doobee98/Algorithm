#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m, n, l;
vector<int> shooter;


bool isCatchable(int animal_x, int animal_y) {
	// �ִ� �Ÿ����� �ָ� ������ �ٷ� �ƿ�
	if (animal_y > l) return false;

	// �����ʿ��� ���� ����� ���
	auto right_iter = lower_bound(shooter.begin(), shooter.end(), animal_x);
	int right_x = right_iter != shooter.end() ? *right_iter : 2000000000;

	// ���ʿ��� ���� ����� ���
	auto left_iter = upper_bound(shooter.begin(), shooter.end(), animal_x);
	int lower_x = left_iter != shooter.begin() ? *(--left_iter) : -2000000000;

	// �� �� ����� ������ �Ÿ�
	int dx = min(right_x - animal_x, animal_x - lower_x);

	return animal_y <= l - dx;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> l;

	// ��� �Է¹ޱ�
	int input;
	for (int i = 0; i < m; i++) {
		cin >> input;
		shooter.push_back(input);
	}

	sort(shooter.begin(), shooter.end());

	// ���� �Է¹����鼭 ���� �� �ִ��� ���
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


// �迭 ���� �ʰ�
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
//	// ��� �Է¹ޱ�
//	int input;
//	for (int i = 0; i < m; i++) {
//		cin >> input;
//		shooter_x.push_back(input);
//	}
//
//	sort(shooter_x.begin(), shooter_x.end());
//
//	// ��� ��ġ�� ��Ÿ� ����ϱ�
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
//	// ���� �Է¹����鼭 ���� �� �ִ��� ���
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
