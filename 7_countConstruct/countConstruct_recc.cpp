// canConstruct Aam Jindagi (recursion)

#include "bits/stdc++.h"
using namespace std;
 
// Function to substract prefix of given length from the source string
string minusPrefixStr(string source, int len)
{
    string retString="";
    for(int i=len;i<source.length();i++)
    {
        retString=retString+source[i];
    }
    
    return retString;
}

int countConstruct(string target, string arr[],int n)
{
    int count=0;
    
    if(target == "")
        return 1;
    
    for(int i=0;i<n;i++)
    {
        int pos = target.find(arr[i]); // Check if arr[i] is a substring of required target string and if yes get pos of starting character of substring. If not then it means pos = -1
        
        if(pos == 0)// check if substring is a prefix string of target string i.e substring starts from indx 0 in target string.
        {
            string newTarget = minusPrefixStr(target,arr[i].length());
            count = count + countConstruct(newTarget,arr, n);
        }
    }
    
    return count;
}

int main()
{
    int n;
    cin>>n;
    
    string target;
    string arr[n];
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    cin>>target;
    cout<<"Possible no. of ways to construct given target string are "<<countConstruct(target,arr,n)<<endl;
    
    return 0;
    
}


