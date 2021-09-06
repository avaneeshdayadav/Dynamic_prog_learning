
// CanSum Mentos Jindagi (memoization).

#include "bits/stdc++.h"
using namespace std;


int canSum(int n, int arr[], int targetSum, map<int,int> &memo)
{
    if(memo.find(targetSum) != memo.end())
        return memo[targetSum];
    
    if(targetSum<0)
        return 0;
        
    for(int i=0;i<n;i++)
    {
        if(canSum(n,arr,targetSum-arr[i],memo)==1) // If we are getting true from one of the smaller problem possibilities then just return true from this bigger problem too i.e once we get a 1 we don't want to check other possibilities & directly pass on 1 to upper function call of tree.
        {
            memo[(targetSum-arr[i])] = 1;	// Store in map before returning.
            return memo[targetSum-arr[i]];

        }
            
    }
    
    return 0;
    
}

int main()
{
    map <int,int> memo;
    memo[0] = 1;
    int n;
    cin>>n;
    
    int arr[n],targetSum;
    
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    
    cin>>targetSum;

    cout<<canSum(n,arr,targetSum,memo)<<endl;
    
   
	return 0;
}

