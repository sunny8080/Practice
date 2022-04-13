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

const ll N = 200007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //    #ifndef ONLINE_JUDGE
    //        freopen("input.txt", "r", stdin);
    //        freopen("output.txt", "w", stdout);
    //    #endif
}


// QUE Easy :- https://www.spoj.com/problems/POWRTU/  
// QUE Hard :- https://www.spoj.com/problems/POWPOW2/ 
// Sol :- https://www.quora.com/How-do-I-solve-Power-with-Combinatorics-HARD-on-SPOJ

int fact2[N], fact1681[N][2], fact148721[N];

class Solution {

public:

    void calAllFact() {
        fact2[0] = fact148721[0] = 1;
        for (int i = 1; i < N; i++) {
            fact2[i] = (fact2[i - 1] * 1LL * i) % 2;
            fact148721[i] = (fact148721[i - 1] * 1LL * i) % 148721;
        }

        // Cal fact for mod=1681
        fact1681[0][0] = 1;
        fact1681[0][1] = 0;

        for (int i = 1; i < N; i++) {
            int t = i;

            // Remove all multiple of 41 and store it in fact1681[i][1]
            fact1681[i][1] = fact1681[i - 1][1];
            while (t % 41 == 0) {
                t /= 41;
                fact1681[i][1]++;
            }

            fact1681[i][0] = (fact1681[i - 1][0] * 1LL * t) % 1681;
        }
    }


    // find (a^b)%md 
    ll modPower(ll a, ll b, ll md) {
        ll ans = 1LL;
        while (b) {
            if ((b & 1)) ans = (ans * a) % md;
            a = (a * a) % md;
            b >>= 1;
        }
        return ans;
    }

    // find mod inverse of n wrt md // md is prime
    ll inverseEuler(ll n, ll md) {
        return modPower(n, md - 2, md);
    }

    // find mod inverse of n wrt md // md is not-prime
    ll inverseBrute(ll a, ll md) {
        ll x = 1;
        while (1) {
            if ((a * x) % md == 1) return x;
            x++;
        }
        return x;
    }

    // Chinese remainder theorem is used // num[] is fixed here // used for 3 congruence equation
    ll CRT3(ll r1, ll r2, ll r3) {
        ll p1 = 2, p2 = 1681, p3 = 148721; // p1, p2, p3 are pairwise co-prime
        ll prod = (p1 * p2 * p3);
        ll pp1 = prod / p1, pp2 = prod / p2, pp3 = prod / p3;
        ll inv1 = inverseEuler(pp1, p1);
        ll inv2 = inverseBrute(pp2, p2);
        ll inv3 = inverseEuler(pp3, p3);

        // CRT formula
        ll ans = (r1 * pp1 * inv1) % prod + (r2 * pp2 * inv2) % prod + (r3 * pp3 * inv3) % prod;
        ans = ans % prod;
        return ans;
    }


    // Chinese remainder theorem is used // num[] is fixed here // used for 2 congruence equation
    // p1, p2 should be pairwise co-prime
    ll CRT2(ll r1, ll r2, ll p1 = 2, ll p2 = 500000003) {
        ll prod = p1 * p2;
        ll pp1 = prod / p1, pp2 = prod / p2;
        ll inv1 = inverseEuler(pp1, p1);
        ll inv2 = inverseEuler(pp2, p2);

        // CRT formula
        ll ans = (r1 * pp1 * inv1) % prod + (r2 * pp2 * inv2) % prod;
        ans %= prod;
        return ans;
    }


    ll solve(int a, int b, int n) {
        // Base case a/c to que
        if ((a == 0 && b == 0) || (b == 0)) {
            return 1;
        }

        // find [ 2nCn mod (5*10^8+2) ]

        // nCr % md = (n! * modInv(r!, md) * modInv((n-r)!, md) ) %md

        ll r1 = (n == 0) ? 1 : 0;

        ll r2 = (fact1681[2 * n][0] * inverseBrute(fact1681[n][0], 1681)) % 1681;
        r2 = (r2 * inverseBrute(fact1681[2 * n - n][0], 1681)) % 1681;

        // Add requirred powers of 41 // p41(n) - p41(r) - p41(n-r) // p41(x) = power of 41 in x
        ll p41Require = fact1681[2 * n][1] - fact1681[n][1] - fact1681[2 * n - n][1];
        r2 = (r2 * modPower(41, p41Require, 1681)) % 1681;

        ll r3;
        if (a == 0) {
            r3 = 1;
        } else {
            r3 = (((fact148721[2 * n] * inverseEuler(fact148721[n], 148721)) % 148721) * inverseEuler(fact148721[2 * n - n], 148721)) % 148721;
        }

        // cout<<r1<<sp<<r2<<sp<<r3<<nl;

        ll X2nCn = CRT3(r1, r2, r3);
        if (X2nCn == 0) X2nCn = 500000002;
        ll ans;


        // Path - 1
        // Check b is odd or even
        if ((b & 1)) {
            // b is odd
            ll bOdd = modPower(b, X2nCn, mod - 1);
            ans = modPower(a, bOdd, mod);
            // cout << "Bodd : " << ans << nl; // DEBUG
        } else {
            r1 = 0;
            r2 = modPower(b, X2nCn, 500000003);
            ll y = CRT2(r1, r2);
            ans = modPower(a, y, mod);
            // cout << "Beven : " << ans << nl; // DEBUG
        }

        // Path - 2
        // // b is odd
        // ll bOdd = modPower(b, X2nCn, mod-1 );
        // ans = modPower(a, bOdd, mod);
        // // cout << "Bodd : " << ans << nl; // DEBUG

        // Both path is working, i don't know why
        // If you know, comment

        return ans;
    }

};


int32_t main() {
    fastIO();

    Solution sol;
    sol.calAllFact();

    wt(t) {
        int a, b, n; cin >> a >> b >> n;
        cout << sol.solve(a, b, n) << nl;
    }

    return 0;
}


// 1
// 1 1 1
// OUT:-
// 1

// 1
// 100000 100000 100000
// OUT:-
// 754901378

// 1
// 10 10 10
// OUT:-
// 330427784
