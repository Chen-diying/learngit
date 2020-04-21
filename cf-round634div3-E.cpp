#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define mod 1000000007
using namespace std;
ll gcd(ll a,ll b){
	if(a%b==0)return b;
	return gcd(b,a%b);
}
int b[201][200005];
int a[200005];
void solve(){
	int n;
	cin >> n;
	for(int i=0;i<=n;i++){
		a[i]=0;
	}
	for(int i=0;i<=200;i++){
		for(int j=0;j<=n;j++){
			b[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
	} 
	for(int i=1;i<=n;i++){
		b[a[i]][0]++;
		b[a[i]][b[a[i]][0]]=i;
	}
	int ans=0;
	for(int i=1;i<=200;i++){
		ans=max(ans,b[i][0]);
		int l=1;int r=b[i][0];
		int cnt=0;
		while(l<r){
			cnt+=2;
			int indexl=b[i][l];
			int indexr=b[i][r];
			int mid=0;
			for(int j=1;j<=200;j++){
				if(i==j) continue;
				int midl = upper_bound(b[j]+1,b[j]+b[j][0]+1,indexl)-b[j];
				int midr = upper_bound(b[j]+1,b[j]+b[j][0]+1,indexr)-b[j]-1;
				mid=max(mid,midr-midl+1);
			}
			ans=max(ans,cnt+mid);
			l++;r--;
		}
	}
	cout << ans << endl;
}
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

//https://codeforces.com/contest/1335/problem/E2
// Codeforces Round #634 (Div. 3)
