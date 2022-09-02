#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > subjects; 
vector<long long> students;
int main(){
    int n,m;
    cin >> n;
    for(int i=0;i<n;i++){
        int time; cin >> time;
        vector<int> subj;
        for(int j=0;j<time;j++){
            int a; cin >> a;
            subj.push_back(a);
        }
        subjects.push_back(subj);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int time; cin >> time;
        long long stud = 0;
        for(int j=0;j<time;j++){
            int a; cin >> a;
            stud |= ((long long)1 << a);
        }
        students.push_back(stud);
    }
    for(auto stud : students){
        int cnt = 0;
        for(auto subj : subjects){
            long long subj_bit = 0;
            for(int x : subj){
                subj_bit |= ((long long)1 << x);
            }
            // for(int i=1;i<=63;i++){
            //     if (subj_bit & (long long)1 << i) cout << "1";
            //     else cout << "0";
            // }
            // cout << " | ";

            // for (int i = 1; i <= 63; i++){
            //     if (stud & ((long long)1 << i)) cout << "1";
            //     else cout << "0";
            // }
            // cout << endl;
            if((subj_bit & stud) == subj_bit) cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}