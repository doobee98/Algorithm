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

const int MOD = 1000000007; // PLZ check
const ll LMOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1);
const double eps = 1e-10;
const pii dxdy[] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };


int n, l, p;
vector<pii> gases;
priority_queue<int> fuels;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		gases.emplace_back(a, b);
	}

	cin >> l >> p;

	sort(gases.begin(), gases.end());

	int count = 0;
	int reachable = p;
	int i = 0;			// ť�� ���� ������ �ε��� �����

	while (reachable < l) {
		// ���� ������ �� �ִ� �����ҵ� ť�� �ֱ�
		while (i < n && gases[i].first <= reachable) {
			auto [x, fuel] = gases[i];
			fuels.push(fuel);
			i++;
		}

		// ���� ������ ���� �� ������ ����
		if (fuels.empty()) {
			count = -1;
			break;
		}
		
		// ť�� ���� �������� ���ᷮ ���� ���� �� pop
		int max_fuel = fuels.top(); fuels.pop();
		reachable += max_fuel;
		count++;
	}

	cout << count << endl;
}
