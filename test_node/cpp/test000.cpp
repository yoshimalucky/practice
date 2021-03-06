#include <iostream>
using namespace std; // std namespace is used

// class myClass;
class myClass {
  int a;
public:
  void set_a(int num);
  int get_a();
  // private: // default
  // protected:
  // public:
}; // Remember to put semicolon!
void RecursiveCall(int argc, char *argv[]); // prototype declaration

int main(int argc, char *argv[]) {
  /* cout << "argc:" << argc << "\n";
  for (int i=0; i < 2; i++) {
    cout << "argv[" << i << "]:" << argv[i] << "\n";
    } */
  // Reprement with recursive call
  myClass obj;
  obj.set_a(25);
  cout << obj.get_a() << "\n";

  RecursiveCall(argc, argv);

  int month = 11, day = 3;
  double percent = 25.2525;
  std::cout << month << "月"; // if namespace std is not used
  cout << day << "日\n";
  cout << "降水確率" << percent << "%\n";

  // char *str[size];
  string str; // string do not need size info
  do {
    cout << ": ";
    cin >> str;
    cout << str << "\n";
  } while (str != "exit");
  return 0;
}

void myClass::set_a(int num) {
  a = num;
}
int myClass::get_a() {
  return a;
}


void RecursiveCall(int argc, char *argv[]) {
  argc -= 1;

  if (argc >= 0) {
    cout << "argv[" << argc  << "]:" << argv[argc] << "\n";
  } else {
    return;
  }
  return RecursiveCall(argc, argv); // argc can be decremented. not constant.
}
