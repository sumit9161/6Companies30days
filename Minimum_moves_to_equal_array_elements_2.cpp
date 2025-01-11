#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    int ans=0,median=nums[n/2];
    for(int i=0;i<n;i++){
        ans+=abs(median-nums[i]);
    }
    cout<<ans<<endl;
}