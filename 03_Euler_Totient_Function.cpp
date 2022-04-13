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

// QUE :- https://www.spoj.com/problems/ETF/

class Solution {

public:
    // METHOD - 1

    vi computeTotientByEratosthenes(int n) {
        vi phi(n + 1);
        phi[0] = 0;
        for (int i = 1; i <= n; i++) phi[i] = i;

        for (int p = 2; p <= n; p++) {
            if (phi[p] == p) {
                for (int j = p; j <= n; j += p) {
                    phi[j] -= phi[j] / p;
                }
            }
        }
        return phi;
    }

    vi computeTotientByAddProperty(int n) {
        vi phi(n + 1);
        phi[0] = 0, phi[1] = 1;

        for (int i = 2; i <= n; i++) {
            phi[i] = i - 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 2 * i; j <= n; j += i) {
                phi[j] -= phi[i];
            }
        }
        return phi;
    }
};

int32_t main() {
    fastIO();

    int N = 1e6 + 1;
    //vi phi = (new Solution())->computeTotientByEratosthenes(N);
    vi phi = (new Solution())->computeTotientByAddProperty(N);

    wt(t) {
        int n; cin >> n;
        cout << phi[n] << nl;
    }

    return 0;
}

