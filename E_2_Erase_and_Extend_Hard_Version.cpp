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

public:
    // for E1 // n,k < 5000  // O(N^2)
    string solve1(int n, int k, string& s) {
        vector<string> arr;
        for (int i = 0; i < n; i++) {
            string tmp = s.substr(0, i + 1);
            while (tmp.size() < k) {
                tmp += tmp;
            }
            if (tmp.size() > k) tmp = tmp.substr(0, k);
            arr.push_back(tmp);
        }

        sort(arr.begin(), arr.end());
        return arr[0];
    }



    // O(N)
    string solve2(int n, int k, string& s) {
        int i = 1;
        for (; i < n; i++) { // dbafga => dba
            if (s[i] > s[0]) break;
            else if (s[i] == s[0]) {  // dbadbca,    dbabdbaa
                int j = 1, k = i + 1; // compare s[1...(i-1)]  and s[(i+1) .... (n-1)]

                while (j < i && k < n) {
                    if (s[j] == s[k]) j++, k++;
                    else break;
                }

                if (k == n || s[k] > s[j]) {
                    break;
                } else {
                    i = k;
                }

            }
        }

        // after removing some chars from end => s = [0...(i-1)]
        s = s.substr(0, i);

        int sz = s.size();
        if (sz > 2 && s[0] == s[sz - 1] && s[sz - 2] < s[sz - 1]) { // dbcad
            s = s.substr(0, sz - 1);
        }

        while (s.size() < k) s += s;
        if (s.size() > k) s = s.substr(0, k);
        return s;
    }
};



int32_t main() {
    fastIO();
    Solution sol;

    drii(n, k);
    drs(s);

    // cout << sol.solve1(n, k, s) << nl;
    cout << sol.solve2(n, k, s) << nl;


    return 0;
}




