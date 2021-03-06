#include<bits/stdc++.h>
using namespace std;
using li = long int;
using lli  = long long int;

#define eb emplace_back
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define pi pair <int,int>
#define vi vector <int>
#define vl vector <lli>
#define p(x) cout << #x << " is " << (x) << " on Line:" << __LINE__ << " \n";
#define pl(x) for(auto &y:x) cout << y << " "; cout << "\n";

//The same as for the undirected one just don't avoid parent

void dfs(int src, vi &s, int vis[], vector <vi> &graph){
	vis[src] = 1;
	s.eb(src);
	for(auto &x: graph[src]){
		if(vis[x] == 0){
			dfs(x,s,vis,graph);
		}
		else if(vis[x] == 1){
				cout << "cycle \n";
				stack <int> temp;
				int pos = ((int)s.size())-1;
				while(pos >= 0 && s[pos] != x){
					temp.push(s[pos]);
					--pos;
				}
				cout << x << " ";
				while(!temp.empty()){
					cout << temp.top() << " ";
					temp.pop();
				}
				cout << "\n";
		}
	}
	vis[src] = 2;
	s.pop_back();
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector <vi> graph(n, vi (0));
  for(int i = 0; i < m; ++i){
	  int a,b;
	  cin >> a >> b;
	  graph[a].eb(b);
  }
  int vis[n] = {0};
  vi s;
  for(int i = 0; i < n; ++i){
	  if(vis[i] == 0){
		  dfs(i,s,vis,graph);
	  }
  }
}
//Sample Input

//14 16
//0 1 
//1 2 
//2 3
//3 4
//4 5
//5 6
//6 7
//7 8
//8 5
//5 9
//9 10
//10 11
//11 3
//7 12
//12 13
//13 7

//Sample Output

//cycle 
// 5 6 7 8
//cycle 
// 7 12 13
//cycle
// 3 4 5 9 10 11
