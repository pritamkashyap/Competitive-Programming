#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int maxProfit(int wt[],int profit[],int n,int bag_wt){

if(bag_wt==0 || n==0)
return 0;

if(dp[n][bag_wt]!=-1)
return dp[n][bag_wt];

if(bag_wt>=wt[n-1])
return dp[n][bag_wt]=max(profit[n-1]+maxProfit(wt,profit,n-1,bag_wt-wt[n-1]),maxProfit(wt,profit,n-1,bag_wt));

else
return dp[n][bag_wt]=maxProfit(wt,profit,n-1,bag_wt);

}
int main() {

int t; cin>>t;
while(t-->0){
int n; cin>>n;
int bag_wt; cin>>bag_wt;

int profit[n];
for(int i=0;i<n;i++) cin>>profit[i];

int wt[n];
for(int i=0;i<n;i++) cin>>wt[i];

memset(dp,-1,sizeof(dp));
cout<<maxProfit(wt,profit,n,bag_wt)<<endl; 
}

return 0;
}
