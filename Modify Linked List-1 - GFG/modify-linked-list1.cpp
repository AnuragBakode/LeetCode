//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    struct Node* middelNode(Node* root){
        Node* slow = root;
        Node* fast = root;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast) return slow->next;
        return slow;
    }
    
    public:
    struct Node* reverse(Node* root){
        Node* pre = NULL;
        Node* next = NULL;
        
        while(root != NULL){
            next = root->next;
            root->next = pre;
            pre = root;
            root = next;
        }
        
        return pre;
    }
    
    public:
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
        Node* middle = middelNode(head);
        Node* ans = head;
        
        Node* middleReverse = reverse(middle);
        Node* pre = middleReverse;
        
        while(middleReverse){
            int temp = head->data;
            head->data =  middleReverse->data - head->data ;
            middleReverse->data = temp;
            head= head->next;
            middleReverse  = middleReverse->next;
            
        }
        
        reverse(pre);
        
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends