#include<bits/stdc++.h>
using namespace std;



void lcs(string s1,string s2){

 int m = s1.length();
 int n = s2.length();

 int dp[1001][1001] ;
 for(int i = 0 ; i <=m;i++){
	 dp[i][0] = 0;
 }

for(int i = 0 ; i <=n;i++){
	 dp[0][i] = 0;
 }

for(int i = 1 ; i <=m;i++){

 for(int j = 1 ; j <= n;j++){

int q = 0;
if(s1[i-1] == s2[j-1]){
	q = 1 + dp[i-1][j-1];
}
else{
q = max(dp[i-1][j],dp[i][j-1]);
}
dp[i][j] = q;

 }

}
int index = dp[m][n]; 
  
   // Create a character array to store the lcs string 
   char lcs1[index+1]; 
   lcs1[index] = '\0'; // Set the terminating character 
  
   // Start from the right-most-bottom-most corner and 
   // one by one store characters in lcs[] 
   int i = m, j = n; 
   while (i > 0 && j > 0) 
   { 
      // If current character in X[] and Y are same, then 
      // current character is part of LCS 
      if (s1[i-1] == s2[j-1]) 
      { 
          lcs1[index-1] = s1[i-1]; // Put current character in result 
          i--; j--; index--;     // reduce values of i, j and index 
      } 
  
      // If not same, then find the larger of two and 
      // go in the direction of larger value 
      else if (dp[i-1][j] > dp[i][j-1]) 
         i--; 
      else
         j--; 
   } 
  
   // Print the lcs 
   cout <<lcs1<<endl; 
}





int main() {

  string s1,s2;
  cin>>s1>>s2;

  lcs(s1,s2);




	return 0;
}
