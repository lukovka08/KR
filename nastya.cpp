#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
  string s,s1,s2;
  int n,k;
  if (argc<=1){
    cout<<"Не задано имя файлов"<<endl;
    return 0;
  }
  ifstream f(argv[1]);
  if (f.is_open()==0){
    cout<<"Файл не открывается"<<endl;
    return 0;
  }
  f>>s;
  cin>>s1;
  cin>>s2;
  for (int i=0;i<s.size();i++){
    int b=0;
    for (int j=i;j<i+s1.size();j++){
      if (s[j]==s1[j-i]){
        b+=1;
      }
    }
    if (b==s1.size()){
      s.replace(i,s1.size(),s2);
      i=i+s2.size()-1;
    }
  }
  cout<<s;
  f.close();
}
