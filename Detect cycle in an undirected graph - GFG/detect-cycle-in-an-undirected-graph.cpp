//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    // bool bfs(vector<int> adj[] , vector<int> &vis , int start){
    //     queue<pair<int, int>> q;
    //     q.push({start , -1});
        
    //     vis[start] = 1;
        
    //     while(!q.empty()){
    //         int node = q.front().first;
    //         int cameFrom = q.front().second;
    //         q.pop();
            
    //         for(auto it : adj[node]){
    //             if(!vis[it]){
    //                 q.push({it , node});
    //                 vis[it] = 1;
    //             }
                
    //             else if(it != cameFrom){
    //                 return true;
    //             }
    //         }
    //     }
        
    //     return false;
    // }
    bool dfs(vector<int> adj[] , vector<int> &vis , int start , int cameFrom){
        vis[start] = 1;
        
        for(auto it : adj[start]){
            if(!vis[it]){
              if(dfs(adj , vis , it , start) == true) return true;
            }
            
            else if(it != cameFrom) return true;
        }
        
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V , 0);
        for(int i = 0  ; i < V ; i++){
            if(!vis[i]){
                if(dfs(adj , vis , i , -1)) return true;
            }
            
        }
        
        return false;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends