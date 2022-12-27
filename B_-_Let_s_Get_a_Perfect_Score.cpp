#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll               long long
// #define int              long long
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
#define ri(x)            cin >> x
#define rii(x, y)        cin >> x >> y
#define riii(x, y, z)    cin >> x >> y >> z
#define rv(nums)         for (auto& x : nums) cin >> x;
#define dri(x)           int x; cin >> x
#define drs(s)           string s; cin >> s
#define drii(x, y)       int x, y; cin >> x >> y
#define driii(x, y, z)   int x, y, z; cin >> x >> y >> z
#define drv(nums, n)     vector<int> nums(n); for (auto& x : nums) cin >> x;

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



//class Solution {
//
//public:
//
//};



int32_t main() {
    fastIO();
    // Solution sol;

    drii(n, m);
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int tmp = 0;
        for (int j = m - 1; j >= 0; j--) {
            if (s[j] == 'o') tmp |= (1 << (m - j - 1));
        }
        // cout<<tmp<<nl;
        arr.push_back(tmp);
    }

    int pos = (1 << m) - 1, cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) cnt += ((arr[i] | arr[j]) == pos);
    }
    cout << cnt << nl;
    return 0;
}



