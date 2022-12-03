#include<bits/stdc++.h>
using namespace std;
long long subArrayRanges(vector<int>& nums){
    stack<int> stack,stack2;
    int n = nums.size();
    vector<int> left_min_b(n,1),right_min_b(n,1);
    vector<int> left_max_b(n,1),right_max_b(n,1);
    // for (int i = 0; i < n; i++){
    //   left_min_b.push_back(1);
    // }
    for(int i =0 ;i<n ;i++){
      while(!stack.empty() && nums[stack.top()]>nums[i]){
        left_min_b[i] += left_min_b[stack.top()];
        stack.pop();
      }
      stack.push(i);
    }
  //  stack = new stack<int>;
    // for(auto it:right_min_b) cout<<it<<" ";
    // cout<<endl;
    for(int i =n-1 ;i>=0 ;i--){
      while(!stack2.empty() && nums[stack2.top()]>=nums[i]){
        right_min_b[i] += right_min_b[stack2.top()];
        stack2.pop();
      }
      stack2.push(i);
    }
    while(!stack.empty()) stack.pop();
    while(!stack2.empty()) stack2.pop();
    for(auto it:left_min_b) cout<<it<<" ";
    cout<<endl;
    for(auto it:right_min_b) cout<<it<<" ";
    cout<<endl;
     for(int i =0 ;i<n ;i++){
      while(!stack.empty() && nums[stack.top()]<nums[i]){
        left_max_b[i] += left_max_b[stack.top()];
        stack.pop();
      }
      stack.push(i);
    }
  //  stack = new stack<int>;
    // for(auto it:right_min_b) cout<<it<<" ";
    // cout<<endl;
    for(int i =n-1 ;i>=0 ;i--){
      while(!stack2.empty() && nums[stack2.top()]<=nums[i]){
        right_max_b[i] += right_max_b[stack2.top()];
        stack2.pop();
      }
      stack2.push(i);
    }
    for(auto it:left_max_b) cout<<it<<" ";
    cout<<endl;
    for(auto it:right_max_b) cout<<it<<" ";
    cout<<endl;
    int res =0;
    for(int i =0 ;i<n ;i++){
      int prod = left_max_b[i]*right_max_b[i]-left_min_b[i]*right_min_b[i];
      res+=prod*nums[i];
    }
  cout<<res;
}
int main(){
  vector<int> nums = {1,3,3};
  subArrayRanges(nums);
}