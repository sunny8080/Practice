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

const ll N = 1e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}


struct flower {
    int ht, bty;
};


int n;
vector<flower> v(200005);
int dp[200005];



class Solution {

public:
    int solve() {
        map<int, int> mful; // meaningful set// {ht, dp[ht]}
        dp[1] = v[1].bty;
        mful[v[1].ht] = dp[1];

        int ans = dp[1];

        for (int i = 2; i <= n; i++) {
            dp[i] = v[i].bty;
            auto it = mful.lower_bound(v[i].ht + 1);
            if (it != mful.begin()) {
                it--;
                dp[i] += it->second;
            }
            mful[v[i].ht] = dp[i];


            it = mful.upper_bound(v[i].ht);
            while (it != mful.end() && it->second <= dp[i]) {
                auto tmp = it;
                tmp++;
                mful.erase(it);
                it = tmp;
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }

};



int32_t main() {
    fastIO();
    Solution sol;
    mems(dp, -1);

    cin >> n;
    fr(i, 1, n) cin >> v[i].ht;
    fr(i, 1, n) cin >> v[i].bty;
    cout<<sol.solve()<<nl;




    return 0;
}

