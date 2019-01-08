#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N,M;
int num;

vector < vector < int > > v ;
int *visited;
int *cnt_hacking;

int res = 0;

void DFS( int vertex ){

      cnt_hacking[vertex]++;
      res = max(res,cnt_hacking[vertex]);

      for(int i = 0 ; i < v[vertex].size() ; i++ ){
          int next = v[vertex][i];
          if(!visited[next]){

            visited[next] = 1;
            DFS(next);
          }

      }


}

int main(){


    scanf("%d %d" , &N , &M);

    v.resize(N);

    visited = new int [N];
    cnt_hacking = new int [N];

    for(int i = 0 ; i < M ; i++){

          int a,b;

          scanf("%d %d" , &a , &b);
          v[a-1].push_back(b-1);

    }
    for(int i = 0 ; i < N ; i++){

      for(int j = 0 ; j < N ; j++) visited[j] = 0 ;
      visited[i] = 1;
      DFS(i);

    }

    for(int i = 0 ;i < N ; i++){
        if(cnt_hacking[i] == res){
            printf("%d ",i+1 );
        }
    }

}
