//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDiagonal(int N, vector<vector<int>> A)
	{
		// Your code goes here
		int row = 0;
		int col  = 0;
		
		vector<int> ans;
		
		while(col < N){
		    int r = row;
		    int c = col;
		    
		    while(r < N && c >= 0){
		        ans.push_back(A[r][c]);
		        r++;
		        c--;
		    }
		    
		    col++;
		}
		
		col--;
		row++;
		
		while(row < N){
		    int r = row;
		    int c = col;
		    
		    while(r < N && c >= 0){
		        ans.push_back(A[r][c]);
		        r++;
		        c--;
		    }
		    
		    row++;
		}
		
		return ans;
		
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDiagonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends