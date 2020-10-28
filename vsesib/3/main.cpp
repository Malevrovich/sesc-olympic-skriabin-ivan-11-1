#include <bits/stdc++.h>

using namespace std;

#define ll uint64_t

vector<int> cin_vector(int n){
	vector<int> a(n);
	for(auto &i: a){
		cin >> i;
	}
	return a;
}

vector<int64_t> z_func(const string &s) {
	vector<int64_t> z(s.size(), 0);
	int64_t l = 0, r = 0;
	for (int i = 1; i < s.size(); i++) {
		if (i <= r) {
			z[i] = min(z[i - l], r - i + 1);
		}
		while (z[i] + i < s.size() && s[z[i]] == s[z[i] + i]) {
			z[i]++;
		}
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

int64_t count(const string& where, const string& s){
	string tmp = s + "&" + where;
	vector<int64_t> z = z_func(tmp);

	int result = 0;
	for(int64_t i = s.size() + 1; i != tmp.size(); i++){
		if(z[i] >= s.size()){
			result++;
		}
	}

	return result;
}

void solve(){
	string num;
	cin >> num;
	int64_t m;
	cin >> m;
	int64_t result = 0;

	map<string, int64_t> counts = map<string, int64_t>();

	for(int i = 0; i != m; i++){
		string f;
		int64_t cost;
		cin >> f >> cost;
		if(counts.find(f) == counts.end()){
			counts[f] = count(num, f);
		}
		result += counts[f] * cost;
	}
	cout << result << endl;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t = 1;
//	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
