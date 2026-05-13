#include <iostream>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

const int MAXN = 1e5 + 5;
vector<vector<int>> adj(MAXN);
bool dead[MAXN];
vector<int> preorder;
int query_type[MAXN], query_val[MAXN];

void dfs(int u) {
  preorder.push_back(u);

  for(int v : adj[u]){
    dfs(v);
  }
}

int main() {
  FAST_IO;
  int q;
  cin >> q;

  int current_id = 1;
  for (int i = 0; i < q; ++i) {
    cin >> query_type[i] >> query_val[i];
    
    if (query_type[i] == 1) {
      current_id++;
      adj[query_val[i]].push_back(current_id);
      query_val[i] = current_id;
    }
  }

  dfs(1);

  int monarch_ptr = 0; 
  for(int i = 0; i < q; ++i){
    if(query_type[i] != 1){
      dead[query_val[i]] = true;
            
      while(dead[preorder[monarch_ptr]]){
        monarch_ptr++;
      }
      cout << preorder[monarch_ptr] << "\n";
    }
  }

  return 0;
}
