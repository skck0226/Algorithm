#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<string> v;
    vector<vector<int> > v2(10, vector<int>(8, 0));
    map<char, int> a2i;
    map<int, char> i2a;
    map<char, int> m;
    map<char, int> ::iterator miter;
    set<char> a_set;
    set<char>::iterator iter;
    long long match[11];
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        v.push_back(s);
    }
    for(int i=0;i<n;i++){
        for(int j=v[i].size()-1;j>=0;j--){
            a_set.insert(v[i][j]);
        }
    }
    int index = 0;
    for(iter=a_set.begin(); iter!=a_set.end();iter++){
        i2a[index] = *iter;
        a2i[*iter] = index++;
    }
    for(int i=0;i<n;i++){
        for(int j=v[i].size()-1;j>=0;j--){
            v2[a2i[v[i][j]]][v[i].size()-1-j]++;
        }
    }
    vector< pair< long long, char> > score_alpha;
    vector< long long > score(10,0);
    for(int i=7;i>=0;i--){
        for(int j=0;j<10;j++){
            if(v2[j].size()==0) continue;
            if(v2[j][i]) score[j] += v2[j][i]*pow(10,i);
        }
    }
    for(int i=0;i<10;i++){
        score_alpha.push_back(pair<long long, char>(score[i], i2a[i]));
    }
    sort(score_alpha.begin(), score_alpha.end());
    for(int i=0;i<10;i++){
        m[score_alpha[i].second] = i;
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