#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<pair<int, bool>> p (n);

  bool in_queue = false;
  bool direction;
  int curr_time;

  cin >> p[0].first >> p[0].second;
  direction = p[0].second;
  curr_time = p[0].first + 10;

  for(int i = 1; i < n; i++){

    cin >> p[i].first >> p[i].second;

    if(in_queue && (curr_time <= p[i].first)){
        curr_time += 10;
        direction = !direction;
        in_queue = false;
    }

    if(p[i].second == direction){

      curr_time = p[i].first + 10;

    }else{

      if(p[i].first >= curr_time){
        curr_time = p[i].first + 10;
        direction = !direction;
      }else in_queue = true;

    }
  }

  if(in_queue)curr_time+=10;

  cout << curr_time;

  return 0;
}
