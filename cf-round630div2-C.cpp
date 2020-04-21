#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define INF 0x3f3f3f3f

void solve(){
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	int nn=n/k;int ans=n;
	for(int i=0;i<k/2;i++){
		int cnt[30]={0};
		int mx=0;
		for(int j=0;j<nn;j++){
			cnt[s[i+j*k]-'a']++;
			cnt[s[k-i-1+j*k]-'a']++;
		}
		for(int j=0;j<26;j++){
			mx=max(mx,cnt[j]);
		}
		ans-=mx;
	}
	if(k%2){
		int cnt1[30]={0};
		int x=0;
		for(int i=0;i<nn;i++){
			cnt1[s[k/2+i*k]-'a']++;
		}
		for(int j=0;j<26;j++){
			x=max(x,cnt1[j]);
		}
		ans-=x;
	}
	cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
    	solve();
	}
    return 0;
}

//https://codeforces.com/contest/1332/problem/C
//Codeforces Round #630 (Div. 2)

