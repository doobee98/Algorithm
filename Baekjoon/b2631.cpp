#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> line;
vector<int> sorted_line;


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		line.push_back(input);
	}

	sorted_line.push_back(line[0]);


	for (int i = 1; i < n; i++) {
		int current = line[i];

		if (current > sorted_line.back()) {
			sorted_line.push_back(current);
		}
		else {
			for (int j = 0; j < sorted_line.size(); j++) {
				if (current < sorted_line[j]) {
					sorted_line[j] = current;
					break;
				}
			}
		}
	}

	int move_count = n - sorted_line.size();
	cout << move_count << endl;
}