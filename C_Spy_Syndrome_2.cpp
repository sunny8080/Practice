#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll                 long long
#define int                long long
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


struct node {
    node* nxt[26];
    int cnt = 0, ended = 0, ind = -1;
    node() {
        fr(i, 0, 25) nxt[i] = NULL;
    }
};



class Trie {
    node* root = new node();
public:
    // s should in lowercase 
    void insert(string& s, int ind) {
        node* cur = root;
        for (auto ch : s) {
            int t = ch - 'a';
            if (!cur->nxt[t]) cur->nxt[t] = new node();
            cur->cnt++;
            cur = cur->nxt[t];
        }
        cur->ind = ind;
        cur->cnt++;
        cur->ended = 1;
    }

    int search(string& s, int pos, vi& dp) {
        node* cur = root;
        for (int i = pos; i >= 0; i--) {
            int t = s[i] - 'a';
            if (!cur->nxt[t]) return -1;
            cur = cur->nxt[t];
            if (cur->ended && dp[i] >= 0) return cur->ind;
        }
        return -1;
    }

};




class Solution {
    Trie t;
public:
    string solve(string& s, vector<string>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            string tmp = arr[i];
            for (auto& ch : tmp) ch = tolower(ch);
            t.insert(tmp, i);
        }

        int n = s.size();
        vi dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = t.search(s, i - 1, dp);
        }

        // PRT(dp);

        string ans;
        while (n > 0) {
            ans = arr[dp[n]] + " " + ans;
            n -= arr[dp[n]].size();
        }
        ans.erase(ans.size() - 1); // remove extra space
        return ans;
    }


};



int32_t main() {
    fastIO();
    Solution sol;

    dri(m);
    drs(s);

    dri(n);
    vector<string> arr(n);
    rvi(arr);

    cout << sol.solve(s, arr) << nl;


    return 0;
}




