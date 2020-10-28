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

void solve(){
	int64_t n;
	cin >> n;
	int64_t result = 0;
	result += n / 200;
	n %= 200;
	result += n / 40;
	n %= 40;
	result += n / 10;
	n %= 10;
	result += n / 5;
	n %= 5;
	result += n;
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
