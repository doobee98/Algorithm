#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int n;
vector<int> cups;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		cups.push_back(input);
	}

	sort(cups.begin(), cups.end(), [](int cup1, int cup2) {
		return abs(cup1) < abs(cup2);
	});

	int min_mixed = 2000000001;
	int min_cup1, min_cup2;
	for (int i = 0; i < n - 1; i++) {
		int cup1 = cups[i];
		int cup2 = cups[i + 1];
		int mixed = abs(cup1 + cup2);

		if (min_mixed > mixed) {
			min_mixed = mixed;
			min_cup1 = cup1;
			min_cup2 = cup2;

			if (mixed == 0) break;
		}
	}

	if (min_cup1 > min_cup2) swap(min_cup1, min_cup2);

	cout << min_cup1 << " " << min_cup2 << endl;
}
