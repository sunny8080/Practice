#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll               long long
#define ull              unsigned long long
#define ff               first
#define ss               second
#define pb               push_back
#define mp               make_pair
#define pii              pair<int,int>
#define vi               vector<int>
#define vll              vector<ll> 
#define vvi              vector< vector<int>>
#define vvll             vector< vector<ll>>
#define mii              map<int,int>
#define pqb              priority_queue<int>
#define pqs              priority_queue<int, vector<int>, greater<int>>
#define setbits(x)       __builtin_popcountll(x)
#define zrobits(x)       __builtin_ctzll(x)
#define mod              1000000007
#define inf              1e18
#define ps(x,y)          fixed<<setprecision(y)<<x
#define mk(arr, n, type) type *arr=new type[n];
#define wt(x)            int x; cin>>x; while( x-- )
#define rep(i,a,b)       for( int i=a; i<=b; i++ )
#define repi(i,a,b)      for( int i=a; i>=b; i-- )
#define sp               ' '
#define nl               char(10)
#define endl             char(10)
#define PRT(ar)          for( auto i : ar ) cout<<i<<sp; cout<<nl;
#define mems(x,ch)       memset(x,ch,sizeof(x))
#define sortv(x)         sort(x.begin(),x.end())
#define sortvr(x)        sort(x.rbegin(),x.rend())
#define all(x)           x.begin(), x.end()

const ll cnst = 1e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //    #ifndef ONLINE_JUDGE
    //        freopen("input.txt", "r", stdin);
    //        freopen("output.txt", "w", stdout);
    //    #endif
}

// QUE :- https://www.hackerearth.com/problem/algorithm/number-of-divisors-3-4f073391/

class Solution {

    ll modPower(ll a, ll b, ll m) {
        ll ans = 1LL;
        while (b) {
            if ((b & 1)) ans = (ans * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return ans;
    }

    ll invMod(ll a, ll m) {
        if (m == 1) return 0;
        return modPower(a, m - 2, m);
    }

public:
    ll solve(vll& nums) {
        ll ans = 1LL;

        ll prod = 1;
        for (auto x : nums) {
            prod = (prod * (x + 1)) % mod;
        }
        // cout<<"PROD "<<prod<<"\n";

        for (auto x : nums) {
            // cnt = [ prod*x*(x+1) ]% mod
            ll cnt = ((prod * x) % mod * invMod(2, mod)) % mod;
            // cout<<"CNT "<<cnt<<nl;

            ans = (ans * (cnt + 1)) % mod;
        }
        return ans;
    }
};


int32_t main() {
    fastIO();

    int n; cin >> n;
    vll arr(n);
    for (auto& x : arr) cin >> x;
    cout << (new Solution())->solve(arr);
    return 0;
}

// 3
// 3 2 1
// OUT:- 12025