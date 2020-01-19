#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
void solve(){
    int n, l = 0;
    ll a[100007], sum = 0, cur = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    for (int j = 0; j < n; ++j) {
        if (cur <= 0) {
            cur = 0;
            l = j;
        }
        cur += a[j];
        if (cur >= sum) {
            if (l == 0&&j == n-1) {
                continue;
            }
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}