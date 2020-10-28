#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<bool>> matrix(n, vector<bool>(m));
		for (int i = 0; i != n; i++) {
			for (int k = 0; k != m; k++) {
				int a;
				cin >> a;
				matrix[i][k] = (a == 1);
			}
		}
		int result = 0;
		for (int j = 1; j <= (n + m - 1) / 2; j++) {
			int t = 0, f = 0;
			for (int i = 0; i != j; i++) {
				int k = j - i - 1;
				if (i < n && k < m && n - i - 1 < n && m - k - 1 < m) {
					if (matrix[i][k]) {
						t++;
					} else {
						f++;
					}
					if (matrix[n - i - 1][m - k - 1]){
						t++;
					} else{
						f++;
					}
				}
			}
			result += min(t, f);
		}
		cout << result << endl;
	}
	return 0;
}
