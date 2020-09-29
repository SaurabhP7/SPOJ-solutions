#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
void addEdge(vector<vector<int>> &adj,int u,int v){

	adj[u].push_back(v) ;
	adj[v].push_back(u) ;

}

vector<bool> segmentedSieve(int L, int R) {
   

	vector<int> primes ;

	//upto R ,prime numbers
	int lim=sqrt(R) ;
	
	vector<bool> marked(lim+1,false) ;
	
	for(int i=2;i<=lim;++i){
		if(!marked[i])
		{	primes.emplace_back(i) ;	
			for(int j=i*i;j<=lim;j=j+i){
				marked[j]=true ;
			}
		}
	}

	vector<bool> isPrime(R-L+1,true) ;

	for(ll i:primes)
	{
		for(int j=max(i*i,((L+i-1)/i)*i);j<=R;j=j+i){
			isPrime[j-L]=false ;
		}

	}

	return isPrime ;


}

bool differBy1(int a,int b){
   
    string s1 = to_string(a); 
    string s2 = to_string(b); 
    int c = 0; 
    if (s1[0] != s2[0]) 
        c++; 
    if (s1[1] != s2[1]) 
        c++; 
    if (s1[2] != s2[2]) 
        c++; 
    if (s1[3] != s2[3]) 
        c++; 
  

    return (c == 1); 
}


int BFS(int a,int b,vector<vector<int>> &adj,int n){


	vector<int> d(n) ;
	vector<int> p(n) ;

	vector<bool> used(n) ;
	queue<int> q ;

	for(int i=0;i<n;i++){
		d[i]=-1 ;
	}
	
	q.push(a) ;
	used[a]=true ;
	p[a]=-1 ;
	d[a]=0 ;

	while(!q.empty()){

		int v=q.front() ;
		q.pop() ;
		for(int u:adj[v]){

			if(!used[u])
				{
					used[u]=true ;
					q.push(u) ;
					d[u]=d[v]+1 ;
					p[u]=v ;
				}

		}


	}

	if(d[b]!=-1)

		return d[b] ;
	else
		return -1 ;	
}


void solve(int y){

	
	int l=1000 ;
	int r=10000 ;

	vector<bool> p =segmentedSieve(l,r) ;


	vector<int> num ;
	for(int i=0;i<p.size();i++){
		if(p[i]==true){
			num.push_back(i+1000) ;
		}
	}
	
	


	int n=num.size() ;
	vector<vector<int>> adj(n) ;


/*
	 for(int i=0;i<n;i++){
	 	cout<<num[i]<<endl ;
	 }
*/	 
/*
	addEdge(adj,0,2) ;

	cout<<num[0]<<"->" ;

	for(int i:adj[0]){
		cout<<num[i] ;
	}
	
*/

	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<=n-1;j++){
			if(differBy1(num[i],num[j])){
				addEdge(adj,i,j) ;
			}
		}
	}


	int count=0 ;
 	while(count<y){
	
 		int a,b ; 
		cin>>a>>b ;
 		
 	 int in1=-1;
 	 int in2=-1;

    for (int j = 0; j < num.size(); j++)  
        if (num[j] == a) 
            in1 = j;  
    for (int j = 0; j < num.size(); j++)  
        if (num[j] == b) 
            in2 = j;  

        
        int ans ;

        if(in1==-1||in2==-1)
			cout<<"Impossible"<<endl ;
        else
        {		

	 		ans=BFS(in1,in2,adj,n) ;
	 		
	 		if(ans!=-1)
				cout<<ans<<endl ;
			else
				cout<<"Impossible"<<endl ;
		}
		count++ ;
	}
	
}



int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	
	int y ;
	
	//y=1 ;
	cin>>y ;
	
	solve(y) ;
	

	
}