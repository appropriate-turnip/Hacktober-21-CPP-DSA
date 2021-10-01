#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;

const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;

struct st
{
    static const int N = 1100000;
    string a;
    int t[N][26], l[N], r[N], p[N], s[N], tv, tp, ts, la;
    vector<int> e[N];
    int cnt[N];

    void ukkadd(int c) // add character s to the tree
    {
    suff:; // we'll return here after each transition to the suffix (and will add character again)
        if (r[tv] < tp)
        {
            if (t[tv][c] == -1)
            {
                t[tv][c] = ts;
                l[ts] = la;
                p[ts++] = tv;
                tv = s[tv];
                tp = r[tv] + 1;
                goto suff;
            }
            tv = t[tv][c];
            tp = l[tv];
        }
        if (tp == -1 || c == a[tp] - 'a')
            tp++;
        else
        {
            l[ts + 1] = la;
            p[ts + 1] = ts;
            l[ts] = l[tv];
            r[ts] = tp - 1;
            p[ts] = p[tv];
            t[ts][c] = ts + 1;
            t[ts][a[tp] - 'a'] = tv;
            l[tv] = tp;
            p[tv] = ts;
            t[p[ts]][a[l[ts]] - 'a'] = ts;
            ts += 2;
            tv = s[p[ts - 2]];
            tp = l[ts - 2];
            while (tp <= r[ts - 2])
            {
                tv = t[tv][a[tp] - 'a'];
                tp += r[tv] - l[tv] + 1;
            }
            if (tp == r[ts - 2] + 1)
                s[ts - 2] = tv;
            else
                s[ts - 2] = ts;
            tp = r[tv] - (tp - r[ts - 2]) + 2;
            goto suff;
        }
    }

    void build()
    {
        ts = 2;
        tv = 0;
        tp = 0;
        fill(r, r + N, (int)a.size() - 1);
        s[0] = 1;
        l[0] = -1;
        r[0] = -1;
        l[1] = -1;
        r[1] = -1;
        memset(t, -1, sizeof t);
        fill(t[1], t[1] + 26, 0);
        for (la = 0; la < (int)a.size(); ++la)
            ukkadd(a[la] - 'a');
    }

    void dfs(int v)
    {
        for (int j = 0; j < 26; j++)
        {
            if (t[v][j] != -1)
            {
                dfs(t[v][j]);
                cnt[v] += cnt[t[v][j]];
            }
        }
        cout << v << " " << cnt[v] << endl;
    }

    void init()
    {
        for (ll i = 0; i < a.length(); i++)
        {
            bool leaf = 1;
            for (ll j = 0; j < 26; j++)
            {
                if (t[i][j] != -1)
                    leaf = 0;
            }
            cnt[i] = leaf;
            e[p[i]].push_back(i);
        }

        dfs(0);
    }

    ll ask(string s)
    {
        ll p = 0;
        for (ll i = 0; i < s.length(); i++)
        {
            cout << p << " " << cnt[p] << endl;
            p = t[p][s[i] - 'a'];
            cout << p << " " << cnt[p] << endl;
        }
        return cnt[p];
    }
};

ll n, m, k, q, l, r, x, y, z;
string s, t;
ll ans = 0;

const ll stopv = 1.05e6;
string ss[500];
ll stop_pos;
st suffix;

void solve(int tc = 0)
{
    cin >> n >> q;
    cin >> s >> t;

    ss[0] = s;
    string x = s;
    stop_pos = n + 1;
    for (ll i = 1; i <= n; i++)
    {
        x = x + t[i - 1] + x;
        if (x.length() > stopv)
        {
            stop_pos = i;
            break;
        }
        ss[i] = x;
    }

    string y = ss[stop_pos - 1];
    y = y + 'x' + y;
    suffix.a = y;

    suffix.build();
    suffix.init();

    cout << y << endl;
    cout << suffix.ask("d") << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;
    cin >> tc;
    for (int t = 0; t < tc; t++)
        solve(t);
}
