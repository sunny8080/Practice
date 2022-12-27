#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll               long long
#define int              long long
// #define int              unsigned long long
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
#define sp               ' '
#define nl               char(10)
#define PRT(ar)          for( auto i : ar ) cout<<i<<sp; cout<<nl;
#define mems(x,ch)       memset(x,ch,sizeof(x))
#define sortv(x)         sort(x.begin(),x.end())
#define sortvr(x)        sort(x.rbegin(),x.rend())
#define all(x)           x.begin(), x.end()
#define fr(t,a,b)        for( int t=(a); t<=(b); t++)
#define frr(t,a,b)       for( int t=(a); t>=(b); t--)
#define cn(x)            int x; cin>>x;
#define cnar(nums)       for (auto& x : nums) cin >> x;

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



class Solution {
    int query(vi& a, vi& b, int x, int k) {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            cnt += ((a[i] * x - b[i]) > 0 ? (a[i] * x - b[i]) : 0);
        }
        return cnt <= k;
    }
public:
    int solve(int n, int k, vi& a, vi& b) {
        int ans = 0, l = 0, r = INT64_MAX;
        for (int i = 0; i < a.size(); i++) {
            r = min(r, (k + b[i]) / a[i]);
        }

        while (l <= r) {
            int mid = (l + r) / 2;
            if (query(a, b, mid, k)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return ans;
    }
};



int32_t main() {
    fastIO();
    Solution sol;

    cn(n); cn(k);
    vi a(n), b(n); cnar(a); cnar(b);

    cout << sol.solve(n, k, a, b) << nl;;


    return 0;
}




