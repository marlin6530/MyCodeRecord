#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(){
    int n;
    while(cin >> n)
    {
        if(n == 0){
            break;
        }
        vector<int> start;
        for(int i=0;i<n;i++){
            start.push_back(i+1);
        }

        int t;
        while(cin >> t)
        {
            vector<int> end;
            if(t == 0){
                cout << endl;   
                break;
            }
            end.push_back(t);
            for(int i=1;i<n;i++){
                cin >> t;
                end.push_back(t);
            }

            stack<int> tmp;
            int count = 0;
            for(int i=0;i<n;i++){
                if(start[i] == end[count]){
                    count++;
                }
                else if(!tmp.empty() && tmp.top() == end[count]){
                    tmp.pop();
                    count++;
                    i--;
                }
                else{
                    tmp.push(start[i]);
                }
            }
            while(1){
                if(tmp.empty()){
                    cout << "Yes" << endl;
                    break;
                }
                else if(tmp.top() == end[count]){
                    tmp.pop();
                    count++;
                }
                else{
                    cout << "No" << endl;
                    break;
                }
            }
        }
        
    }


    return 0;
}
