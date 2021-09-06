
// HowSum Aam Jindagi (recurssion)

#include "bits/stdc++.h"
using namespace std;


vector<int> howSum(int arr[], int n, int targetSum,vector<int> &result)
{
    int rem;
    vector<int> ret;
    
    if(targetSum == 0)
    {
        vector<int> v(1);
        return v;
    }
    else if(targetSum<0)
    {
        vector<int> v;
        return v;
    }
    
    for(int i = 0;i<n;i++)
    {
        rem = targetSum - arr[i];
        ret = howSum(arr,n,rem,result);
        
        if(ret.capacity() != 0)
        {
            result.push_back(arr[i]);
            return result;
            
        }
    }
    
    return result;
}


int main()
{
    int n,targetSum;
    vector<int> result;
    
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cin>>targetSum;
    
    howSum(arr,n,targetSum,result);
    
    for(int i = 0;i<result.size();i++)
    {
        cout<<result[i]<<endl;
    }
    
}
