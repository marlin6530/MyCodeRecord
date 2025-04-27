#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, count = 1;
    while(cin >> n)
    {
        bool repeat[20000] = {false};
        bool b2 = true;
        vector<int> num;

        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            if(x < 1){
                b2 = false;
            }
            num.push_back(x);
        }

        for(int i=1;i<n && b2;i++){
            if(num[i-1] >= num[i]){
                b2 = false;
            }
        }

        for(int i=0;i<n && b2;i++){
            for(int j=i;j<n && b2;j++){
                int sum = num[i] + num[j];
                if(repeat[sum] == false){
                    repeat[sum] = true;
                }else{
                    b2 = false;
                }
            }
        }
        if(b2){
            cout << "Case #" << count << ": It is a B2-Sequence." << endl;
        }else{
            cout << "Case #" << count << ": It is not a B2-Sequence." << endl;
        }
        count ++;
    }

    return 0;
}