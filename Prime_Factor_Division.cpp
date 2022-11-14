#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll               long long
#define int              long long
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
#define vpii             vector<pair<int,int>>
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
#define fr(t,a,b)        for( int t=(a); t<=(b); t++)
#define frr(t,a,b)       for( int t=(a); t>=(b); t--)
#define cn(x)            int x; cin>>x;

const ll N = 1e5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}



vi sieve(N + 1, 1);
vi primes;      
class Solution {

public:
    void primeSieve() {
        sieve[0] = sieve[1] = 0;

        for (ll i = 2; i <= N; i++) {
            // i is prime if sieve[i] = 1
            if (sieve[i] == 1) {
                primes.pb(i);
                for (ll j = i * i; j <= N; j += i) {
                    sieve[j] = 0;
                }
            }
        }
    }


    // Using prime sieve // O(logN)
    vi factorize(ll n) {
        vi primeFactors;

        int i = 0;
        int pr = primes[i++];

        while (pr * pr <= n) {
            if (n % pr == 0) {
                primeFactors.pb(pr);
                while (n % pr == 0) {
                    n /= pr;
                }
            }
            pr = primes[i++];
        }

        if (n != 1) {
            primeFactors.pb(n);
        }
        return primeFactors;
    }


    vi findAllPrimeOfN(ll n) {
        vi primeFactors;

        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                primeFactors.pb(i);
                while (n % i == 0) {     // i is a prime factor of n
                    n /= i;
                }
            }
        }

        // if n is not 1 then n itself is a prime no
        if (n != 1) {
            primeFactors.pb(n);
        }

        return primeFactors;
    }
};



int32_t main() {
    fastIO();
    Solution sol;
    // sol.primeSieve();

    wt(t){
        int a, b; cin>>a>>b;
        auto a1 = sol.findAllPrimeOfN(a);
        auto a2 = sol.findAllPrimeOfN(b);
        // PRT(a1);
        // PRT(a2);

        if( a1.size() < a2.size() ) cout<<"NO"<<nl;
        else{
            int i=0;
            for( i=0; i<a2.size(); i++ ){
                if( a1[i] != a2[i] ) break;
            }
            // cout<<"SS";

            if( i == a2.size() ) cout<<"YES"<<nl;
            else cout<<"NO"<<nl;
        }

    }



    return 0;
}

