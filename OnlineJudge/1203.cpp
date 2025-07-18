//Time Complexity: O()

//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<queue>
#include<utility>
using namespace std;

int main(){
    int n, counter = 0;
    string r;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int num, time;
    while(cin >> r && r != "#")
    {
        cin >> num >> time;
        pq.push(make_pair(time, make_pair(num, time)));
        counter++;
    }
    cin >> n;
    int i = 0;
    while(i < n){
        cout << pq.top().second.first << '\n';
        int time = pq.top().first + pq.top().second.second;
        int num = pq.top().second.first;
        int next = pq.top().second.second;
        pq.push(make_pair(time, make_pair(num, next)));
        pq.pop();
        ++i;
    }

    return 0;
}