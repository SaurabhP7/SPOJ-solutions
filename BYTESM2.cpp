#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

/*
Few points to consider - 
1)-Use c++ not java, input format works fine for cpp.
2)-Normal recursion gives TLE,  memoization with recursion gets AC.
3)-While using DP, handle the indices of DP array correctly (should not be less  than 0 or greater than n-1 or m-1.
4)-Some Test Cases-

1
3 3
0 0 3
0 2 0
1 0 0 
output- 6 

1
1 5
1 2 3 4 5
output-5

1
5 1 
1 2 3 4 5 
output-15
*/

int m,n=0 ;
int maxAns(int n1,int n2,int n3)
{
	int q=0 ;	
if(n1 >= n2 && n1 >= n3)
    {
        q=n1;
    }

    else if(n2 >= n1 && n2 >= n3)
    {
         q=n2;
    }

    else if(n3 >= n1 && n3 >= n2) {
       	q=n3;
    }
return q ;
}
int findMaxPath(int a[][100],int m,int n ,int sx,int sy,int memo[][100])
{
	if(memo[sx][sy]!=-1)
		return memo[sx][sy] ;
	 

	if(sx<0||sx>=m||sy<0||sy>=n)
		return 0 ;

	int x,y,z ;

	if(sy>=1&&sx<m-1)
	 	x=findMaxPath(a,m,n,sx+1,sy-1,memo);
	else 
		x=0 ; 	
	
	if(sx<m-1)
		y=findMaxPath(a,m,n,sx+1,sy,memo);  
	else
		y=0 ;

	if(sy<n-1&&sx<m-1)
	 	z=findMaxPath(a,m,n,sx+1,sy+1,memo);  
	else
		z=0 ;
	
	 memo[sx][sy]=maxAns(x,y,z)+a[sx][sy] ;
	 return memo[sx][sy] ;
}


void solve(){




	cin>>m>>n; 

	int a[m][100] ;

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j] ;
		}
	} 

	int ans=-1 ;
	int max=-1 ;


	int memo[m][100] ;
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			memo[i][j]=-1  ;
		}
	} 
	
	for(int i=0;i<n;i++){

	 ans=findMaxPath(a,m,n,0,i,memo) ;
	 //cout<<ans<<"\n" ;
	 if(ans>max)
	 	max=ans ;
	}

	cout<<max<<"\n" ;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	int y ;
	//y=1 ;
	cin>>y ;
	while(y--){
		solve() ;
	}
	
}