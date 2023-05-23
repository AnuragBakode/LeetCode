//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    
public:
    void helper(vector<vector<int>> &m ,int i , int j , int xd ,int yd ,int &ans , int sum){
        if(i == xd && j == yd){
            if(sum > ans){
                ans = sum;
            }
            return;
        }
        
        m[i][j] = 2;
        
       vector<pair<int , int>> directions = {{0 , 1}, {1 , 0}, {-1, 0}, {0, -1}};
       
       for(auto direction : directions){
           int x = i + direction.first;
           int y = j + direction.second;
           
           if(x >= 0 && x < m.size() && y >= 0 && y < m[0].size() && m[x][y] == 1){
               helper(m , x ,y , xd , yd, ans , sum + 1);
           }
       }
       
       m[i][j] = 1;
        
    }
public:
    int longestPath(vector<vector<int>> m, int xs, int ys, int xd, int yd)
    {
        // code here
        if(m[xs][ys] == 0 || m[xd][yd] ==0) return -1;
        int row = m.size();
        int col = m[0].size();
        int ans = -1;
        int sum = 0;
        
        helper(m , xs , ys , xd , yd, ans , sum);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends