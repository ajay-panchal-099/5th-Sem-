/*
 *
 * Author :  Ajay Panchal
 * B.TECH  CSE STUDENT
 * LOVELY PROFESSIONAL UNIVERSITY
 * BATCH : 2018-2022
 * GITHUB LINK : https://github.com/ajay-panchal-099
 * PROBLEM STATEMENT :
 */

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>                  ii;
typedef vector<int>                    vi;
typedef vector<bool>                   vb;
typedef vector<vi>                     vvi;
typedef vector<ii>                     vp;
typedef unordered_map<int,int>         umap_ii;
typedef unordered_map<char,int>        umap_ci;
typedef unordered_map<string,int>      umap_si;
typedef unsigned long long int         ull;
typedef pair<int,int>                  ii;

#define int                            long long
#define fi                             first
#define se                             second
#define INF                            0x3f3f3f3f
#define PI                             3.1415926535897932384626
#define MOD                            1000000007
#define pb                             push_back
#define uset                           unordered_set
#define pq_max                         priority_queue<int>
#define pq_min                         priority_queue<int,vector<int>,greater<int>>
#define mp                             make_pair  //Better use {}
#define size5                          100010

//LOOPS
#define For(i,b)                       for(int i=0;i<b;i++)
#define FoR(i,a,b)                     for(int i=a;i>=b;i--)
#define FOR(i,a,b)                     for(int i=a;i<b;i++)
#define foreach(v, c)                  for(auto v:c)
#define nested(i,a,b,j,c,d)            for(int i=a;i<b;i++){ for(int j=c;j<d;j++)
//#define foreach(v, c)                for( auto v = (c).begin();  v != (c).end(); ++v)
#define min3(a,b,c)                    min(a,min(b,c))
#define min4(a,b,c,d)                  min(min(a,b),min(c,d))
#define maxall(v)                      *max_element(all(v))
#define minall(v)                      *min_element(all(v))
#define all(a)                         a.begin(), a.end()
#define MS0(X)                         memset((X), 0, sizeof((X)))
#define MS1(X)                         memset((X), -1, sizeof((X)))
#define whileNE(x)                     while(!x.empty())
#define present(c,x)                   ((c).find(x) != (c).end())
#define TCase                          int ___T, case_n = 1; cin>>___T; while (___T-- > 0)

// directions
const int fx[4][2] =                   {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] =                  {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

// Some common useful functions
#define maX                            INF
#define miN                            INT_MIN
#define checkbit(n,b)                  ((n >> b) & 1)
#define INDEX(arr,ind)                 (lower_bound(all(arr),ind)-arr.begin())
#define REMAX(a,b)                     (a)=max((a),(b)) // set a to the maximum of a and b
#define REMIN(a,b)                     (a)=min((a),(b));
#define sz(a)                          (int)(a.size())
#define len(a)                         (int)(a.length())
#define UB(x,a)                        (upper_bound(all(a),x)-a.begin())
#define LB(a,x)                        (lower_bound(all(a),x)-a.begin())
#define NP(a)                          next_permutation(all(a))

#define print(x)                       cout<<x;
#define print2(x,y)                    cout<<x<<" "<<y;
#define println(x)                     cout<<x<<'\n';
#define accept_arr(N,arr)              int N; cin>>N; int arr[N]; For(i,N) cin>>arr[i];
#define print1d(arr,length)            for(int i=0;i<length;i++) cout<<arr[i]<<" "; cout<<'\n';
#define print1D(arr,start,length)      for(int i=start;i<length;i++) cout<<arr[i]<<" "; cout<<'\n';
#define print2d(arr,n)                 For(i,n){For(j,n){cout<<arr[i][j]<<" ";}cout<<endl;}
#define print2D(arr,m,n)               For(i,m){For(j,n){cout<<arr[i][j]<<" ";}cout<<endl;}
#define gets(n)                        getline(cin,n); cin.ignore();
#define debug(x)                       cerr << #x << ": " << x << endl;
#define debug2(x, y)                   cerr << #x << ": " << x << " | " << #y << ": " << y << endl;

#define fast_io                        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sublimeProblem                 freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

int32_t main()
{
    fast_io;
    // IO Problem;

    int n;
    cin>>n;

    int arr[n][3];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin>>arr[i][j];
        }
    }

    int dp[n][3];

    for (int i = 0; i < n; ++i) {
        if(i == 0){
            dp[i][0] = arr[0][0];
            dp[i][1] = arr[0][1];
            dp[i][2] = arr[0][2];
        }
        else{
            dp[i][0] = arr[i][0] + max( dp[i-1][1] , dp[i-1][2]);
            dp[i][1] = arr[i][1] + max(dp[i-1][0] , dp[i-1][2]);
            dp[i][2] = arr[i][2] + max( dp[i-1][1] , dp[i-1][0]);
        }
    }


   /* for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    int mx = INT_MIN;

    for (int i = 0; i < 3; ++i) {
        mx = max(mx, dp[n-1][i]);
    }

    cout<<mx<<endl;

    return 0;
}