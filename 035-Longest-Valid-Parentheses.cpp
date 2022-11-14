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





// QUE :- https://leetcode.com/problems/valid-parentheses/
class Solution1 {
    bool isOpen(char ch) {
        return (ch == '(' || ch == '{' || ch == '[');
    }
    char closeB(char ch) {
        if (ch == '(') return ')';
        if (ch == '{') return '}';
        return ']';
    }

    int getTop(string& s, int ind) {
        int right = 0;
        while (ind >= 0) {
            if (isOpen(s[ind])) right--;
            else right++;
            if (right < 0) return ind;
            ind--;
        }
        return -1;
    }
public:
    // O(N) space
    bool isValid1(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (isOpen(s[i])) stk.push(s[i]);
            else {
                if (stk.empty()) return false;
                if (s[i] != closeB(stk.top())) return false;
                stk.pop();
            }
        }

        return (stk.empty() ? 1 : 0);
    }

    // O(1) space
    bool isValid(string& s) {
        int top = -1;
        for (int i = 0; i < s.size(); i++) {
            if (isOpen(s[i])) top = i;
            else {
                if (top == -1 || s[i] != closeB(s[top])) return false;
                else {
                    top = getTop(s, top - 1);
                }
            }
        }

        return top == -1;
    }

};








//QUE :- https://leetcode.com/problems/longest-valid-parentheses/
class Solution2 {
public:
    // Using stack // TC - O(N) // SC - O(N)
    int longestValidParentheses1(string s) {
        stack<int> stk;
        stk.push(-1);
        int mxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') stk.push(i);
            else {
                stk.pop();
                if (stk.empty()) stk.push(i);
                else {
                    mxLen = max(mxLen, i - stk.top());
                }
            }
        }
        return mxLen;
    }



    // Using stack // TC - O(N) // SC - O(1)
    int longestValidParentheses2(string s) {
        int open, close, mxLen = 0;

        open = close = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') open++;
            else close++;

            if (open == close) mxLen = max(mxLen, open + close);
            else if (close > open) open = close = 0;
        }

        open = close = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') open++;
            else close++;

            if (open == close) mxLen = max(mxLen, open + close);
            else if (open > close) open = close = 0;
        }
        return mxLen;
    }




    // Using DP // TC - O(N) // SC - O(N)
    int longestValidParentheses(string s) {
        int mxLen = 0, n = s.size();
        int dp[n + 1];
        memset(dp, 0, sizeof dp);

        for (int i = 1; i < n; i++) {
            // if( s[i] == '(' ) dp[i] = 0;
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = 2 + ((i - 2 >= 0) ? dp[i - 2] : 0);
                } else if ((i - dp[i - 1] - 1 >= 0) && (s[i - dp[i - 1] - 1] == '(')) {
                    dp[i] = 2 + dp[i - 1] + ((i - dp[i - 1] - 2 >= 0) ? dp[i - dp[i - 1] - 2] : 0);
                }
                mxLen = max(mxLen, dp[i]);
            }
        }

        return mxLen;
    }
};




int32_t main() {
    fastIO();
    Solution2 sol2;

    string s; cin >> s;
    cout << sol2.longestValidParentheses(s) << nl;


    return 0;
}

