#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
int n;
vector<int> ip_vec;
int checkM(){
    for(int i=31;i>=0;i--){
        for(int j=0;j<n;j++){
            if( (ip_vec[0] >> i )!= (ip_vec[j] >> i) ) return i+1;
        }
    }
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
        common_bit &= ip_bit;
        ip_vec.push_back(ip_bit);
    }
    string ip_v4 = "";
    for(int i=3;i>=0;i--){
        int temp = (common_bit >> (8 * i)) & 0b00000000000000000000000011111111;
        ip_v4 += to_string(temp);
        if(i!=0) ip_v4 += '.';
    }
    cout << ip_v4 << endl;
    int m = checkM();
    int fill = ~0;
    int mask = (fill >> m) << m;
    string mask_str = "";
    for(int i=3;i>=0;i--){
        mask_str += to_string(mask >> (8 * i) & 0b00000000000000000000000011111111);
        if(i>0) mask_str += '.';
    }
    cout << mask_str << endl;
    return 0;
}