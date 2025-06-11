//Time Complexity: O()

#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

string months[13] = {
    " ","January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

bool leapYear(int y){
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int main(){
    int n;
    cin >> n;
    for(int counter = 1;counter <= n;++counter)
    {
        string month, s;
        int year[2], monthIndex[2], day[2];
        for(int i = 0;i < 2;++i){
            cin >> month;
            cin.ignore();
            for(int j = 1;j <= 12;++j){
                if(month == months[j]){
                    monthIndex[i] = j;
                }
            }
            getline(cin, s);
            string tmp;
            tmp = s.substr(0, 2);
            day[i] = stoi(tmp);
            tmp = s.substr(4, 4);
            year[i] = stoi(tmp);
        }

        int num[2] = {};
        num[0] = year[0] / 4 - year[0] / 100 + year[0] / 400;
        num[1] = year[1] / 4 - year[1] / 100 + year[1] / 400;
        
        if(leapYear(year[0])){
            if(monthIndex[0] <= 2){
                num[0]++;
            }
        }

        if(leapYear(year[1])){
            if(monthIndex[1] < 2){
                num[0]--;
            }else if(monthIndex[1] == 2 && day[1] < 29){
                num[0]--;
            }
        }

        cout << "Case " << counter << ": " << num[1] - num[0] << '\n';
    }
}