#include<iostream>
#include<vector>
using namespace std ;

int main() {




	vector<float> v ;
	float x;
	cin >> x ;
	while (x != 0.00)
	{
		v.push_back(x) ;
		cin >> x ;
	}

	int l = v.size() ;
	vector<int> ans ;

	for (int i = 0; i < l; i++) {
		float sum = 0.0 ;
		float c = 2.0;
		while (sum <= v[i])
		{
			sum = sum + (1.0 / c) ;
			c++ ;
		}
		ans.push_back(c - 2) ;
	}

	for (int k = 0; k < ans.size(); k++) {
		cout << ans[k] << " card(s)" << "\n" ;
	}

}