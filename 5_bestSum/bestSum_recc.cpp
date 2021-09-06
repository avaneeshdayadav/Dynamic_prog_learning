// bestSum Aam Jindagi (recursion)

#include "bits/stdc++.h"
using namespace std;

vector<int> bestSum(int arr[], int n, int targetSum, map<int,vector<int>> &memo)
{
    int rem=0;
    vector<int> ret,shortestComb;

    if(targetSum == 0)
    {
        vector<int> v(1);
        v.pop_back();
        return v; // Here returned vector is not null (i.e capacity!=0) but size is 0
    }
    else if(targetSum < 0)
    {
        vector<int> v;
        return v; // Here returned vector is null (i.e capacity=0) and size is also 0
    }
    
    for(int i=0;i<n;i++)
    {
        rem = targetSum - arr[i];
        ret = bestSum(arr,n,rem,memo);
        
        if(ret.capacity() != 0) // Checking if returned vector is not null
        {
            ret.push_back(arr[i]); // Pushing current arr[i] in returned combination
            
            // Checking if this new combination size is less than already smallest combination.
            if(shortestComb.capacity()==0 || ret.size() < shortestComb.size())
                shortestComb = ret;
            
        }
    }
    
    return shortestComb; // Returning this shortest combination to upper called function node in tree.
}

int main()
{
    int n,targetSum;
    vector<int> result;
    map<int,vector<int>> memo;
    
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cin>>targetSum;
    
    result = bestSum(arr,n,targetSum,memo);
    
    if(result.capacity() == 0)
    {
        cout<<"Not Possible"<<endl;
        return 0;
    }
    
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
}

