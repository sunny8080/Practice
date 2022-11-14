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




// To flush the buffer
// fflush(stdout);       in c++ ()(if using printf scanf)
// cout<<flush;          in c++ ()(if using cin cout)
// System.out.flush();   in Java
// stdout.flush()        in python

// endl actually works as cout<<'\n'<<flush;



// QUE :- https://codeforces.com/problemset/problem/1167/B
class Solution2 {
    int query(int i, int j) {
        cout << "? " << i << sp << j << endl;
        int t; cin >> t;
        return t;
    }
public:
    void solve() {
        vi nums = { 4, 8, 15, 16, 23, 42 };
        vi a(4);

        for (int i = 0; i < 4; i++) {
            a[i] = query(i + 1, i + 2);
        }

        do {
            int can=1;
            for (int i = 0; i <=3; i++) {
                if( nums[i]*nums[i+1] != a[i] ){
                    can=0;
                    break;
                }
            }
            if(can){
                cout<<"! ";
                for(auto x : nums ) cout<<x<<sp;
                cout<<endl;
                break;
            }
        } while (next_permutation(nums.begin(), nums.end()));
    }
};



int32_t main() {
    fastIO();
    Solution2 sol2;
    sol2.solve();


    return 0;
}
    