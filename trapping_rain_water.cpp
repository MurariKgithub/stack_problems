#include<bits/stdc++.h>
using namespace std;
int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_b;
        vector<int> right_b;
        left_b.push_back(height[0]);
        int k = 1;
        for(int i=1 ;i<height.size() ;i++){
            left_b.push_back(max(height[i],left_b[i-1]));
        }
        right_b.push_back(height[n-1]);
        for(int i=height.size()-2 ;i>=0 ;--i){
            right_b.push_back(max(height[i],right_b[k-1]));
            cout<<max(height[i],right_b[i+1])<<" ";
            k++;
        }
        cout<<endl;
        reverse(right_b.begin(),right_b.end());
        int curmax = 0;
        int ans = 0;
        for(auto it:left_b) cout<<it<<" ";
        cout<<endl;
        for(auto it:right_b) cout<<it<<" ";
        for(int i=0 ;i<n ;i++){
           curmax = min(left_b[i],right_b[i]);
            ans += curmax-height[i];
        }
        return ans;
    }
int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(height);
}