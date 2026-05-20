#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<cstdlib>

using namespace std;

struct Data{
    int board[4][4];
    int turn;
    int winner;
    int cnt;
};

int countLine(int board[4][4], int r, int c, int dirR, int dirC, int player){
    int count = 0;
    int nr = r + dirR;
    int nc = c + dirC;

    while (nr >= 0 && nr < 4 && nc >= 0 && nc < 4 && board[nr][nc] == player) {
        count++;
        nr += dirR;
        nc += dirC;
    }
    return count;
}

bool check(int b[4][4], int r, int c, int player){
    int horizon = 1 + countLine(b, r, c, 0, 1, player) 
                    + countLine(b, r, c, 0, -1, player);
    if (horizon == 3) return true;

    // 2. 檢查縱向 (Vertical)
    int v_count = 1 + countLine(board, r, c, 1, 0, player) 
                    + countLine(board, r, c, -1, 0, player);
    if (v_count == 3) return true;

    // 3. 檢查主對角線 (Main Diagonal: \)
    int d1_count = 1 + countLine(board, r, c, 1, 1, player) 
                     + countLine(board, r, c, -1, -1, player);
    if (d1_count == 3) return true;

    // 4. 檢查副對角線 (Anti-Diagonal: /)
    int d2_count = 1 + countLine(board, r, c, 1, -1, player) 
                     + countLine(board, r, c, -1, 1, player);
    if (d2_count == 3) return true;

    return false;

    return false;
}

void print(int b[4][4]){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (b[i][j] == 1)
                cout << "P"; 
            else if (b[i][j] == 2)
                cout << "C"; 
            else
                cout << "."; 
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]){
    int m1 = atoi(argv[1]);
    int m2 = atoi(argv[2]);

    const char *name = "os_hw1";
    const int SIZE = sizeof(Data);
    int fd = shm_open(name, O_CREAT | O_RDRW, 0666);
    ftruncate(fd, SIZE);
    Data *ptr = (Data *)mmap(0, SIZE, PROT_READ | PORT_WRITE, MAP_SHARED, fd, 0);

    memset(ptr->board, 0, sizeof(ptr->board));
    ptr->turn = 0;
    ptr->winner = 0;
    ptr->cnt = 0;

    pid_t = fork();

    if(pid < 0){
        cout << "fork failed\n";
        return 1;
    }
    else if(pid == 0){ //child
        srand(m2);
        cout << "[" << getpid() << "Child]: random seed " << m2 << '\n';

        while (true) {
            // 1. 等待輪到子行程 (turn == 1) 或 遊戲已由父行程宣告結束
            while (ptr->turn != 1 && ptr->winner == 0); 

            // 檢查遊戲是否因父行程獲勝或平手而結束
            if (ptr->winner != 0) {
                if (ptr->winner == 1) {
                    cout << "[" << getpid() << " Child]: I lose" << endl; // 輸了要表態 [cite: 30]
                }
                break; 
            }

            // 2. 隨機下棋邏輯
            int r, c;
            do {
                r = rand() % 4;
                c = rand() % 4;
            } while (ptr->board[r][c] != 0); // 確保該位置是空的 

            // 3. 更新棋盤狀態
            ptr->board[r][c] = 2; // 2 代表子行程 (C) [cite: 23]
            cout << "[" << getpid() << " Child]: plays at (" << r << "," << c << ")" << endl;
            print(ptr->board); // 每次下完印出棋盤 

            // 4. 判斷子行程是否獲勝
            if (check(ptr->board, r, c, 2)) {
                ptr->winner = 2; // 標記子行程獲勝
            } else if (++ptr->move_count == 16) {
                ptr->winner = 3; // 棋盤滿了，平手 
            }

            // 5. 將控制權交回父行程 (turn = 0)
            ptr->turn = 0;

            // 如果子行程這手棋下完就贏了，跳出迴圈結束行程
            if (ptr->winner != 0) break;
        }

        exit(0);

    }
    else{              //parent
        srand(m1);
        cout << "[" << getpid() << "Child]: random seed " << m1 << '\n';
        cout << "[" << getpid() << "Child]: create a child " << pid << '\n';

        while (!ptr->winner) {
            while (ptr->turn != 0 && ptr->winner == 0); 
            if (ptr->winner != 0) break;
            
            int r, c;
            do {
                r = rand() % 4;
                c = rand() % 4;
            } while (ptr->board[r][c] != 0);

            ptr->board[r][c] = 1; 
            cout << "[" << getpid() << " Parent]: plays at (" << r << "," << c << ")" << endl;

            if (check(ptr->board, r, c, 1)) {
                ptr->winner = 1; // 父行程勝
            } else if (++ptr->cnt == 16) {
                ptr->winner = 3; // 平手
            }

            // 4. 交棒給子行程
            ptr->turn = 1;
        }

        wait(NULL);

    }

    return 0;
}
