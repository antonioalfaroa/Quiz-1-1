#include <iostream>

using namespace std;

class Smith{
public: 
int name;
Smith(){
  name = 1;
  m_home = 2;
  m_wife = 3;
}
//friend class Son_Smith;
friend class Friend_Smith;
friend class Son_friend_Smith;
private:
int m_wife;

protected:
int m_home;
};

class Son_Smith : public Smith{
private:
int flag;

public:
Son_Smith(){
  flag = 4;
}
};

class Friend_Smith{
public:
void help(const Smith& sm){
  cout<<"sm.name : "<<sm.name<<endl;
  cout<<"sm.m_home : "<<sm.m_home<<endl;
  cout<<"sm.m_wife : "<<sm.m_wife<<endl;
  }

};

class Son_friend_Smith : public Smith,public Friend_Smith{
public: 
//even giving inheritance from all the above classes i wasnt able to give this class the smith private and protected objects. The only way i can found was giving son_friend as a friend of the Smith class
void help(const Smith& uncle_smith){
    cout<<"uncle_smith name : "<<uncle_smith.name<<endl;
    cout<<"uncle_smith home : "<<uncle_smith.m_home<<endl;
    cout<<"uncle_smith wife : "<<uncle_smith.m_wife<<endl;
}
};


int main(){

  Smith sa;
  Friend_Smith s;
  Son_friend_Smith so;
  cout<<"help in friend_smith : "<<endl;
  s.help(sa);
  cout<<"help in Son_friend_smith : "<<endl;
  so.help(sa);


  
}