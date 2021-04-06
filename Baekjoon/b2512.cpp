#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <cmath>
#include <cstring>
using namespace std;

#define endl "\n"
#define ends " "
#define mk_p(x,y) make_pair((x), (y))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef unsigned long long ull;

const int MOD = 1000000000; // PLZ check
const ll LMOD = 1000000000;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1);
const double eps = 1e-10;
const pii dxdy[] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

enum NextFind {
	EQ_FIND_MAX,		// 찾는 타겟이지만 최댓값을 찾는 경우
	EQ_FIND_MIN,		// 찾는 타겟이지만 최솟값을 찾는 경우
	NEQ_FIND_MAX,		// 찾는 타겟이 아니고 최댓값을 찾는 경우
	NEQ_FIND_MIN,		// 찾는 타겟이 아니고 최솟값을 찾는 경우
};

template<class T>
using TestFunc = NextFind (*)(const T&);


template<class T>
int parametric_search(vector<T>& list, TestFunc<T> test, int left, int right) {
	if (left > right) return -1;

	int mid = (left + right) / 2;
	switch (test(mid)) {
	case EQ_FIND_MAX: {
		int upper_result = parametric_search(list, test, mid + 1, right);
		return upper_result != -1 ? upper_result : mid;
	}
	case EQ_FIND_MIN: {
		int lower_result = parametric_search(list, test, left, mid - 1);
		return lower_result != -1 ? lower_result : mid;
	}
	case NEQ_FIND_MAX:
		return parametric_search(list, test, left, mid - 1);
	case NEQ_FIND_MIN:
		return parametric_search(list, test, mid + 1, right);
	}
}


int N, M;
vector<int> requests;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		requests.push_back(input);
	}

	cin >> M;

	sort(requests.begin(), requests.end());

	int left = 1;
	int right = requests.back();
	auto test = [](const int& target) {
		ll sum = 0;
		for (auto request : requests) {
			sum += min(request, target);
		}

		if (sum <= M)
			return EQ_FIND_MAX;
		else
			return NEQ_FIND_MAX;
	};
	cout << parametric_search<int>(requests, test, 1, right) << endl;
}
