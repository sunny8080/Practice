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


//QUE :- https://leetcode.com/problems/longest-consecutive-sequence/


class Solution {
public:
    // METHOD - 1 // Hashing // O(maxVa - minVal)
    int longestConsecutive1(vector<int>& nums) {
        // hashing
        map<int, int> mpp;
        for (auto x : nums) mpp[x] = 1;

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        int cnt = 0, len = 0;
        for (int i = mn; i <= mx; i++) {
            if (mpp.count(i) > 0) cnt++;
            else {
                len = max(len, cnt);
                cnt = 1;
            }
        }
        len = max(len, cnt);
        return len;
    }



    // METHOD - 2 // Sorting // O(NlogN) 
    int longestConsecutive2(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        // nums.resize( unique(nums.begin(), nums.end()) - nums.begin());
        int len = 1, cnt = 1, prev = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == prev + 1) {
                cnt++;
            } else if (nums[i] != prev) {
                len = max(len, cnt);
                cnt = 1;
            }
            prev = nums[i];
        }
        len = max(len, cnt);
        return len;
    }


    // METHOD - 3 // unordered map // O(N)
    int longestConsecutive3(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        // sort(nums.begin(), nums.end());
        // nums.resize( unique(nums.begin(), nums.end()) - nums.begin());
        unordered_map<int, int> m;

        int maxLen = 1;
        for (auto x : nums) {
            if (m.count(x) > 0) continue;

            bool less = (m.count(x - 1) != 0);
            bool high = (m.count(x + 1) != 0);
            int streak = 0;

            if (!less && !high) { // create new
                m[x] = 1;
            } else if (less && high) { // joint two group
                int len1 = m[x - 1];
                int len2 = m[x + 1];
                streak = len1 + len2 + 1;
                m[x - len1] = m[x + len2] = streak;
                m[x] = streak; // to avoid repeating no
            } else if (less && !high) { // add to right
                int len1 = m[x - 1];
                streak = len1 + 1;
                m[x - len1] = m[x] = streak;
            } else if (!less && high) { // add to left
                int len1 = m[x + 1];
                streak = len1 + 1;
                m[x + len1] = m[x] = streak;
            }
            maxLen = max(maxLen, streak);
        }

        return maxLen;
    }



    // METHOD - 4 // unordered set // O(N)
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for (auto x : nums) st.insert(x);

        // Iterate over all the elements and target those from which a streak can start

        int maxLen = 0;
        for (auto x : nums) {
            // this point can be starting point of the sequence or not
            if (st.find(x - 1) == st.end()) {
                int cnt = 1;
                int next_no = x + 1;
                while (st.find(next_no) != st.end()) {
                    cnt++;
                    next_no++;
                }
                maxLen = max(maxLen, cnt);
            }
        }

        return maxLen;
    }

};



int32_t main() {
    fastIO();
    Solution sol;

    int n; cin >> n;
    vi nums(n);
    for (auto& x : nums) cin >> x;
    cout << sol.longestConsecutive(nums);



    return 0;
}

