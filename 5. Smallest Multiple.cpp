#include "bits/stdc++.h"
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define nline             "\n"
#define ll                long long int
#define vi                vector<int>
#define vll               vector<ll>
#define vvi               vector<vi>
#define vvll              vector<vll>
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

template<typename T1, typename T2>istream& operator>>(istream& in, pair<T1, T2> &a) {in >> a.fr >> a.sc; return in;}
template<typename T1, typename T2>ostream& operator<<(ostream& out, pair<T1, T2> a) {out << a.fr << " " << a.sc; return out;}
template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}

const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;

const int N = 0;

multiset<int> factors(int n) {
   multiset<int> f;
   for (int x = 2; x * x <= n; x++) {
      // if (n % x == 0)
      // {
      while (n % x == 0) {
         f.insert(x);
         n /= x;
      }
      // }
   }
   if (n > 1) f.insert(n);
   return f;
}


ll power(ll a, ll b)   //a is base, b is exponent
{
   if (b == 0)
      return 1;
   if (b == 1)
      return a;
   if (b % 2 == 1)
      return (power(a, b - 1) * a) % M;
   ll q = power(a, b / 2);
   return (q * q) % M;
}

void solve() {

   multiset<int> s;
   map<int, int> m;
   for (int i = 1; i <= 20; ++i)
   {
      // vi a = factors(i);
      multiset<int> st = factors(i);
      // for (int j = 0; j < a.size(); ++j)
      // s.insert(a[j]);
      for (auto x : st)
      {
         m[x] = max(m[x], (int)st.count(x));
      }
   }


   ll ans = 1;
   for (auto x : m)
   {
      cout << x.first << ' ' << x.second << nline;
      if (x.second > 0) ans *= power(x.first, x.second);
   }


   cout << ans << nline;
   for (int i = 1; i < 21; ++i)
   {
      cout << ans % i << ' ';
   }


   return;
}
signed main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
#ifdef SIEVE
   sieve();
#endif
#ifdef NCR
   init();
#endif
   int t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}
