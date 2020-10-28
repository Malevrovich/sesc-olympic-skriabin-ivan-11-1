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
     
    int num(int n, int k){
    	if(n % (k + 1) == 0){
    		return n / (k + 1);
    	}
    	return (n / (k + 1)) + 1;
    }
     
    void solve() {
    	int n, k;
    	cin >> n >> k;
    	vector<bool> s(n);
    	vector<int> poss;
    	string tmp;
    	cin >> tmp;
    	for (int i = 0; i != n; i++) {
    		int a = tmp[i] - '0';
    		if (a == 1) {
    			poss.push_back(i);
    		}
    		s[i] = a;
    	}
    	for (int p : poss) {
    		int size = s.size();
    		for (int i = p - k; i <= p + k && i < size; i++) {
    			if(i < 0){
    				continue;
    			}
    			s[i] = true;
    		}
    	}
    	int result = 0;
    	int cur = 0;
    	for(int i = 0; i != s.size(); i++){
    		if(s[i]){
    			result += num(cur, k);
    			cur = 0;
    		} else{
    			cur += 1;
    		}
    	}
    	result += num(cur, k);
    	cout << result << endl;
    }
     
    int main() {
    	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    	int t;
    	cin >> t;
    	while (t--) {
    		solve();
    	}
    	return 0;
    }
