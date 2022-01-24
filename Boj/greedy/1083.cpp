#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, a;
    int s;
    vector<int> v, sorted;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a);
        v.push_back(a);
    }
    scanf("%d", &s);
    int cnt = 0;
    while(1){
        if(s==0) break;
        if(v.size()==0) break;
        int max = 0, index;
        for(int i=0;i<=s;i++){
            if(i==v.size()) break;
            if(max < v[i]){
                max = v[i];
                index = i;
            }
        }
        sorted.push_back(max);
        v.erase(v.begin()+index);
        s -= index;
    }

    for (int i = 0; i < sorted.size(); i++){
        printf("%d ", sorted[i]);
    }
    for (int i = 0; i < v.size(); i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}