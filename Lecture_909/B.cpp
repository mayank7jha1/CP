// #pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using namespace chrono;

// in case of ordered set;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

// using namespace std;
// using namespace __gnu_pbds;

// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
// void myerase(pbds &t, int v){
//     int rank = t.order_of_key(v);//Number of elements that are less than v in t
//     auto it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
//     t.erase(it);
// }
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define rohit 1
#define MOD1 998244353
#define endl "\n"
#define exit break;
#define ar array
#define inf 1e18
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mod 1000000007
#define mp make_pair
#define in insert
#define fc first
#define sc second
#define pi 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define rp(i, a, n) for (int i = (a); i < (n); i++)
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.fc);
    cerr << ",";
    _print(p.sc);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
void init_code()
{
    fio
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
ll fact1(ll n, ll mod1)
{
    if (n == 1)
        return 1;
    return (fact1(n - 1, mod1) * n) % mod1;
}
bool cmppsf(const pair<ll, pair<ll, ll>>&a, const pair<ll, pair<ll, ll>>&b)
{
    if (a.second.first == b.second.first)
        return a.second.second > b.second.second;
    return a.second.first < b.second.first;
}
bool cmppss(const pair<int, pair<int, int>>&a, const pair<int, pair<int, int>>&b)
{
    if (a.second.first == b.second.first)
        return a.second.second < b.second.second;
    return a.second.first < b.second.first;
}
bool cmps(const pair<ll, ll>&a, const pair<ll, ll>&b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;

}
bool cmpfs(const pair<int, int>&a, const pair<int, int>&b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
bool cmpf(const pair<ll, ll>&a, const pair<ll, ll>&b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}
// tutoient function for fi(p^x)=p^(x-1)*(p-1) where p is some prime value is the nubmer which are coprime with p^x
// for equation ax+by=gcd(a,b); v[0] will give x and v[1] will give y and v[2] will give gcd(a,b);
void gcd2(ll a, ll b, vector<ll>&v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} gcd2(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll modinverse(ll x, ll m)
{
    vector<ll>v(3, 1);
    gcd2(x, m, v);
    return v[0];
}
void rotatel(vector<ll>&v, int k)
{
    int n = v.size();
    vector<ll>b(n);
    for (int i = 0; i < n; i++)
    {
        if (i - k < 0)
        {
            b[(i - k) % n + n] = v[i];
        }
        else
            b[(i - k) % n] = v[i];
    }
    v = b;
}
int lis(vector<int>v, int n) //longest increasing subsequence
{
    vector<int>d;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(d.begin(), d.end(), v[i]);
        if (it == d.end())
        {
            d.pb(v[i]);
        }
        else
        {
            *it = v[i];
        }
    }
    return d.size();
}
int modulo(int x, int mod1)
{
    return ((x % mod1) + mod1) % mod1;
}
ull power(ull x, ull y)
{
    // your code goes here
    ull ans = 1;
    while (y > 0)
    {
        ull lsbt = (y & 1);
        if (lsbt)
        {
            ans = (ans * x);
            //ans=modulo(ans,mod1);
        }
        x *= x;
        y >>= 1;
    }

    return ans;
}
vector<ll> smdiv(ll n)//
{
    vector<ll>v1;
    v1.pb(1);
    for (ll i = 2; i <= sqrt(n); i++) {
        {
            if (n % i == 0)
            {
                v1.pb(i);
                if (i != n / i)
                {
                    v1.pb(n / i);
                }
            }
        }
    }
    sort(all(v1));
    return v1;
}
vector<ll> primefactorization(ll n)
{
    vector<ll>v1;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            v1.pb(i);
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n > 1)
        v1.pb(n);
    return v1;
}
const int N = 300005;
vector<int>prime(N, 0);
void primesieve()// complexity (n/2+n/3+n/5+n/7+....) approx(order(n));(nlog(logn))
{
    prime[0] = 1;
    prime[1] = 1;
    for (int i = 2; i * i <= N; i++)
    {
        for (int j = i * i; j <= N; j += i)
        {
            if (prime[j] == 0)
                prime[j] = 1;
        }
    }
}
ll gcd(ll a, ll b)
{
    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // base case
    if (a == b)
        return a;
    // a is greater
    if (a > b)

        return gcd(a - b, b);
    return gcd(a, b - a);
}

int fen[N];// for fenwick initialize with all the values to 0 first then update;
void update(int i, int add)
{
    while (i < N)
    {
        fen[i] += add;
        i += (i & (-i));
    }
}
int getsum(int i)// and sum for ranges is sum(r)-sum(l-1);
{
    int s = 0;
    while (i > 0)
    {
        s += fen[i];
        i -= i & (-i);
    }
    return s;
}
ll modpower(int y, int n, ll m1)
{
    ll res = 1;
    ll x = y;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            res = (res % m1) * (x % m1);
            res %= m1;
        }
        n /= 2;
        x *= (x % m1);
        x %= m1;
    }
    return res % m1;
}
ll c[1010][1010];
void ncrpascal(int n, int r)
{

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, r); j++)
        {
            if (j == 0 or j == i)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]);
        }
    }
}
bool isprime(int x)
{
    if (x <= 1)return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            //cout<<i<<endl;
            return false;
        }
    }
    return true;
}
vector<int> lps(string t)
{
    //cout<<t<<endl;
    int n = t.length();
    vector<int>pf(n + 1, 0);
    int j = pf[0];
    for (int i = 1; i < n; i++)
    {
        j = pf[i - 1];
        while (j > 0 and t[j] != t[i])
        {
            j = pf[j - 1];
        }
        if (t[j] == t[i])
            j++;
        pf[i] = j;
    }
    //debug(pf);
    return pf;
}
vector<int> lpsv(vector<int>&t)
{
    //cout<<t<<endl;
    int n = t.size();
    vector<int>pf(n + 1, 0);
    int j = pf[0];
    for (int i = 1; i < n; i++)
    {
        j = pf[i - 1];
        while (j > 0 and t[j] != t[i])
        {
            j = pf[j - 1];
        }
        if (t[j] == t[i])
            j++;
        pf[i] = j;
    }
    return pf;
}
ll fact[200005];
void facatorial()
{
    fact[0] = 1;
    fact[1] = 1;
    for (ll i = 2; i <= 200002; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
    }
}
ll ncr(ll n, ll r)
{
    ll x = (fact[r] * fact[n - r]) % mod;
    return (fact[n] * modpower(x, mod - 2, mod)) % mod;
}
class segtree
{
public:
    ll sz;
    vector<ll>tree;
    vector<ll>ltree;
    bool lazy = false;

