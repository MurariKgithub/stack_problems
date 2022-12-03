#include<bits/stdc++.h>
using namespace std;
int appendCharacters(string s, string t) {
        int n =  s.size(),m = t.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(s[i]==t[j]){
             cout<<s[i]<<" "<<s[j]<<endl;   
                j++;
            }
            i++;
        }
        return m-j;
}
int main(){
    string s = "coaching", t = "coding";
    cout<<appendCharacters(s,t);
}