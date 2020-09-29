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
string reverseStr(string& str) 
{ 
    int n = str.length(); 
  
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 

    return str ;
} 
  
void copyPaste(string &s,int i,int j){

	for(int k=i;k>=0;k--){
		s[j]=s[k] ;
		j++ ;
	}
	cout<<s<<"\n" ;
}

void addAndMirror(string &q,int z){

	string s1=add(q) ;
	int n=s1.size() ;
	string s4=s1 ;
    string s2=reverseStr(s4) ;
string s3 ;
if(z==0)
	 s3=s1+s2 ;
else{
	
	string s5=s2.substr(1) ;

	s3=s1+s5 ;

}
	cout<<s3<<"\n" ;

}

void forEvenString(string &s){
	int z=0 ;
	int n=s.size() ;

	int i=(n/2)-1 ;
	int j=(n/2) ;

	int flag=0;
	
	while(i>=0 && j<=n-1){


		if(s[i]==s[j]){
			i-- ;
			j++ ;
		}
		else{
			flag++ ;
			int a=s[i]-'0' ;
			int b=s[j]-'0' ;


			if(a<b){
				string r=s.substr(0,n/2); 
				addAndMirror(r,z) ;
				return ;
			}
			else{
				copyPaste(s,i,j) ;
				return ;
			}
		}
	}

	if(flag==0&&i<0&&j>n-1){
		string r=s.substr(0,n/2) ;

		addAndMirror(r,z) ;
		return ;
	}


}

void forOddString(string &s){
	int z=1 ;
	int n=s.size() ;
	int j=n/2 ;
	int i=n/2 ;
	
	int flag=0;
	
	while(i>=0 && j<=n-1){


		if(s[i]==s[j]){
			i-- ;
			j++ ;
		}
		else{
			flag++ ;
			int a=s[i]-'0' ;
			int b=s[j]-'0' ;


			if(a<b){
		
				string m=s.substr(0,(n/2)+1) ;
				
				addAndMirror(m,z) ;
				return ;
			}
			else{
				copyPaste(s,i,j) ;
				return ;
			}
		}


		}

	if(flag==0&&i<0&&j>n-1){
		string r=s.substr(0,(n/2)+1) ;

		addAndMirror(r,z) ;
		return ;
	}	


}


void traverse(string &s){

	int a=s.size() ;

	if(a%2==0){

		forEvenString(s) ;

	}
	else
	{
		forOddString(s) ;
	}
	

}

bool ifAll9(string &s){

	bool flag=0 ;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='9'){
			flag=1 ;
		}
	}
	if(flag==0)
    {   string a1=add(s) ;
	    string a2=add(a1) ;
		cout<<a2<<"\n" ; 
		return 1 ;
	}
	
	return 0 ;
}

void findPalin(string &s){

	bool m=ifAll9(s) ;
	if(m==0)
		traverse(s) ;

	
}
void ifAll0(string &s){

	bool flag=0 ;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='0'){
			flag=1 ;
		}
	}
	if(flag==0)
    {   
    	cout<<"1" ;
    	return ;
	}
	
}

void solve(){

	string s ;
	cin>>s ;
	ifAll0(s) ;

	string s2 ;
	for(int i=0;i<s.size();i++){
		if(s[i]!='0'){
			 s2=s.substr(i) ;
			 break ;
		}
	}
	findPalin(s2) ;
 

}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	
int y ;

cin>>y ;
//y=1;
while(y--){
	solve() ;
}

}