#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
ll gcd(ll a,ll b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}
 
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
ll dp1[205][205],dp2[205][205];
void solve(){
	ll n;
	cin >> n;
	ll a[205]={0};ll s[205]={0};
	for(int i=1;i<=n;i++){
		cin >> a[i];
		a[i+n]=a[i];
		
	}
	for(int i=1;i<=2*n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int len=2;len<=n;len++){
		for(int l=1;l<=2*n-len+1;l++){
			int r=l+len-1;
			dp2[l][r]=1e18;
			for(int k=l;k<r;k++){
				dp1[l][r]=max(dp1[l][r],dp1[l][k]+dp1[k+1][r]+s[r]-s[l-1]);
				dp2[l][r]=min(dp2[l][r],dp2[l][k]+dp2[k+1][r]+s[r]-s[l-1]);
			}
		}
	}
	ll mi=1e18,ma=0;
	for(int i=1;i<=n;i++){
		mi=min(mi,dp2[i][i+n-1]);
		ma=max(ma,dp1[i][i+n-1]);
	}
	cout << mi << endl << ma << endl;
}
 
int main() {
	ios::sync_with_stdio(false);
	solve();
    return 0;
}

//https://www.luogu.com.cn/problem/P1880
//P1880 [NOI1995]石子合并 区间dp 


