#include <bits/stdc++.h>

using namespace std;

#define ull uint64_t

vector<int> cin_vector(int n) {
	vector<int> a(n);
	for (auto &i : a) {
		cin >> i;
	}
	return a;
}

void solve() {
	string s;
	cin >> s;

	int lg = s.size();

	int result = 0;

	for (int i = 1; i != lg / 2; i++) {
		if(s[i] != '0'){
			result++;
		}
	}

	if(s[lg / 2] == '0'){
		cout << result << endl;
		return;
	}

	if(lg % 2 == 1){
		cout << result + 1 << endl;
		return;
	}

	for(int i = 0; i != lg/2; i++){
		if(s[i] > s[i + lg/2]){
			cout << result << endl;
			return;
		} else if(s[i] < s[i + lg/2]){
			cout << result + 1 << endl;
			return;
		}
	}
	cout << result + 1 << endl;
	return;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
