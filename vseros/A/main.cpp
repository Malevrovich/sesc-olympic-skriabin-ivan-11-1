#include <bits/stdc++.h>

using namespace std;

#define ll uint64_t

vector<int> cin_vector(int n) {
	vector<int> a(n);
	for (auto &i : a) {
		cin >> i;
	}
	return a;
}

void solve(int64_t n, int64_t x, int64_t a, int64_t y, int64_t b) {
//	int64_t n, x, a, y, b;
//	cin >> n >> x >> a >> y >> b;
	cout << max((n - x) * a, (n - y) * b) << endl;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t = 1;
	cin >> t;
	srand(time(NULL));
	while (t--) {
		int64_t n = rand() % 1'000'000;
		while (n == 0) {
			n = rand() % 1'000'000;
		}
		int64_t x = rand() % n;
		int64_t y = rand() % n;
		int64_t a = rand() % 1000;
		while (a == 0) {
			a = rand() % 1000;
		}
		int64_t b = rand() % 1000;
		while (b == 0) {
			b = rand() % 1000;
		}
		cout << "INPUT: " << n << ' ' << x << ' ' << a << ' ' << y << ' ' << b << endl;
		solve(n, x, a, y, b);
		cout << endl;
	}
	return 0;
}
