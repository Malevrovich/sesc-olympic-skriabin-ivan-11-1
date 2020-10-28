#include <bits/stdc++.h>

using namespace std;

#define ll uint64_t

void solve(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for(auto& i: nums){
		cin >> i;
	}
	vector<int> result(n);
	for(int i = 0; i != n; i++){
		if(i >= n/2){
			result[i] = nums[n - i - 1];
		} else{
			result[i] = -1 * nums[n - i - 1];
		}
	}
	for(auto i: result){
		cout << i << ' ';
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