    // Tree intialization
    void init(ll n)
    {
        sz = n;

        tree.assign(4 * sz + 1, (ll)0);
    }
    // Lazy Tree initialization
    void Linit()
    {
        lazy = true;
        ltree.assign(4 * sz + 1, (ll)0);
    }
    // merge is to be updated according to type of query.
    ll merge(ll node1, ll node2)
    {
        return max(node1, node2);
    }
    // Left Node
    ll lc(ll x)
    {
        return 2 * x;
    }

    // Right Noder
    ll rc(ll x)
    {
        return 2 * x + 1;
    }

    // We can both build and update using set.
    void set(ll ni, vector<ll>&tree, ll start, ll end, ll curr, ll val)
    {
        if (start == end)
        {
            tree[ni] = val;
            return;
        }
        ll mid = (start + end) / 2;
        if (curr > mid)
        {
            set(2 * ni + 1, tree, mid + 1, end, curr, val);

        }
        else
        {
            set(2 * ni, tree, start, mid, curr, val);

        }
        tree[ni] = merge(tree[2 * ni], tree[2 * ni + 1]);
    }
    void set(ll val, ll i)
    {
        set(1, tree, 0, sz - 1, i, val);
    }
    ll query(ll ni, vector<ll>&tree, ll start, ll end, ll left, ll right)
    {
        // If we are doing lazy propagation

        if ((start > right) || (end < left)) return (-1LL) * (inf);
        if ( (start >= left) && (end <= right))
        {
            return tree[ni];

        }
        ll mid = (start + end) / 2;
        return merge(query(2 * ni, tree, start, mid, left, right), query(2 * ni + 1, tree, mid + 1, end, left, right));
    }
    ll query(ll left , ll right)
    {
        return query(1, tree, 0 , sz - 1, left, right);
    }
    // Update for lazy propagation
    void lupdate(vector<ll>&tree, vector<ll>&ltree, ll ni, ll start, ll end, ll left, ll right, ll val)
    {
        if (ltree[ni] != 0)
        {
            tree[ni] += (ltree[ni] * (end - start + 1));
            if (lc(ni) < ltree.size())
            {
                ltree[lc(ni)] += ltree[ni];

            }
            if (rc(ni) < ltree.size())
            {
                ltree[rc(ni)] += ltree[ni];

            }

            ltree[ni] = 0;

        }
        if ((start > right) || (end < left)) return;

        if ( (start >= left) && (end <= right))
        {
            tree[ni] += (val * (end - start + 1));
            if (rc(ni) < ltree.size())
            {
                ltree[rc(ni)] += val;

            }
            if (lc(ni) < ltree.size())
            {
                ltree[lc(ni)] += val;

            }
            return;
        }
        ll mid = (start + end) / 2;
        lupdate(tree, ltree, 2 * ni, start, mid, left, right, val);
        lupdate(tree, ltree, 2 * ni + 1, mid + 1, end, left, right, val);
        tree[ni] = merge(tree[lc(ni)], tree[rc(ni)]);


    }

    void lupdate(ll lef , ll rig, ll val)
    {
        lupdate(tree, ltree, 1, 0, sz - 1, lef, rig, val);

    }

    // Print the segment tree
    // void printx()
    // {
    //      for(int i=0;i<tree.sz();i++) cout<<tree[i]<<" ";
    //      cout<<"\n";

    // }
};


void solution()
{

    int faltu = 0, faltu1 = 0, faltu2 = 0;
    int STUDY;


    int n; cin >> n;
    vector<ll>v(n);
    vector<ll>pf(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        pf[i + 1] = v[i] + pf[i];
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    vector<ll>v1 = smdiv(n);
    ll ans = 0;
    for (auto it : v1)
    {
        int ele = it;
        ll mn = LLONG_MAX, mx = 0;
        ll l = 0, r = ele;
        while (l < n)
        {
            ll val = pf[r] - pf[l];
            mn = min(mn, val);
            mx = max(mx, val);
            l += ele;
            r += ele;
        }
        ans = max(ans, mx - mn);
    }
    cout << ans << endl;

}
int main()
{   init_code();
    auto st = high_resolution_clock::now();

    int t = 1;
    //facatorial();
    cin >> t;
    while (t--)
        solution();
    auto en = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(en - st);

    cerr << "Time :" << duration.count() / 1000 << "ms" << endl;
    /*
    rohit shakya solution
    user name : saitama_007
    */
    return 0;
}