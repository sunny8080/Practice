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

// observation :- 
// all no. is assumed to be 64 bit
// cnt[i] - cnt of numbers, whose ith bit is set
// k should be such that it is divisor of all the numbers in the cnt array
// so by observation 2, we can find gcd of all nos of cnt ==> g
// if g%k ==0 ==> k is our ans



// observation - 2
// gcd({a, b, c}) = x
// then let assume y is a multiple of x, i.e., y%x== 0 ==> 
// y%a = y%b = y%c = 0

class Solution {

public:
    vi solve1(vi& nums) {
        int cnt[64], n = nums.size();

        // cnt[i] - the number of elements having set ith bit
        fr(i, 0, 63) {
            cnt[i] = 0;
            for (auto x : nums) {
                if ((x & (1 << i))) cnt[i]++;
            }
        }

        vi ans;
        fr(k, 1, n) {
            int yes = 1;
            fr(i, 0, 63) {
                if (cnt[i] % k != 0) {
                    yes = 0;
                    break;
                }
            }
            if (yes) ans.push_back(k);
        }

        return ans;
    }



    vi solve2(vi& nums) {
        int cnt[64], n = nums.size(), g = 0;

        // cnt[i] - the number of elements having set ith bit
        fr(i, 0, 63) {
            cnt[i] = 0;
            for (auto x : nums) {
                if ((x & (1 << i))) cnt[i]++;
            }
            g = __gcd(g, cnt[i]);
        }

        vi ans;
        fr(k, 1, n) {
            if (g % k == 0) ans.push_back(k);
        }

        return ans;
    }
};



int32_t main() {
    fastIO();
    Solution sol;

    wt(t) {
        cn(n);
        vi nums(n);
        for (auto& x : nums) cin >> x;
        // auto ans = sol.solve1(nums);
        auto ans = sol.solve2(nums);
        PRT(ans);
    }


    return 0;
}




