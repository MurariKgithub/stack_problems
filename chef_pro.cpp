#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long long int t;
	while(t--){
	    long long int n,even=0,odd =0;
	    cin >>n;
	    for(int i=0 ;i<n ;i++){
	        int x;
	        cin >>x;
	        if(x%2) odd++;
	        else even++;
	    }
        cout<<odd<<" "<<even<<endl;
	    if(odd==2) cout<<"Yes";
	    else cout<<"NO";
	}
	return 0;
}
