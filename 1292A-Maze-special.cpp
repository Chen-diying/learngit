#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int ma[3][100005], dp = 0;
ll gcd(ll a,ll b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}
void solve(){

}

int main() {
    int n, q;
    cin >> n >> q;
    memset(ma, 0, sizeof(ma));
    for (int i = 1; i <= q; ++i) {
        int r,c;
        cin >> r >> c;
        if (ma[r][c]) ma[r][c] = 0;
        else ma[r][c] = 1;
        if (r == 1) {
            if (ma[2][c]||ma[2][c-1]||ma[2][c+1]) {
                if (ma[r][c]) dp++;
                else dp--;
            }
        } else {
            if (ma[1][c-1]) {
                    if (!(ma[2][c-2]||ma[2][c-1])) {
                        if (ma[2][c]) dp++;
                        else dp--;
                    }
            }
            if (ma[1][c]) {
                if (!(ma[2][c+1]||ma[2][c-1])) {
                    if (ma[2][c]) dp++;
                    else dp--;
                }
            }
            if (ma[1][c+1]) {
                if (!(ma[2][c+2]||ma[2][c+1])) {
                    if (ma[2][c]) dp++;
                    else dp--;
                }
            }
        }
        if (dp) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}