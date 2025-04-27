/* Question : OJ Number */

#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int input;
    vector<int> vec;
    for(int i=0;i<n;++i){
        cin >> input;
        vec.push_back(input);
    }
    for(int i=0;i<n-k+1;++i){
        multiset<int> st;
        for(int j=i;j<i+k;++j){
            st.insert(vec[j]);
        }
        int index;
        if(k%2==0) index = k/2 - 1;
        else index = k/2;
        auto it = next(st.begin(),index);
        cout << *it << " ";
    }

    return 0;
}