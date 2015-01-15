#include<string>

using namespace std;

bool unique(const string &s){
  bool arr[256];
  fill_n(arr, 256, false);
  for(auto c:s)
    if(arr[unsigned(c)])
      return false;
    else
      arr[unsigned(c)]=true;
  return true;
}
