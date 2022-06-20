#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pis pair<int, string>

#define INF ((ll)1 << 60)
#define MOD (int)1000000007

#define f first
#define s second
#define pb push_back

#define FOR(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define EACH(x, n) for (auto& (x): (n))
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define sz(x) (int)x.size()

//------------------- BIT 2.0 -------------------//
#define int ll
int N;
int BIT[1 << 20] = {};

// prefix query
int query(int x) {
    int ret = 0;
    while (x) {
        ret += BIT[x];
        x -= x & (-x);
    }
    return ret;
}

// single update
void update(int x, int d) {
    while (x <= N) {
        BIT[x] += d;
        x += x & (-x);
    }
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}