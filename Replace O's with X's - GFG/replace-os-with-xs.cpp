//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
private:
    void dfs(int row , int col , vector<vector<char>> mat , vector<vector<int>>& vis , int delRow[] , int delCol[]){
        vis[row][col] = 1;
        
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0 ; i < 4 ; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == 'O' && vis[nrow][ncol] == 0){
                dfs(nrow , ncol , mat , vis , delRow , delCol);
            }
        }
        
        
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        
        vector<vector<int>> vis(n , vector<int>(m , 0));
        int delRow[] = {-1 , 0 , +1 , 0};
        int delCol[] = {0 , +1 , 0 , -1};
        
        for(int i = 0 ; i < n ; i++){
            if(mat[i][0] == 'O'){
                dfs(i , 0 , mat , vis , delRow , delCol);
            }
            
            if(mat[i][m-1] == 'O'){
                dfs(i , m-1 , mat , vis , delRow , delCol);
            }
        }
        
        for(int i = 0 ; i < m ; i++){
            if(mat[0][i] == 'O'){
                dfs(0 , i , mat , vis , delRow , delCol);
            }
            
            if(mat[n-1][i] == 'O'){
                dfs(n-1 , i , mat , vis , delRow , delCol);
            }
        }
        
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 'O' && vis[i][j] == 0){
                    mat[i][j] = 'X';
                }
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends