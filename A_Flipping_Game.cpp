#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll                 long long
// #define int                long long
#define ull                unsigned long long
#define ff                 first
#define ss                 second
#define pb                 push_back
#define mp                 make_pair
#define pii                pair<int,int>
#define vi                 vector<int>
#define vll                vector<ll> 
#define vvi                vector< vector<int>>
#define vvll               vector< vector<ll>>
#define vpii               vector<pair<int,int>>
#define mii                map<int,int>
#define pqb                priority_queue<int>
#define pqs                priority_queue<int, vector<int>, greater<int>>
#define setbits(x)         __builtin_popcountll(x)
#define zrobits(x)         __builtin_ctzll(x)
#define mod                1000000007
#define inf                1e18
#define ps(x,y)            fixed<<setprecision(y)<<x
#define mk(arr, n, type)   type *arr=new type[n];
#define wt(x)              int x; cin>>x; while( x-- )
#define sp                 ' '
#define nl                 char(10)
#define PRT(ar)            for( auto i : ar ) cout<<i<<sp; cout<<nl;
#define mems(x,ch)         memset(x,ch,sizeof(x))
#define sortv(x)           sort(x.begin(),x.end())
#define sortvr(x)          sort(x.rbegin(),x.rend())
#define all(x)             x.begin(), x.end()
#define fr(t,a,b)          for( int t=(a); t<=(b); t++)
#define frr(t,a,b)         for( int t=(a); t>=(b); t--)
#define cn(x)              int x; cin>>x;
#define ri(x)              cin >> x
#define rii(x, y)          cin >> x >> y
#define riii(x, y, z)      cin >> x >> y >> z
#define riiii(x, y, z, w)  cin >> x >> y >> z >> w
#define rvi(nums)          for (auto& x : nums) cin >> x;
#define dri(x)             int x; cin >> x
#define drs(s)             string s; cin >> s
#define drii(x, y)         int x, y; cin >> x >> y
#define driii(x, y, z)     int x, y, z; cin >> x >> y >> z
#define driiii(x, y, z, w) int x, y, z, w; cin >> x >> y >> z >> w
#define drvi(nums, n)      vector<int> nums(n); for (auto& x : nums) cin >> x;
#define iff(x, y)  if(x) y

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

    int maxSubarraySum(vi& nums) {
        int maxNeg = INT_MIN, maxi = 0, sum = 0;
        for (auto x : nums) {
            if (x <= 0) maxNeg = max(maxNeg, x);
            sum += x;
            maxi = max(maxi, sum);
            if (sum < 0) sum = 0;
        }
        return maxi == 0 ? maxNeg : maxi;
    }
public:
    // O(N^2)
    int solve1(vi& nums) {
        int n = nums.size();
        vi cnt0(n + 1, 0), cnt1(n + 1, 0);

        for (int i = 1; i <= n; i++) cnt0[i] = cnt0[i - 1] + (nums[i - 1] == 0);
        for (int i = 1; i <= n; i++) cnt1[i] = cnt1[i - 1] + (nums[i - 1] == 1);

        int maxi1 = 0, total1 = cnt1[n];
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                maxi1 = max(maxi1, total1 - (cnt1[j] - cnt1[i - 1]) + (cnt0[j] - cnt0[i - 1]));
            }
        }
        return maxi1;
    }


    // O(N)
    int solve2(vi& nums) {
        int n = nums.size(), cnt1 = 0;
        vi tmp(nums);
        for (auto& x : tmp) cnt1 += (x == 1), x = (x == 0) ? 1 : -1;
        return cnt1 + maxSubarraySum(tmp);
    }
};



int32_t main() {
    fastIO();
    Solution sol;

    dri(n);
    drvi(nums, n);

    // cout << sol.solve1(nums) << nl;
    cout << sol.solve2(nums) << nl;


    return 0;
}




