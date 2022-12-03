#include<bits/stdc++.h>
using namespace std;
void brute_force(vector<int>& arr){
    int maxhigh =0;
    int res = 0;
    int leftbound = 0,rightbound = arr.size()-1;
    for(int i =0;i<arr.size() ;i++){
        // maximum left elem which is gre then ---9, 7 ,3,2,1
        // cur elem ie arr[i]
       int count1 =0,count2=0;
       int s1 = i,s2 =i;
       // left side max 
       while(s1>=0 && arr[i]<=arr[s1-1]){
        count1++; 
        s1--;
        }
       // right side max
       while(s2<rightbound && arr[i]<=arr[s2+1]){ 
       count2++; 
       s2++;
       }
       int totwight= count1+count2+1;
       cout<<totwight<<" "<<arr[i]<<endl;
       maxhigh = totwight*arr[i];
       res = max(res,maxhigh);
    }
    cout<<res;
}
int main(){
    vector<int> arr = {2,1,3,4,5,6};
    brute_force(arr);
}