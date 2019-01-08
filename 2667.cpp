#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector < vector < int > > v;
vector < int > cnt;
int tmp;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int N;

void DFS(int i , int j , int label){

    if(v[i][j] == -1){
      tmp++;
      v[i][j] = label;

      for(int k = 0  ; k < 8 ; k++){

              int next_x = i + dx[k];
              int next_y = j + dy[k];

              if(0 <= next_x && next_x < N && 0 <= next_y && next_y < N){
                  DFS(next_x , next_y , label);
              }

      }
    }
}

int main(){

    string str;

    cin >> N;

    v.resize(N);


    for(int i = 0 ; i < N ; i++){
        cin >> str;

        for(int j = 0 ; j < N ; j++){

            if(str[j] == '1')  v[i].push_back(-1);
            else  v[i].push_back(0);
        }
    }

    int label = 1;

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(v[i][j] == -1){
                tmp = 0;
                DFS(i , j , label);
                cnt.push_back(tmp);
                label++;

            }
        }
    }

    sort(cnt.begin() , cnt.end());

    cout << cnt.size() << endl;

    for(int i = 0 ; i < cnt.size() ; i++){
        cout << cnt[i] << endl;
    }
}
