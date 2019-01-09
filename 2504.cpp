#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
  string str;

  cin >> str;
  stack < char > st;

  int res = 1;
  int ans = 0;
  int flag = 0;

  for(int i = 0 ; i < str.size() ; i++){
      if(str[i] == '(' ) {
        res *= 2;
        st.push(str[i]);
      }
      else if(str[i] == '['){
        res *= 3;
        st.push(str[i]);
      }

      else if(str[i] == ')'){

        if(str[i-1] == '(') ans += res;

        if(st.empty() || st.top() == '['){
          flag = 1;
          break;
        }

        if(st.top() == '(') st.pop();

        res /= 2;


      }
      else{

        if(str[i-1] == '[') ans += res;

        if(st.empty() || st.top() == '('){
          flag = 1;
          break;
        }

        if(st.top() == '[') st.pop();

        res /= 3;
      }
  }

  if(flag == 1 || !st.empty()) cout << 0 << endl;
  else cout << ans << endl;

  return 0;
}
