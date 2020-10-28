#include <bits/stdc++.h>

using namespace std;

#define ll uint64_t

vector<int64_t> cin_vector(int n) {
	vector<int64_t> a(n);
	for (auto &i : a) {
		cin >> i;
	}
	return a;
}

//int64_t n, int64_t k, const vector<int64_t> &v
void solve() {
	int64_t n, k;
	cin >> n >> k;
	vector<int64_t> v = cin_vector(n);

	int64_t cur = 0;

	for (int64_t i = 0; i != k; i++) {
		cur += v[i];
	}
	int64_t mx = cur;
	int64_t mx_ind = 0;

	int l = 0;
	int r = k;
//	cout << l << ' ' << r << ' ' << cur << endl;
	while (r != n) {
		cur -= v[l];
		l++;
		cur += v[r];
		r++;
//		cout << l << ' ' << r << ' ' << cur << endl;
		if (cur > mx) {
			mx_ind = l;
			mx = cur;
		}
	}

	cout << mx_ind + 1 << endl;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t = 1;
//	cin >> t;
	srand(time(NULL));
	while (t--) {
//		int64_t n = rand() % 20;
//		while (n == 0) {
//			n = rand() % 20;
//		}
//		int64_t k = rand() % n;
//		while (k == 0) {
//			k = rand() % n;
//		}
//		vector<int64_t> v = vector<int64_t>(n);
//		for (int i = 0; i != n; i++) {
//			v[i] = rand() % 100;
//			while (v[i] == 0) {
//				v[i] = rand() % 100;
//			}
//		}
//		cout << "INPUT: " << n << ' ' << k << endl;
//		for(auto i : v){
//			cout << i << ' ';
//		}
//		cout << endl;
//		solve(n, k, v);
//		cout << endl;
		solve();
	}
	return 0;
}
