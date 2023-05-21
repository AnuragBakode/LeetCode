//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int findPivot(int nums[] , int l , int h){
        if(nums[l] < nums[h]) return -1;
        else{
            while(l <= h){
            int mid = (l + h) / 2;
            if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1] ) return mid;
            if(nums[mid] < nums[mid + 1] && nums[mid] > nums[0]) l = mid + 1;
            else h = mid - 1;
        }
        }
        
    }
    
    int binarySearch(int arr[] , int l , int r, int x){
        while (l <= r) {
            int m = l + (r - l) / 2;
     
            
            if (arr[m] == x)
                return m;
            if (arr[m] < x)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
    
    public:
    int search(int nums[], int l, int h, int key){
        
        // if(l == h) return -1;
        
        int pivot = findPivot(nums , l , h);
        if(pivot == -1){
           return binarySearch(nums , l , h , key);
        }
        else{
            int firsthalf = binarySearch(nums , l , pivot , key);
            int secondhalf = binarySearch(nums , pivot + 1,h , key);
            
            if(firsthalf != -1)
                return firsthalf;
            else return secondhalf;
        }
        
        return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends