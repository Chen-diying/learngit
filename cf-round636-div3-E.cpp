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

vector<int> v[200005];
int disa[200005],disb[200005],disc[200005];
void bfs(int x,int *a){
	queue<int> q;
	q.push(x);a[x]=0;
	while(!q.empty()){
		int z=q.front();
		q.pop();
		for(vector<int>::iterator it=v[z].begin();it!=v[z].end();it++){
			if(*it==z) continue;
			if(a[*it]<0) {
				a[*it]=a[z]+1;
				q.push(*it);
			}
		}
	}
}
ll p[200005],sum[200005];
void solve(){
	int n,m,a,b,c;
	cin >> n >> m >> a >> b >>c;
	sum[0]=0;
	for(int i=0;i<=n;i++){
		disa[i]=-1;disb[i]=-1;disc[i]=-1;
		v[i].clear();
	}
	for(int i=1;i<=m;i++){
		cin >> p[i];
		sum[i]=0;
	}
	sort(p+1,p+m+1);
	for(int i=1;i<=m;i++){
		sum[i]=sum[i-1]+p[i];
	}
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs(a,disa);bfs(b,disb);bfs(c,disc);
	ll ans=1e18;
	for(int i=1;i<=n;i++){
		if(disa[i]+disb[i]+disc[i]>m) continue;
		ans = min(ans,sum[disb[i]]+sum[disa[i]+disb[i]+disc[i]]);
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

//https://codeforces.com/contest/1343/problem/E
//Codeforces Round #636 (Div. 3)

