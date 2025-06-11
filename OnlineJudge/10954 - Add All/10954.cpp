//Time Complexity: O()

//#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n;
    while(cin >> n && n != 0)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0;i < n;++i){
            int num;
            cin >> num;
            pq.push(num);
        }
        int ans = 0, sum;
        while(1){
            sum = pq.top();
            pq.pop();
            if(pq.empty()) break;
            sum += pq.top();
            ans += sum;
            pq.pop();
            pq.push(sum);
        }
        cout << ans << '\n';
    }


    return 0;
}