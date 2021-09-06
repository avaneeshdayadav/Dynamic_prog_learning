
// CanSum Aam Jindagi (recurssion)

#include "bits/stdc++.h"
using namespace std;


int canSum(int n,int arr[],int targetSum)
{
    if(targetSum == 0)
        return 1;
        
    
    if(targetSum<0)
        return 0;
        
    for(int i=0;i<n;i++)
    {
        if(canSum(n,arr,targetSum-arr[i])==1) // If we are getting true from one of the smaller problem possibilities then just return true from this bigger problem too i.e once we get a 1 we don't want to check other possibilities & directly pass on 1 to upper function call of tree.
            return 1;
    }
    
    return 0;
    
}

int main()
{
    int n;
    cin>>n;
    
    int arr[n],targetSum;
    
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    
    cin>>targetSum;

    cout<<canSum(n,arr,targetSum)<<endl;
    
   
	return 0;
}

