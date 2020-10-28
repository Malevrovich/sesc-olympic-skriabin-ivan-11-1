#include <bits/stdc++.h>

using namespace std;

#define ll uint64_t

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> nums_x(n * m);
	vector<int> nums_y(n * m);

	for (int i = 0; i != n; i++) {
		vector<int> nums(m);

		for (auto &k : nums) {
			cin >> k;
		}

		for (int k = 0; k != m; k++) {
			nums_x[nums[k]] = k;
		}
	}

	for (int i = 0; i != m; i++) {
		vector<int> nums(n);
		for (auto &k : nums) {
			cin >> k;
		}

		for (int k = 0; k != n; k++) {
			nums_y[nums[k]] = k;
		}
	}

	vector<vector<int>> map(n, vector<int>(m, 0));
	for (int i = 1; i != n * m + 1; i++) {
//		cout << nums_x[i] << ' ' << nums_y[i] << ' ' << map.size() << ' ' << map[0].size() << endl;
		map[nums_y[i]][nums_x[i]] = i;
	}

	for(int i = 0; i != n; i++){
		for(int k = 0; k != m; k++){
			cout << map[i][k] << ' ';
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
