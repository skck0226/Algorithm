    #include <iostream>

    using namespace std;
    int oper(int n, int op){
        switch(op){
            case 0:
                n ^= 0b111000000;
                break;
            case 1:
                n ^= 0b000111000;
                break;
            case 2:
                n ^= 0b000000111;
                break;
            case 3:
                n ^= 0b100100100;
                break;
            case 4:
                n ^= 0b010010010;
                break;
            case 5:
                n ^= 0b001001001;
                break;
            case 6:
                n ^= 0b100010001;
                break;
            case 7:
                n ^= 0b001010100;
                break;
        }
        return n;
    }
    int main(){
        int t;
        cin >> t;
        char c;
        for(int z=0;z<t;z++){
            char arr[3][4];
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    cin >> arr[i][j];
                }
            }
            int n = 0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(arr[i][j]=='H') n |= (1<<(i*3 + j));
                }
            }
            int min = 987654321;
            for(int i=0;i<(1<<8);i++){
                int cnt = 0;
                int n_temp = n;
                for(int j=0;j<8;j++){
                    if(i & (1<<j)){
                        n_temp = oper(n_temp,j);
                        cnt++;
                    }
                }
                if(n_temp==0 | n_temp==(1<<9)-1){
                    if(min > cnt) min = cnt;
                }
            }
            if(min==987654321) cout << -1 << "\n";
            else cout << min << "\n";
        }
        return 0;
    }