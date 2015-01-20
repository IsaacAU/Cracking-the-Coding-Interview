#include<string>

using namespace std;

class Call{
public:
  Call(int r=0):rank(r){}
  void reply(string message){
  
  }
  void disconnect(){
    reply("Thank you for calling!");
  }
private:
  int rank;
};
