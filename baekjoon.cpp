#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector < int > v;


int main(){

	int N, C;
	int num;


	cin >> N >> C;


	for(int i = 0 ; i < N ; i++){
			cin >> num;
			v.push_back(num);
	}

	sort(v.begin() , v.end());

	int left = v[0];
	int right =  v[N-1];
	int ans = -1;

	while(left <= right){
			int mid = (left + right) / 2;
			int cnt = 1;
			int pre = 0;

			for(int i = 1 ; i < N ; i++){
						if(v[i] - v[pre] >= mid){
								cnt++;
								pre = i;
						}
			}

			if(cnt >= C) left = mid + 1;
			else right = mid - 1;

			if(ans < mid && cnt >= C)
				ans = mid;
	}

	cout << ans << endl;

	return 0;
}
