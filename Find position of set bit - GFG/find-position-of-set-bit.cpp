//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        int setBitCount = 0;
        int ans = 0;
        int i = 0;
        while(N){
            if(N & 1){
                setBitCount++;
                ans = i;
            }
            i++;
            N = N >> 1;
        }
        
        if(setBitCount == 1) return ans +1;
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends