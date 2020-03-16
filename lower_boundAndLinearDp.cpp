#include <bits/stdc++.h>
using namespace std;

int dp[100005] = {0};
int a[100005];

bool cmp1(int a, int b){
	return a > b;
}

void solve(){
    int lena = 0;
    for(int i = 0; cin >> a[i]; i++) {
        lena++;
    };
    int len = 0, mi = 0;
    for(int i = 0; i < lena; i++){
        if(i == 0) dp[len++] = a[i];
        else {
            if(dp[len-1] >= a[i]) dp[len++] = a[i];
            else {
                *lower_bound(dp,dp+len,a[i],cmp1) = a[i];
            }
        }
    }
    cout << len << endl;
    int len2 = 0;memset(dp,0,sizeof(dp));
    for(int i = 0; i < lena; i++){
    	if(i == 0) dp[len2++] = a[i];
    	else{
    		if(dp[len2-1] < a[i]) dp[len2++] = a[i];
    		else{
    			*upper_bound(dp,dp+len2,a[i]) = a[i];
			}
		}
	}
	cout << len2;
}
int main(){
	solve();
	return 0;
}
