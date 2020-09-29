#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

#define N 311111
#define A 1111111
#define block_size 555 // ~sqrt(N)

int cnt[A], a[N], ans[N], answer = 0;


void remove(int idx){

	cnt[a[idx]]-- ;
	if(cnt[a[idx]]==0)
		answer-- ;
}

void add(int idx){

	cnt[a[idx]]++ ;
	if(cnt[a[idx]]==1)
		answer++  ;
	
}


struct node
{
	int l,r,idx ;
	
}q[N];
bool cmp(node x,node y){
	if(x.l/block_size != y.l/block_size) {
		return x.l/block_size < y.l/block_size;
	}
	return x.r < y.r;

}


void solve(){
	int n ;
	cin>>n ;
	for(int i=1;i<=n;i++){
		cin>>a[i] ;
	}
	int m ;
	cin>>m ;
	
	for(int i=1;i<=m;i++){

		cin>>q[i].l>>q[i].r ; 
		q[i].idx=i ;

	}

	sort(q+1,q+m+1,cmp) ;

	int curr_l=0 ;
	int curr_r=-1;

	for(int i=1;i<=m;i++){

		while(curr_l>q[i].l){
			curr_l-- ;
			add(curr_l) ;
		}

		while(curr_r<q[i].r){
			curr_r++ ;
			add(curr_r) ;
		}

		while(curr_l<q[i].l){
			remove(curr_l) ;
			curr_l++ ;
		}

		while(curr_r>q[i].r){
			remove(curr_r) ;
			curr_r-- ;
		}

		ans[q[i].idx]=answer ;
	}
		for(int i=1;i<=m;i++){
		cout<<ans[i]<<"\n" ;
	}

}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	
int y ;
//cin>>y ;
y=1 ;

while(y--){
	solve() ;
}


}