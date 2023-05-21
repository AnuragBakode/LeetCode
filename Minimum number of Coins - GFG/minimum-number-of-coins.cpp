//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> coins = {2000 , 500 , 200 , 100 , 50 , 20 , 10 , 5, 2 ,1};
        int i = 0;
        vector<int> ans;
        while(N && i < 10){
            while(N < coins[i]) i++;
            int whole = N / coins[i];
            for(int k = 0 ; k < whole; k++){
                ans.push_back(coins[i]);
            }
            N = N % coins[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends