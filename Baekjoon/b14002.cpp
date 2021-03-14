#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> seq;
vector<vector<int>> partial_inc_seq_list;


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		seq.push_back(input);
	}

	for (int i = 0; i < n; i++) {
		int current = seq[i];
		int max_length = 0;
		int max_index = -1;

		for (int j = 0; j < i; j++) {
			auto& partial_inc_seq = partial_inc_seq_list[j];

			if (current <= partial_inc_seq.back()) continue;
			if (max_length >= partial_inc_seq.size()) continue;

			max_length = partial_inc_seq.size();
			max_index = j;
		}

		if (max_index == -1) {
			auto v = vector<int>();
			v.push_back(current);
			partial_inc_seq_list.push_back(v);
		}
		else {
			auto v = partial_inc_seq_list[max_index];
			v.push_back(current);
			partial_inc_seq_list.push_back(v);
		}
	}

	int max_length = 0;
	int max_index;
	for (int i = 0; i < partial_inc_seq_list.size(); i++) {
		auto& partial_inc_seq = partial_inc_seq_list[i];

		if (max_length >= partial_inc_seq.size()) continue;
		max_length = partial_inc_seq.size();
		max_index = i;
	}

	auto& max_partial_inc_seq = partial_inc_seq_list[max_index];
	cout << max_partial_inc_seq.size() << endl;
	for (int i = 0; i < max_partial_inc_seq.size(); i++) {
		cout << max_partial_inc_seq[i] << " ";
	}
	cout << endl;
}