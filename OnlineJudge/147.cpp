#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<cstring>
#include<iomanip>

using namespace std;

#define pb push_back
#define ll long long

const int dollar[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

int main(){
    ll ways[40000] = {};
    ways[0] = 1;
    for(int i = 0;i < 11;++i){
        for(int j = 1;j <= 30000;++j){
            if(j >= dollar[i]){
                ways[j] += ways[j - dollar[i]];
            }
        }
    }

    double num;
    while(cin >> num && num != 0.00)
    {
        int n = (int)(num * 100 + 0.5); //Important!!!
        cout << setw(6) << fixed << setprecision(2) << num << setw(17) << ways[n] << "\n";
    }
}