#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define f(i,a,b) for(long long i=a;i<=b;i++)
#define fr(i,a,b) for(long long i=a;i>=b;i--)
#define ain(a,n) for(ll i=0;i<n;i++)cin>>(a)[i]
#define vll vector<ll>
#define show(a) for(auto x:a)cout<<x<<" ";
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
class ST{
	vector<ll> seg,lazy;
public:
	ST(ll n)
	{
		seg.resize(4*n);
		lazy.resize(4*n);
	}

	void build(ll ind,ll low,ll high,vll &a)
	{
		if(low==high)
		{
			seg[ind]=a[low];
			return;
		}
		ll mid=(low+high)/2;
		build(2*ind+1,low,mid,a);
		build(2*ind+2,mid+1,high,a);
		seg[ind]=seg[2*ind+1]+seg[2*ind+2];

	}

	void update(ll ind,ll l,ll r,ll low,ll high,ll val)
	{
		//update previous updates and propagate downwards
		if(lazy[ind]!=0)
		{
			seg[ind]+=(high-low+1)*lazy[ind];
			if(low!=high)//has childrens
			{
				lazy[2*ind+1]+=lazy[ind];
				lazy[2*ind+2]+=lazy[ind];
			}
			lazy[ind]=0;
		}

		if(r<low or high<l)
			return;
		if(l<=low and high<=r)
		{
			seg[ind]+=(high-low+1)*val;
			if(low!=high)
			{
				lazy[2*ind+1]+=val;
				lazy[2*ind+2]+=val;
			}
			return;
		}
		//no overlap
		ll mid=(low+high)/2;
		update(2*ind+1,l,r,low,mid,val);
		update(2*ind+2,l,r,mid+1,high,val);
		seg[ind]=seg[2*ind+1]+seg[2*ind+2];

	}

	ll query(ll ind,ll l,ll r,ll low,ll high)
	{
		//update previous updates and propagate downwards
		if(lazy[ind]!=0)
		{
			seg[ind]+=(high-low+1)*lazy[ind];
			if(low!=high)//has childrens
			{
				lazy[2*ind+1]+=lazy[ind];
				lazy[2*ind+2]+=lazy[ind];
			}
			lazy[ind]=0;
		}

		if(r<low or high<l)
			return 0ll;
		if(l<=low and high<=r)
			return seg[ind];
	
		//no overlap
		ll mid=(low+high)/2;
		ll left=query(2*ind+1,l,r,low,mid);
		ll right=query(2*ind+2,l,r,mid+1,high);
		return left+right;


	}


};
void init_code(){
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

  
void solve()
{
	ll n;
	cin>>n;
	vll a(n);
	ain(a,n);
	ST st(n);
	st.build(0,0,n-1,a);

    

        
}
 
 
int main() {
#ifndef ONLINE_JUDGE
   freopen("Error.txt", "w", stderr);
#endif
   init_code();
   // ll t;
   // cin>>t;
   // while(t--)
   
     solve();
   
return 0;
  
 
    


}