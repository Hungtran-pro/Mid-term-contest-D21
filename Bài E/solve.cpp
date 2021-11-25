#include <bits/stdc++.h>
#define author "CODE BY KQamazing"
#define faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie();                    \
    cout.tie()
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pld pair<ld, ld>
#define matrix vector<vector<ll>>
#define all(_) _.begin(), _.end()
#define allr(_) _.rbegin(), _.rend()
#define Unique(_) _.erase(unique(all(_)), _.end());
#define Modd (ll)(1e9 + 7)
#define Multitests 1
using namespace std;
void __print(int x) { cerr << x; }
void __print(ll x) { cerr << x; }
void __print(unsigned ll x) { cerr << x; }
void __print(ld x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#define FileInput freopen("test.in", "r", stdin)
#else
#define debug(x...)
#define FileInput
#endif

ll n, k;
string s;

bool check(int d)
{
    vector<ll> lst(k, n);
    matrix pos(n + 1, vector<ll>(k, n + 1));
    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] != '?')
            lst[s[i] - 'a'] = i;
        ll cur = n;
        for (int j = 0; j < k; j++)
        {
            pos[i][j] = (i + d <= cur ? i + d : pos[i + 1][j]);
            cur = min(cur, lst[j]);
        }
        cur = n;
        for (int j = k - 1; j >= 0; --j)
        {
            pos[i][j] = (i + d <= cur ? pos[i][j] : pos[i + 1][j]);
            cur = min(cur, lst[j]);
        }
    }
    vector<ll> dp(1 << k, n + 1);
    dp[0] = 0;
    for (int mask = 0; mask < (1 << k); mask++)
        if (dp[mask] <= n)
            for (int i = 0; i < k; i++)
                if (!((mask >> i) & 1))
                    dp[mask | (1 << i)] = min(dp[mask | (1 << i)], pos[dp[mask]][i]);
    return dp[(1 << k) - 1] <= n;
}

void Solve()
{
    cin >> n >> k >> s;
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l - 1 << endl;
}

int main()
{
    faster;
    // FileInput;
    int test = Multitests ? (cin >> test).ignore(), test : 1;
    while (test--)
        Solve();
    return 0;
}