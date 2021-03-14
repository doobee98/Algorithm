#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n;
vector<pair<int, int>> lines;


int main() {
	// ** ���ͳ� �����Ͽ� �߰�
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int front, back;
		cin >> front >> back;

		lines.push_back(make_pair(front, back));
	}

	sort(lines.begin(), lines.end());

	int total_front = lines[0].first;
	int total_back = lines[0].second;
	int total_length = total_back - total_front;

	for (int i = 1; i < lines.size(); i++) {
		int front = lines[i].first;
		int back = lines[i].second;

		// ���ο� ������ ���� ���ο� ���ԵǴ� ���
		if (total_front <= front && back <= total_back)
			continue;

		// ��ġ�� ������ �ִ� ���
		else if (front <= total_back) {
			total_length += (back - front) - (total_back - front);
			total_back = back;
		}

		// �ƿ� ���� ������ ���
		else {
			total_length += back - front;
			total_back = back;
		}
	}

	cout << total_length << endl;
}


// Ʋ�Ƚ��ϴ�, �� ������ ������ �߰���
//int main() {
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		int front, back;
//		cin >> front >> back;
//
//		int front_idx = -1;
//		int back_idx = -1;
//
//		for (int j = 0; j < lines.size(); j++) {
//			auto line = lines[j];
//
//			if (front_idx == -1 && front <= line.second) {
//				front_idx = j;
//				front = min(front, line.first);
//				back_idx = front_idx;
//			}
//
//			if (front_idx != -1 && back >= line.first) {
//				back_idx = j;
//				back = max(back, line.second);
//				break;
//			}
//		}
//
//		if (front_idx == -1) {
//			lines.push_back(make_pair(front, back));
//			continue;
//		}
//
//		// front_idx�� back_idx ������ �ֵ� ���� �� �ֱ�
//		lines.erase(lines.begin() + front_idx, lines.begin() + back_idx + 1);
//		lines.insert(lines.begin() + front_idx, make_pair(front, back));
//	}
//
//	int total_length = 0;
//
//	for (int i = 0; i < lines.size(); i++) {
//		auto line = lines[i];
//		total_length += line.second - line.first;
//	}
//
//	cout << total_length << endl;
//}