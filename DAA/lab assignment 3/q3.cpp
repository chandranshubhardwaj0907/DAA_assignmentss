// 3. 0/1 KNAPSACK PROBLEM:
#include<iostream>
#include<vector> using
namespace std;
int max(int a,int b)
{
if(a>b) return a; else
return b;
}
int knapsack(int wt[],int profit[],int n,int W)
{
vector<vector<int> > ks (n+1,vector<int>(W+1));
for(int i=0;i<=n;i++)
{
for(int w=0;w<=W;w++)
{
if(i==0||w==0)
{
//if either the row or the column is 0,i.e,the first row and column of the matrix,then we initialise it to
0 ks[i][w]=0;
}
else if(wt[i-1]<=w)
{
//we can insert
ks[i][w]=max(profit[i-1]+ks[i-1][w-wt[i-1]],ks[i-1][w]);
}
else
{ ks[i][w]=ks[i-1][w];
}}}
//start checking from last val return
ks[n][W];
}

int main()
{
int profit[]={60,100,120}; int
wt[]={10,20,30}; int
size=sizeof(profit)/sizeof(profit[0]);
int W=50;
cout<<knapsack(wt,profit,size,W); return
0;
}
//time complexity=O(n*w) OUTPUT:

