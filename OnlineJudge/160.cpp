#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<cstring>
#include<iomanip>

using namespace std;

#define int long long
#define pb push_back

bool isPrime[105];
vector<int> prime;
void getPrime(int n){
    for(int i = 2;i <= n;++i) isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2;i * i <= n;++i){
        if(isPrime[i]){
            for(int j = i * i;j <= n;j += i){
                isPrime[j] = 0;
            }
        }
    }

    for(int i = 2;i <= n;++i){
        if(isPrime[i]) prime.pb(i);
    }
}


signed main(){
    getPrime(100);
    int n;
    while(cin >> n && n != 0)
    {
        int cnt[100]{};
        for(int i = 2;i <= n;++i){
            int tmp = i;
            for(int j = 0;j < prime.size();++j){
                if(prime[j] > tmp) break;
                while(tmp % prime[j] == 0){
                    cnt[j]++;
                    tmp /= prime[j];
                }
            }
        }

        cout << setw(3) << n << "! =";
        for(int i = 0;i < prime.size();++i){
            if(cnt[i] == 0) break;
            if(i % 15 == 0 && i) cout << endl << "      ";
            cout << setw(3) << cnt[i];
        }
        cout << "\n";
    }
}