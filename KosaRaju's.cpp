#include<bits/stdc++.h>
#include <map> 
// #include<string>
// #include<vector>
#include <algorithm> 
#include<map>
#define ll long long
#define vl vector<ll>
#define vpl vector<pair<ll,ll>>
#define f(i,a,b) for (ll i=a;i<b;i++)
#define rf(i,b,a) for(ll i=b;i>=a;i--)
#define pb emplace_back
#define all(C) C.begin(), C.end()
#define pl pair<ll,ll>
#define F first
#define S second
#define seea(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define show(a,n) f(i,0,n) cout<<a[i]<<" "; cout<<endl;
#define tk1(a) ll a; cin>>a;
#define tk2(a,b) ll a,b; cin>>a>>b;
#define tk3(a,b,c) ll a,b,c; cin>>a>>b>>c;
#define tk4(a,b,c,d) ll a,b,c,d; cin>>a>>b>>c>>d;
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
#define nl cout<<'\n';
#define endl '\n'
#define mod 1000000007

#define MAXN 100001
using namespace std;

void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,stack<int>&st){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,st);
        }
    }
    st.push(node);
}
int main(){
    long long n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    vector<vector<int>>reveradj(n);
    f(i,0,m){
       long long u,v,wt;
       cin>>u>>v;
       u--;
       v--;
       adj[u].pb(v);
       reveradj[v].pb(u);
    }
    vector<int>vis(n,0);
    stack<int>st;
    f(j,0,n){
        if(!vis[j]){
            dfs(j,adj,vis,st);
        }
        
    }
    
    vector<int>newvis(n,0);
    vector<vector<int>>ans;
    while(st.size()){
      int x=st.top();
      st.pop();
      if(!newvis[x]){
        stack<int>newst;
        dfs(x,reveradj,newvis,newst);
        vector<int>al;
        while(newst.size()){
          al.pb(newst.top());
          newst.pop();
        }
        ans.pb(al);
      }
    }
    
    return 0;
}
