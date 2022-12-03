#include<bits/stdc++.h>
using namespace std;
string removeStars(string s) {
        stack<char> stack;
        for(auto it:s){
            if(it=='*' && stack.empty()) return "";
            else if(!stack.empty() && it=='*'){
                stack.pop();
            }
            else{
                stack.push(it);
                // cout<<it<<endl;
            }
            
        }
        string ans;
        while(!stack.empty()){
            ans+=stack.top();
            // cout<<ans<<endl;
            stack.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
}
int main(){
    string s= "leet**cod*e";
    cout<<removeStars(s);
}
