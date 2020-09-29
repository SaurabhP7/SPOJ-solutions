#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

class Trie {

public:
    Trie() {


    }

   	int f=1 ;

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= '0';

        if(node->isword==true){

        	f=0 ;

        }   

        if (!node->next[ch]) { 

            	node->next[ch] = new Trie(); 
            }
            node = node->next[ch];
        }
        node->isword = true;

        for(int i=0;i<10;i++){

        	if(node->next[i]!=NULL)

        		f=0 ;

            }


    }

    bool search(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= '0';
            if (!node->next[ch]) { return false; }
            node = node->next[ch];
        }
        return node->isword;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= '0';
            if (!node->next[ch]) { return false; }
            node = node->next[ch];
        }
        return true;
    }
   
private:
    Trie* next[11] = {};
    bool isword = false;
};


void solve(){

	int n ;
	cin>>n ;

	vector<string> st ;
	for(int i=1;i<=n;i++){

		string s ;
		cin>>s ;

		st.push_back(s) ;

	} 

	Trie alphabets ;

	for(int i=0;i<n;i++){

		alphabets.insert(st[i]) ;
				
	}

	int x=alphabets.f ;

	if(x==0){
		cout<<"NO"<<"\n" ;
	}
	else{
		cout<<"YES"<<"\n" ;
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
	
	while(y--)
	{	
		solve() ;
	}


}