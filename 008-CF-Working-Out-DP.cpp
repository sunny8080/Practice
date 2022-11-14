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



// QUE :- https://codeforces.com/problemset/problem/429/B


int r, c;
int boy_start[1005][1005];
int boy_end[1005][1005];
int girl_start[1005][1005];
int girl_end[1005][1005];
int cal[1005][1005]; // calorie


class Solution {

public:
    int solve() {
        // fill all the dp wiht bottom up manner

        // boy starts from (1, 1) and goes to (i, j)
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                boy_start[i][j] = cal[i][j] + max(boy_start[i][j - 1], boy_start[i - 1][j]);
            }
        }

        // boy starts from (r, c) and goes to (i, j) // ie in reverse direction
        for (int i = r; i >= 1; i--) {
            for (int j = c; j >= 1; j--) {
                boy_end[i][j] = cal[i][j] + max(boy_end[i][j + 1], boy_end[i + 1][j]);
            }
        }


        // boy starts from (r, 1) and goes to (i, j)
        for (int i = r; i >= 1; i--) {
            for (int j = 1; j <= c; j++) {
                girl_start[i][j] = cal[i][j] + max(girl_start[i][j - 1], girl_start[i + 1][j]);
            }
        }

        // boy starts from (1, c) and goes to (i, j) // ie in reverse direction
        for (int i = 1; i <= r; i++) {
            for (int j = c; j >= 1; j--) {
                girl_end[i][j] = cal[i][j] + max(girl_end[i][j + 1], girl_end[i - 1][j]);
            }
        }

        int ans = 0;

        // Iterate over all the meeting points points // b/w (2, 2) to (r-c, c-1)
        // consider this point as actuak meeting point and calculate max possible ans
        for (int i = 2; i < r; i++) {
            for (int j = 2; j < c; j++) {
                int op1 = boy_start[i][j - 1] + boy_end[i][j + 1] + girl_start[i + 1][j] + girl_end[i - 1][j];
                int op2 = boy_start[i - 1][j] + boy_end[i + 1][j] + girl_start[i][j - 1] + girl_end[i][j + 1];
                ans = max({ ans, op1, op2 });
            }
        }
        return ans;
    }
};



int32_t main() {
    fastIO();
    Solution sol;

    mems(boy_start, 0);
    mems(boy_end, 0);
    mems(girl_start, 0);
    mems(girl_end, 0);
    mems(cal, 0);

    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) cin >> cal[i][j];
    }
    cout << sol.solve() << nl;




    return 0;
}

