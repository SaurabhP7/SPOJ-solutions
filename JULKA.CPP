#include<bits/stdc++.h>
using namespace std ;
typedef vector<int> lnum ;
const int base=1000*1000*1000 ;


lnum inputNum(string s1){

	lnum a ;

	//INPUT LARGE NUMBER
	for(int i=(int)s1.length();i>0;i=i-9){
		if(i<9){
			a.push_back(atoi(s1.substr(0,i).c_str())) ;
		}
		else
		{
			a.push_back(atoi(s1.substr(i-9,9).c_str())) ;
		}
	}
	
	//REMOVE LEADING ZEROES
	while(a.size()>1 && a.back()==0){
		a.pop_back() ;
	}

	return a ;

}

void outputNum(lnum a){

	//OUTPUT THE LARGE NUMBER
	printf("%d",a.empty()?0:a.back()) ;

	for(int i=(int)a.size()-2;i>=0;--i)
	{
		printf("%09d",a[i]) ;
	}

}

//ADD 2 LARGE NUMBERS
lnum addition(lnum a,lnum b){

	int carry=0 ;

	for(size_t i=0;i<max(a.size(),b.size())||carry;++i)
	{
		if(i==a.size()){
			a.push_back(0) ;
		}

	a[i]+=carry+(i<b.size()?b[i]:0) ;
	carry=a[i]>=base ;
	if(carry){
		a[i]-=base ;
	}

	}

	return a ;
}

//SUBSTRACT 2 LARGE NUMBERS
lnum substract(lnum a,lnum b){

	int carry=0 ;
	for(size_t i=0;i<a.size()||carry;++i){

		a[i]-=carry+(i<b.size()?b[i]:0) ;

		carry=a[i]<0 ;
		if(carry){
			a[i]+=base ;
		}
	}
	
	while(a.size()>1 && a.back()==0){
		a.pop_back() ;
	}

	return a ;
}

//DIVIDE A BY SMALL NUMBER
lnum divide(lnum a,int b){

	int carry=0 ;

	for(int i=a.size()-1;i>=0;i--){

		long long curr=a[i]+carry*1ll*base ;
		a[i]=int(curr/b) ;
		carry=int(curr%b) ;

	}

	while(a.size()>1 && a.back()==0){
		a.pop_back() ;
	}

	return a ;
}


void solve(int count){

	string s1,s2;
	cin>>s1 ;
	cin>>s2 ;

	for(int i=0;i<s1.length();i++){
		if(s1[i]!='0'){
			s1=s1.substr(i) ;
			break ;
		}
	}

	for(int i=0;i<s2.length();i++){
		if(s2[i]!='0'){
			s2=s2.substr(i) ;
			break ;
		}
	}


	lnum a=inputNum(s1) ;
	lnum b=inputNum(s2) ;

	lnum ans=addition(a,b) ;
	lnum ans1=divide(ans,2) ;
	lnum ans2=substract(a,ans1) ;

	outputNum(ans1) ;
	cout<<"\n" ;
	outputNum(ans2) ;
	if(count<10) 
	cout<<"\n" ;

}	


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	
	int count=1 ;

	while(count<=10){

		solve(count) ;
		count++ ;
	}

	return 0 ;
}