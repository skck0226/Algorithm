#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
int n;
vector<int> ip_vec;
int checkM(){
    int bit = 0;
    for(int i=31;i>=0;i--){
        for(int j=1;j<n;j++){
            if( (ip_vec[0] >> i )!= (ip_vec[j] >> i) ) return bit << i+1;
        }
        bit = bit << 1;
        bit += 1;    
    }
}
void print(int mask)
{
    int shift = 24;
    for (int i = 0; i < 4; i++, shift -= 8)
    {
        cout << ((mask >> shift) & (1 << 8) - 1);
        if (i != 3)
            cout << '.';
    }
    cout << '\n';
}
int main(){
    cin >> n;
    int common_bit = ~0;
    fflush(stdin);
    for(int i=0;i<n;i++){
        string ip;
        getline(cin,ip,'\n');
        stringstream ss(ip);
        string num_str;
        int index = 3;
        int ip_bit = 0;
        while(getline(ss,num_str,'.')){
            int num = stoi(num_str);
            ip_bit |= (num<<(8*index));
            index--;
        }
        ip_vec.push_back(ip_bit);
    }
    int mask = checkM();
    print(ip_vec[0] & mask);
    print(mask);
    return 0;
}