//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    void dfs(int sr , int sc , vector<vector<int>>& img , vector<vector<int>>& ans , int newColor , int initialColor , int deltaRow[] , int deltaCol[]){
        ans[sr][sc] = newColor;
        
        int row = img.size();
        int col = img[0].size();
        
        for(int i = 0 ; i < 4 ; i++){
            int nrow = sr + deltaRow[i];
            int ncol = sc + deltaCol[i];
            
            if(nrow >= 0 && nrow < row && ncol >= 0 && ncol < col && img[nrow][ncol] == initialColor && ans[nrow][ncol] != newColor){
                dfs(nrow , ncol , img , ans , newColor , initialColor , deltaRow , deltaCol);
            }
        }
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<vector<int>> ans = image;
        int initialColor = image[sr][sc];
        int deltaRow[] = {-1 , 0 , +1, 0};
        int deltaCol[] = {0 , +1 , 0 , -1};
        
        dfs(sr , sc , image , ans , newColor , initialColor , deltaRow , deltaCol);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends