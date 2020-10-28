#include <iostream>

using namespace std;



int main(){
	int t;
	cin >> t;
	while(t--){
		int h, v, m;
		cin >> h >> v >> m;

		while(v--){
			if(h <= 20){
				break;
			}
			h = h / 2 + 10;
		}

		while(m--){
			h -= 10;
			if(h <= 0){
				break;
			}
		}

		if(h <= 0){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}




