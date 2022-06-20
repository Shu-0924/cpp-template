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

//------------------- String -------------------//
#define int ll

string read_string(string& str, int& i) {
    string ret = "";
    while (i < sz(str) && str[i] > ' ') {
        ret += str[i];
        i++;
    }
    while (i < sz(str) && str[i] <= ' ') {
        i++;
    }
    return ret;
}

int read_int(string& a, int& i) {
    int ret = 0, sign = 1;
    if (a[i] > ' ' && a[i] == '-') {
        sign = -1;
        i++;
    }
    while (i < sz(a) && a[i] > ' ') {
        ret = ret * 10 + a[i] - '0';
        i++;
    }
    while (i < sz(a) && a[i] <= ' ') {
        i++;
    }
    return sign * ret;
}

bool compare(string& a, string& b) {
    if (sz(a) != sz(b)) {
        return sz(a) < sz(b);
    }
    for (int i = sz(a) - 1; i >= 0; i--) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return false;
}

string add(string a, string b) {
    if (sz(a) < sz(b)) {
        string temp = a;
        a = b;
        b = temp;
    }
    FOR(i, sz(b)) {
        a[i] += b[i] - '0';
    }
    FOR(i, sz(a) - 1) {
        if (a[i] > '9') {
            a[i] -= 10;
            a[i + 1]++;
        }
    }
    if (a.back() > '9') {
        a[sz(a) - 1] -= 10;
        return a + "1";
    }
    else {
        return a;
    }
}

string subtract(string a, string b) {
    int sign = 1;
    if (compare(a, b) == true) {
        string temp = a;
        a = b;
        b = temp;
        sign *= -1;
    }
    FOR(i, sz(b)) {
        a[i] -= b[i] - '0';
    }
    FOR(i, sz(a) - 1) {
        if (a[i] < '0') {
            a[i] += 10;
            a[i + 1]--;
        }
    }
    while (sz(a) > 1 && a.back() == '0') {
        a.pop_back();
    }
    if (sign == -1) {
        a += '-';
    }
    return a;
}

string multiply(string a, string b) {
    if (a == "0" || b == "0") {
        return "0";
    }
    if (a == "1") {
        return b;
    }
    if (b == "1") {
        return a;
    }
    vector<int> v(sz(a) + sz(b), 0);
    FOR(i, sz(a)) {
        FOR(j, sz(b)) {
            v[i + j] += ((int)a[i] - '0') * ((int)b[j] - '0');
        }
    }
    FOR(i, sz(v) - 1) {
        v[i + 1] += v[i] / 10;
        v[i] %= 10;
    }
    string c = "";
    FOR(i, sz(v)) {
        c += v[i] + '0';
    }
    while (sz(c) > 1 && c.back() == '0') {
        c.pop_back();
    }
    return c;
}

string divide(string a, string b) {
    if (b == "0") {
        cout << "Error: divided by zero\n";
        exit(0);
    }
    if (compare(a, b) == true) {
        return "0";
    }
    vector<string> dp(10);
    dp[0] = "0";
    FOR(i, 9) {
        dp[i + 1] = add(dp[i], b);
    }
    string now = "";
    for (int i = sz(a) - sz(b); i < sz(a); i++) {
        now += a[i];
    }
    string c = "";
    for (int i = sz(a) - sz(b); i >= 0; i--) {
        int q = 0, step = 8;
        while (step) {
            if (q + step <= 9 && compare(now, dp[q + step]) == false) {
                q += step;
            }
            step >>= 1;
        }
        c += q + '0';
        string r = subtract(now, dp[q]);
        if (i > 0) {
            now = "";
            now += a[i - 1];
            now += r;
        }
    }
    reverse(all(c));
    while (sz(c) > 1 && c.back() == '0') {
        c.pop_back();
    }
    return c;
}

string compute(string& a, char op, string& b) {
    if (op == '+') {
        if (a.back() != '-') {
            if (b.back() != '-') {
                return add(a, b);
            }
            else {
                b.pop_back();
                return subtract(a, b);
            }
        }
        else {
            if (b.back() != '-') {
                a.pop_back();
                return subtract(b, a);
            }
            else {
                a.pop_back();
                b.pop_back();
                return add(a, b) + "-";
            }
        }
    }

    if (op == '-') {
        if (a.back() != '-') {
            if (b.back() != '-') {
                return subtract(a, b);
            }
            else {
                b.pop_back();
                return add(a, b);
            }
        }
        else {
            if (b.back() != '-') {
                a.pop_back();
                return add(a, b) + "-";
            }
            else {
                a.pop_back();
                b.pop_back();
                return subtract(b, a);
            }
        }
    }

    else {
        int sign = 1;
        if (a.back() == '-') {
            a.pop_back();
            sign *= -1;
        }
        if (b.back() == '-') {
            b.pop_back();
            sign *= -1;
        }
        string result;
        if (op == '*') {
            result = multiply(a, b);
        }
        else {
            result = divide(a, b);
        }
        if (sign == 1) {
            return result;
        }
        else {
            return result + "-";
        }
    }
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
        solve();
    }
    return 0;
}

//--------------------------------------------------------------//
void solve() {
    // we compute the big integer by reversed string
    string a, b, operation;
    while (cin >> a >> operation >> b) {
        reverse(all(a));
        reverse(all(b));
        char op = operation[0];
        string result = compute(a, op, b);
        reverse(all(result));
        cout << result << '\n';
    }
    return;
}