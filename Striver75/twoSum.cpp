#include<bits/stdc++.h>
using namespace std ;

//Global Variable
int target = 15;

//Brute force Approach for first Variant in this output will be like(YES or NO)

string sumFind(int* arr, int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]+ arr[j] == target)
            return("Yes");
        }
    }
    return("No");
}

//Brute force Approach for Second Variant inn this variant output will be (indices of element or {-1,-1})
//Time complexity is O(n^2) kyuki yha pe nested loop hai...
   
vector<int>targetSum(int* arr,int size)
{
    vector<int>ans;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]+ arr[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return(ans);
            }
        }
    }
    return{-1,-1};
}

// A better approach Using Hashing 
//Time complexity O(NlogN)  N for loop and logN for searching Element in map 

vector<int> UsingHash(vector<int>&arr,int size)
{
    unordered_map<int,int>mpp;
    for(int i=0;i<size;i++)
    {
        int num = arr[i];
        int moreNeeded = target - num;
        if(mpp.find(moreNeeded)!=mpp.end())
        {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return{-1,-1};
}

//There is one more optimized approach is there to implemet this (I implemet it Letter)


int main()
{

    int arr[] = {2,6,5,8,11};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<< sumFind(arr,size)<<endl;
    vector<int>result=targetSum(arr,size);
    if(result[0]!=-1)
    cout<<"Indices "<<result[0]<<" "<<result[1]<<endl;
    else
    cout<<"No valid Pair Found"<<endl;


   //Hashing ke hisab se main function ka setup

   vector<int>array = {2,6,5,8,11};
   vector<int>Hresult = UsingHash(array,size);
       if(Hresult[0]!=-1)
    cout<<"Indices Hash :"<<Hresult[0]<<" "<<Hresult[1]<<endl;
    else
    cout<<"No valid Pair Found"<<endl;

}