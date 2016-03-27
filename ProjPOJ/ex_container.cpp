#include<list>
#include<iostream>
void intList() {
  int arr[ ] = { 75, 23, 65, 42, 13 };
  std::list<int> lst(arr, arr + 5);
  std::cout << "";
  for(std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';
}

void charList() {
  char s[] = "abc";
  std::list<char> lst(s, s + strlen(s));
  for(std::list<char>::iterator it = lst.begin(); it != lst.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';
}

int mainh() {
  charList();
  return 0;
}