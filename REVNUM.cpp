#include<iostream>
#include<vector>
#include<math.h>
using namespace std ;

int rev(int n) {
	std::vector<int> v;

	while (n > 0) {

		int x = n % 10 ;
		v.push_back(x) ;
		n = n / 10 ;
	}

	int l = v.size() ;

	int num = 0 ;

	for (int i = 0; i < l; i++)
	{
		num = (num + ((v[i]) * (pow(10.0, (l - i - 1)))));

	}

	return num ;
}



int main() {





	int y ;
	cin >> y ;
	while (y--)
	{
		int n1, n2 ;
		cin >> n1 >> n2 ;

		int ans1 = rev(n1) ;
		int ans2 = rev(n2) ;
		int k = ans1 + ans2 ;
		int ans3 = rev(k) ;
		cout << ans3 << "\n" ;
	}

}