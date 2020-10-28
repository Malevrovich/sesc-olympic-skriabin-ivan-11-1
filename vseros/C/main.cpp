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

void solve(int h, int m){
//	int h, m;
//	cin >> h >> m;

	int need = (h % 10) * (h / 10);

	for(int i = 0; i != 60; i++){
		int tmp = (m + i) % 60;
		if((tmp % 10) * (tmp / 10) == need){
//			cout << i << endl;
			return;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t = 1;
	cin >> t;
	srand(time(NULL));
	while(t--){
		int h = rand() % 24;
		int m = rand() % 59;
//		cout << "INPUT: " << h << ' ' << m << endl;
		solve(h, m);
//		cout << endl;
	}
	return 0;
}
