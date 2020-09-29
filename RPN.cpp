#include<bits/stdc++.h>
#include<stack>
using namespace std ;
typedef long long ll ;

void solve(){
	
	string s ;
	cin>>s ;
	stack<char> mystack ;


	for(int i=0;i<s.size();i++){

		if(s[i]=='*'||s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='^'||s[i]=='('||s[i]==')'){

			if(s[i]==')'){
				char val=mystack.top() ;
				while(val!='('){

					cout<<mystack.top() ;
					mystack.pop() ;
					val=mystack.top() ;

				}
				mystack.pop() ;
			}
			else{
					mystack.push(s[i]) ;
			}

		}else
		{
			cout<<s[i] ;
		}
	}
	cout<<"\n" ;
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	
int y ;

cin>>y ;

while(y--){
	solve() ;
}


}