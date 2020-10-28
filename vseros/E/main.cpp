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
	int64_t a, n, m;
	cin >> a >> n >> m;
	if(a == n * m){
		cout << "YES" << endl;
		for(int i = 0; i != n; i++){
			for(int k = 0; k != m; k++){
				cout << ".";
			}
			cout << endl;
		}
		return;
	}

	for(int x = 1; x != n + 1; x++){
		for(int y = 1; y != m + 1; y++){
			if((m - x) * (n - y) == a){
				cout << "YES" << endl;
				for(int i = 0; i != n; i++){
					for(int k = 0; k != m; k++){
						if(k < x && i < y){
							cout << "R";
						} else{
							cout << ".";
						}
					}
					cout << endl;
				}
				return;
			}
		}
	}
	cout << "NO" << endl;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t = 1;
//	cin >> t;
	srand(time(NULL));
	while(t--){
//		int n = rand() % 100;
//		while(n == 0){
//			n = rand() % 100;
//		}
//		int m = rand() % 100;
//		while(m == 0 || (m == 1 && n == 1)){
//			m = rand() % 100;
//		}
//		int a = rand() % (n * m);
//		while(a == 0){
//			a = rand() % (n * m);
//		}
//		cout << "INPUT : " << a << ' ' << n << ' ' << m << endl;
//		solve(a, n, m);
//		cout << endl;
		solve();
	}
	return 0;
}

/*
..............................................................
 */
