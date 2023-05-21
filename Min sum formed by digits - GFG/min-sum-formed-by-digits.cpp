//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        
        sort(arr , arr+n);
        
        int i = 0;
        int j = 1;
        
        long long num1 = 0;
        long long num2 = 0;
        while(i < n && j < n){
            num1 = (num1* 10) + arr[i];
            num2 = (num2 * 10) + arr[j];
            
            i+=2;
            j+=2;
        }
        
        if(i == n -1){
            num1 = (num1 * 10) + arr[i];
        }
        
        return (num1 + num2);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends