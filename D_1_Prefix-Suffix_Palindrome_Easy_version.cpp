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
    // O(N^2)
    int lenOfLongestPrefixPalindrome(string s) {
        int maxi = 0;
        string tmp;
        for (int i = 0; i < s.size(); i++) {
            tmp += s[i];
            string tmp2 = tmp;
            reverse(tmp2.begin(), tmp2.end());
            if (tmp2 == tmp) maxi = tmp.size();
        }
        return maxi;
    }


    // O(N) // BY KMP
    int lenOfLongestPrefixPalindromeByKMP(string s) {
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        s = s + "#" + tmp;

        int n = s.size();
        vector<int> lps(n, 0); // lps[i] - length of longest prefix which is also suffix ending at i

        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];
            while (j > 0 && s[i] != s[j]) j = lps[j - 1];
            lps[i] = j + (s[i] == s[j]);
        }

        return lps[n - 1]; // length of longest longest prefix which is palindrome
    }

public:
    string solve(string s) {
        int n = s.size();
        int l = 0;
        for (int i = 0, j = n - 1; i < j; i++, j--, l++) {
            if (s[i] != s[j]) break;
            // l++;
        }

        // remaing is from s[l ... (n-l+1)]
        string rem = s.substr(l, n - 2 * l);

        // ans -> s[0...l-1] + sp + s[n-l ... n-1 ]
        // sp -> longest suffix or prefix which is palindrome in s[l...n-l-1]
        string ans = s.substr(0, l);
        if (rem.size()) {
            string rem2 = rem;
            reverse(rem2.begin(), rem2.end());
            // int lenPre = lenOfLongestPrefixPalindrome(rem);
            // int lenSuf = lenOfLongestPrefixPalindrome(rem2);

            int lenPre = lenOfLongestPrefixPalindromeByKMP(rem);
            int lenSuf = lenOfLongestPrefixPalindromeByKMP(rem2);
            ans += (lenPre > lenSuf) ? rem.substr(0, lenPre) : rem.substr(rem.size() - lenSuf, lenSuf);
        }
        ans += s.substr(n - l, l);

        return ans;
    }
};



int32_t main() {
    fastIO();
    Solution sol;

    wt(t) {
        drs(s);
        cout << sol.solve(s) << nl;
    }

    return 0;
}





