#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<string> v;
    vector<vector<int> > v2(10, vector<int>(12, 0));
    int first[10]={0,};
    map<char, int> m;
    long long match[10];
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        v.push_back(s);
    }
    for(int i=0;i<n;i++){
        first[v[i][0]-'A']++;
        for(int j=v[i].size()-1;j>=0;j--){
            v2[v[i][j] - 'A'][v[i].size()-1-j]++;
        }
    }
    vector< pair< long long, char> > score_alpha;
    vector< long long > score(10,0);
    for(int i=11;i>=0;i--){
        for(int j=0;j<10;j++){
            if(v2[j][i]) score[j] += v2[j][i]*pow(10,i);
        }
    }
    for(int i=0;i<10;i++){
        char c = 'A' + i;
        score_alpha.push_back(pair<long long, char>(score[i], c));
    }
    sort(score_alpha.begin(), score_alpha.end());
    for(int i=0;i<10;i++){
        if(first[score_alpha[i].second-'A']==0){
            m[score_alpha[i].second] = 0;
            score_alpha.erase(score_alpha.begin()+i);
            break;
        }
    }
    for (int i = 0; i < 9; i++){
        m[score_alpha[i].second] = i+1;
    }
    long long answer = 0;
    for (int i = 0; i < n; i++){
        long long num = 0;
        for(int j=v[i].size()-1; j>=0; j--){
            num += m[v[i][j]]*pow(10,v[i].size()-1-j);
        }
        answer += num;
    }
    printf("%lld\n",answer);
    return 0;
}