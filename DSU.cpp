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

//-------------------- DSU --------------------//
#define int ll
#define MAX_N (1 << 20)

int parent[MAX_N + 5];

int get_root(int a) {
    if (parent[a] < 0) {
        return a;
    }
    return parent[a] = get_root(parent[a]);
}

bool join(int a, int b) {
    int root_a = get_root(a);
    int root_b = get_root(b);
    if (root_a != root_b) {
        if (parent[root_a] <= parent[root_b]) {
            parent[root_a] += parent[root_b];
            parent[root_b] = root_a;
        }
        else {
            parent[root_b] += parent[root_a];
            parent[root_a] = root_b;
        }
        return true;
    }
    return false;
}

void solve();

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    //cin >> T;
    FOR(t, T) {
        //cout << "Case #" << t << ": ";
        FOR(i, MAX_N) {
            parent[i] = -1;
        }
        solve();
    }
    return 0;
}


//--------------------------------------------------------------//
void solve() {

}