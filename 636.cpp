#include<bits/stdc++.h>
using namespace std;
void extract(vector<string> &temp,string s){
    string res;
    for(auto it:s){
        if(it==':') {
        temp.push_back(res);
        res.clear();
        }
        else res+=it;
    }
    temp.push_back(res);
}
vector<int> exclusiveTime(int n, vector<string>& logs) {
    stack<pair<pair<int,int>,int>> stack;
    vector<int> ans(n,0);
    for(int i=0 ;i<logs.size() ;i++){
        vector<string> temp;
        extract(temp,logs[i]);
        int ID= temp[0][0]-'0';
        int t = temp[2][0]-'0';
        string ind = temp[1];
        if(ind=="start") stack.push({{ID,t},0});
        if(ind=="end" && !stack.empty()){
            int child = stack.top().second;
            int T = stack.top().first.second;
            int id = stack.top().first.first;
            int tt = ((t-T)+1)-child;
            stack.pop();
            if(!stack.empty()) stack.top().second+=(tt+child);
            ans[id]+=tt;
        }
    }
    for(auto it:ans) cout<<it<<endl;
}
int main(){
  int n = 1;
  vector<string> logs = {"0:start:0","0:start:1","0:start:2","0:end:3","0:end:4","0:end:5"};
    exclusiveTime(n,logs);
}