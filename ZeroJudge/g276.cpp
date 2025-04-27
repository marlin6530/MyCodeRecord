#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    int valid[105][105]{true}, pos[505][5], dir[505][5];
    bool alive[505] = 1;
    cin >> n >> m >> k;
    for(int i = 0;i < k;++i){
        cin >> pos[i][0] >> pos[i][1] >> dir[i][0] >> dir[i][1];
    }
    int counter = n, amt = 0;
    while(counter > 0)
    {
        //put bomb
        for(int i = 0;i < k;++i){
            if(alive[i]){
                if(valid[pos[i][0]][pos[i][1]]){
                    valid[pos[i][0]][pos[i][1]] = false;
                    amt++;
                }
            }
            
        }
        //move
        for(int i = 0;i < k;++i){
            int nx = pos[i][0] + die[i][0], ny = pos[i][1] + die[i][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                alive[i] = 0;
                counter--;
            }else{
                
            }
        }

        //bomb!
    }
    

    return 0
}