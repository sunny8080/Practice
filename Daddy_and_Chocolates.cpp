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

const ll N = 1000000 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}



struct query {
    int l, r, q_ind, block_ind;
    bool operator<(query& q2) {
        if (block_ind < q2.block_ind) return 1;
        if (block_ind > q2.block_ind) return 0;
        return (r < q2.r);
    }
};


int freq[N];
int cost = 0;
vi nums;
int n, m, rn;
vector<query> q;



class Solution {
    void add(int x) {
        int oldCostX = freq[x] * freq[x] * x;
        freq[x]++;
        int newCostX = freq[x] * freq[x] * x;
        cost += (newCostX - oldCostX);
        // cout<<oldCostX<<sp<<newCostX<<sp<<cost<<nl;
    }

    void remove(int x) {
        int oldCostX = freq[x] * freq[x] * x;
        freq[x]--;
        int newCostX = freq[x] * freq[x] * x;
        cost += (newCostX - oldCostX);
    }

    void adjust(int& curr_l, int& curr_r, int l, int r) {
        // fix l
        while (l < curr_l) add(nums[--curr_l]);

        while (curr_l < l) remove(nums[curr_l++]);

        // fix r
        while (r < curr_r) remove(nums[curr_r--]);

        while (curr_r < r) add(nums[++curr_r]);
    }

public:
    vi solve() {
        vi ans(m);

        sort(all(q));
        mems(freq, 0);
        cost = 0;

        int curr_l = q[0].l, curr_r = q[0].r;
        for (int i = curr_l; i <= curr_r; i++) {
            add(nums[i]);
        }
        ans[q[0].q_ind] = cost;

        for (int i = 1; i < m; i++) {
            adjust(curr_l, curr_r, q[i].l, q[i].r);
            ans[q[i].q_ind] = cost;
        }

        return ans;
    }
};



int32_t main() {
    fastIO();
    Solution sol;

    cin >> n >> m;
    rn = sqrt(n);
    nums.resize(n);
    q.resize(m);
    for (auto& x : nums) cin >> x;

    for (int i = 0; i < m; i++) {
        cn(l); cn(r);
        tie(q[i].l, q[i].r, q[i].q_ind, q[i].block_ind) = make_tuple(l - 1, r - 1, i, l / rn);
    }

    auto ans = sol.solve();
    for (auto x : ans) cout << x << nl;



    return 0;
}

