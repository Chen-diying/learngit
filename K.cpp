#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
ll gcd(ll a,ll b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll a[1000004], b[1000004];
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

void solve(){
	ll n, m, p;
	cin >> n >> m >> p;
	ll ans1 = 0, ans2 = 0, f1 = 1, f2 = 1;
	for(int i = 0; i < n; i++){
		a[i] = read();
		if((a[i]%p)&&f1){
			ans1 = i;
			f1 = 0; 
		}	
	} 
	for(int i = 0;i<m;i++){
		b[i] = read();
		if((b[i]%p)&&f2){
			ans2 = i;
			f2 = 0;
		}
	}
	cout << ans1+ans2<< endl;
}

int main() {
	solve();
    return 0;
}
