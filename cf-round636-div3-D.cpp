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

int cnt[400005];int sum[400005];int c[400005];
void solve(){
    int n,k;
    cin >> n >> k;
    int a[200005];int b[100005];
    for(int i=1;i<=n;i++){
    	cin >> a[i];
	}
	for(int i=1;i<=2*k;i++){
		cnt[i]=0;sum[i]=0;c[i]=0;
	}
	for(int i=1;i<=n/2;i++){
		b[i]=a[i]+a[n-i+1];
		c[b[i]]++;
		int ma=max(a[i],a[n-i+1]);
		int mi=min(a[i],a[n-i+1]);
		if(b[i]-ma+1>=1) cnt[b[i]-ma+1]++;
		else cnt[1]++;
		if(b[i]+k-mi+1<=2*k) cnt[b[i]+k-mi+1]--;
	}
	for(int i=1;i<=2*k;i++) sum[i]+=(sum[i-1]+cnt[i]);
	int ans=1e8;
	for(int i=2;i<=2*k;i++){
		int cnt=(n/2-sum[i])*2+sum[i]-c[i];
		ans=min(ans,cnt);
	}
	cout << ans << endl;
	
}
 
int main(){
	ios::sync_with_stdio(false);
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}

//https://codeforces.com/contest/1343/problem/D
//Codeforces Round #636 (Div. 3)

