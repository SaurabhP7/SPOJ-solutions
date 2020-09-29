#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;


string add(string &s){

	int carry=0 ;
	string ans(s.size()+1,'0') ;
	int m=s.size() ;
	for(int i=m-1;i>=0;i--){
		int num=0 ;
		
		if(i==m-1){
			num=1 ;
		}
		int sum=(s[i]-'0')+carry+num ;
		s[i]=sum%10 +'0' ;
		carry=sum/10 ; 
		num=0 ;


	}
	if(carry==1){
		s='1'+s ;

	}

	return s ;
}


string multiply(string &num1,string &num2){
	

	int l1=num1.size() ;
	int l2=num2.size() ;
	string str(l1+l2,'0') ;

	for(int i=l1-1;i>=0;i--){

		for(int j=l2-1;j>=0;j--){

			int p=(num1[i]-'0')*(num2[j]-'0')+ (str[i+j+1]-'0') ;
			str[i+j+1]=p%10 +'0' ;
			str[i+j]+=p/10 ;

		}


	}

	for(int i=0;i<l1+l2;i++){
		if(str[i]!='0'){
			return str.substr(i) ;
		}
	}
	return "0" ;

}

string factorial(string &s){

	string s1="1" ;
	string ans="1" ;
	string c=add(s) ;
	while(s1!=c){
		ans=multiply(s1,ans) ;
		s1=add(s1) ;
		
	}
	return ans ;
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	
/*
	char a='0' ;
	a=a+1 ;
	cout<<a<<"\n" ;
	cout<<typeid(a).name() ;
*/
	//cout<<ans ;
int t ;
cin>>t ;
int count =0 ;

	while(count<t){
		string s ;
		cin>>s ;
		string ans=factorial(s) ;
		cout<<ans<<"\n" ;
		count++ ;
	}
}