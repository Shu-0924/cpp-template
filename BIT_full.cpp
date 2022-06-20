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

//------------------- BIT 3.0 -------------------//
#define int ll
int N;
int D[1 << 20] = {}; // store d[i]
int D_i[1 << 20] = {}; // store d[i]*i

// prefix query
int query(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= i & (-i)) {
        ret += (x + 1) * D[i] - D_i[i];
    }
    return ret;
}

// postfix update
void update(int x, int d) {
    for (int i = x; i <= N; i += i & (-i)) {
        D[i] += d;
        D_i[i] += d * x;
    }
}

int range_ask(int L, int R) {
    return query(R) - query(L - 1);
}

void range_add(int L, int R, int d) {
    update(L, d);
    update(R + 1, -d);
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}
