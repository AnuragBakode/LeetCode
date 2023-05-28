//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here
        int XOR = 0;
        int n = nums.size();
        
        for(int i = 0 ; i < n ; i++){
            XOR ^= nums[i];
        }
        
        int setBitPosi = 0;
        
        while(XOR){
            if(XOR & 1) break;
            setBitPosi++;
            XOR = XOR >> 1;
        }
        
        int XOR1 = 0;
        int XOR2 = 0;
        
        vector<int> ans;
        int map = 1 << setBitPosi;
        for(int i = 0 ; i < n ;i++){
            if(nums[i] & map) XOR1 ^= nums[i];
            else XOR2 ^= nums[i];
        }
        
        ans.push_back(XOR1);
        ans.push_back(XOR2);
        sort(ans.begin() , ans.end());
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends