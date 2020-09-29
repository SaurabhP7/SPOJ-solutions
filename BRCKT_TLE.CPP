#include<string>
#include<stdio.h>
using namespace std ;

#define NMAX 32768
char seq[NMAX];

void changeExpress(int x){

	int pos=x-1 ;

	if(seq[pos]==')'){
		seq[pos]='(' ;
	}
	else if(seq[pos]=='(')
	{
		seq[pos]=')' ;
	}

}


bool check(int n){
	
	int depth=0 ;

	for(int i=0;i<n;i++){

		if(seq[i]=='('){
			depth++ ;
		}
		else{
			depth-- ;
		}

		if(depth<0)
			return false ;

	}	

	if(depth>0)
		return false ;
	else
		return true ;

	
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	int len, q, i, idx, test = 1;
	while(scanf("%d", &len)==1) {
		scanf("%s", seq);
		printf("Test %d:\n", test++);
		scanf("%d", &q);
		for(i=0; i<q; i++) {
			scanf("%d", &idx);

			if(idx==0){
				bool ans=check(len) ;
				if(ans==true){
					printf("YES\n");
				}
				else
				{
					printf("NO\n");
				}
			}
			else
			 changeExpress(idx) ;
		}
	}
	return 0;

}