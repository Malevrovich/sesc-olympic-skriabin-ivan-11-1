#include <bits/stdc++.h>

using namespace std;

#define ll uint64_t
#define mod 1000'000'009

vector<int> cin_vector(int n) {
	vector<int> a(n);
	for (auto &i : a) {
		cin >> i;
	}
	return a;
}

// ~60 баллов

/*

3 2 2
+ 3 x
2 1
3 1
2
3

 */

/*

10 9 2
* + 1 3 2 + + 10 3 2
3 2
4 2
5 2
2 1
8 7
9 7
7 6
10 6
6 1
1
23

90
90

 */

/*
5 6 1
+ + * x 3
2 1
3 1
4 2
4 3
3 2
5 3
2
 */

int64_t count_with_x(const vector<int64_t> &values,
		const vector<vector<int>> &dependence, const vector<string> &types,
		int n, int x) {
	int64_t val = 0;


//	cout << types[n] << endl;

	if (values[n] != -1) {
		return values[n];
	}

	if (types[n] == "x") {
		return x;
	} else if (types[n] != "+" && types[n] != "*") {
		return values[n];
	}

	for (int i : dependence[n]) {
		if (values[i] != -1) {
			if (types[n] == "+") {
				val += values[i];
				val %= mod;
			} else if (types[n] == "*") {
				if (val == 0) {
					val = values[i];
				} else {
					val *= values[i];
					val %= mod;
				}
			}
//			cout << val << ' ';
		} else {
			int64_t tmp = count_with_x(values, dependence, types, i, x) % mod;

			if (types[n] == "+") {
				val += tmp;
				val %= mod;
			} else if (types[n] == "*") {
				if (val == 0) {
					val = tmp;
				} else {
					val *= tmp;
					val %= mod;
				}
			}
//			cout << val << ' ';
		}
	}
	return val;
}

int64_t count_values(vector<int64_t> &values,
		const vector<vector<int>> &dependence, const vector<string> &types,
		int n) {
	int64_t val = 0;
	bool is_bad = false;
//	cout << n << endl;

	if (values[n] != -1) {
		return values[n];
	}

	if (types[n] == "x") {
		values[n] = -1;
		return -1;
	} else if (types[n] != "+" && types[n] != "*") {
		values[n] = stoll(types[n]);
		return values[n];
	}

	for (auto i : dependence[n]) {
		if (values[i] != -1) {
			if (types[n] == "+") {
				val += values[i];
				val %= mod;
			} else if (types[n] == "*") {
				if (val == 0) {
					val = values[i];
				} else {
					val *= values[i];
					val %= mod;
				}
			}
		} else {
			int64_t tmp = count_values(values, dependence, types, i) % mod;
			if (tmp == -1) {
				is_bad = true;
			} else {
				if (types[n] == "+") {
					val += tmp;
					val %= mod;
				} else if (types[n] == "*") {
					if (val == 0) {
						val = tmp;
					} else {
						val *= tmp;
						val %= mod;
					}
				}
			}
		}
	}

	if (is_bad) {
		val = -1;
	}
	values[n] = val;
	return val;
}

void solve() {
	int n, m, q;

	cin >> n >> m >> q;
	vector<string> types = vector<string>(n);
	for (int i = 0; i != n; i++) {
		cin >> types[i];
	}

	vector<vector<int>> dependence = vector<vector<int>>(n, vector<int>());
	for (int i = 0; i != m; i++) {
		int src, dst;
		cin >> src >> dst;
		src--;
		dst--;
		dependence[dst].push_back(src);
	}

	vector<int64_t> values = vector<int64_t>(n, -1);

	vector<bool> is_start = vector<bool>(n, true);
	for (auto i : dependence) {
		for (auto k : i) {
			is_start[k] = false;
		}
	}

	int start = -1;
	for (int i = 0; i != n; i++) {
		if (is_start[i]) {
			start = i;
			break;
		}
	}

	count_values(values, dependence, types, start);

	for (int i = 0; i != q; i++) {
		int tmp;
		cin >> tmp;
		cout << count_with_x(values, dependence, types, start, tmp) % mod << endl;
	}

//	for(auto i: values){
//		cout << i << ' ';
//	}
//	cout << endl;

}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
