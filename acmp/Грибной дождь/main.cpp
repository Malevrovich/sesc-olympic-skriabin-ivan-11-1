#include <bits/stdc++.h>

//ЗАДАЧА №699
// 30%

using namespace std;

#define ll int64_t
#define ull uint64_t

vector<int> cin_vector(int n){
	vector<int> a(n);
	for(auto &i: a){
		cin >> i;
	}
	return a;
}

struct mushroom{
	int x, y, r;
};

double distance(const mushroom& lhs, const mushroom& rhs){
	return sqrt((lhs.x - rhs.x) * (lhs.x - rhs.x) + (lhs.y - rhs.y) * (lhs.y - rhs.y)) - lhs.r - rhs.r;
}

void solve(){
	double k, t;

	cin >> k >> t;
	vector<mushroom> v = vector<mushroom>(k);

	for(auto& i: v){
		cin >> i.x >> i.y >> i.r;
	}

	double min_dist = 100'000'000;

	for(int i = 0; i < k - 1; i++){
		for(int j = i + 1; j < k; j++){
			min_dist = min(min_dist, distance(v[i], v[j]));
		}
	}

	cout << min(min_dist / 2, t) << endl;
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
