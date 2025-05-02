#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    int valid[105][105], num[105][105];
    int pos[505][5], dir[505][5];
    bool alive[505];

    cin >> n >> m >> k;
    for(int i = 0;i < k;++i){
        cin >> pos[i][0] >> pos[i][1] >> dir[i][0] >> dir[i][1];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            valid[i][j] = true;
            num[i][j] = 0;
        }
    }

    for(int i = 0; i < k; i++) {
        alive[i] = true;
    }

    int counter = k, amt = 0;
    while(counter > 0)
    {
        //put bomb
        for(int i = 0;i < k;++i){
            if(alive[i] && valid[pos[i][0]][pos[i][1]]){
                valid[pos[i][0]][pos[i][1]] = false;
                amt++;
            }
            
        }

        //move
        for(int i = 0;i < k;++i){
            if(alive[i]){
                int nx = pos[i][0] + dir[i][0], ny = pos[i][1] + dir[i][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                    alive[i] = false;
                    counter--;
                }else{
                    pos[i][0] = nx;
                    pos[i][1] = ny;
                }
            }
        }

        //bomb!
        for(int i = 0;i < n;++i){
            for(int j = 0;j < m;++j){
                if(!valid[i][j]){
                    bool bomb = false;
                    for(int l = 0;l < k;++l){
                        if(pos[l][0]==i && pos[l][1]==j && alive[l]){
                            bomb = true;
                            alive[l] = false;
                            counter--;
                        }
                    }
                    if(bomb){
                        valid[i][j] = true;
                        amt--;
                    }
                }
            }
        }
    }
    cout << amt << "\n";

    return 0;
}