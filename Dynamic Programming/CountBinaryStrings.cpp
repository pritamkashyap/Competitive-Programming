#include<iostream>
using namespace std;


long int b_s(int long n){

long int  a[n], b[n]; 
    a[0] = b[0] = 1; 
    for (int i = 1; i < n; i++) 
    { 
        a[i] = a[i-1] + b[i-1]; 
        b[i] = a[i-1]; 
    } 
    return a[n-1] + b[n-1]; 
}

int main() {


	int t;
	cin>>t;
	while(t--){
 long int n;
  cin>>n;
  cout<<b_s(n)<<endl;


	}
	return 0;
}
