#include<iostream>
int mainh() {
  char a[100], b[100];
  std::cin >> a >> b;
  std::cout << a << ' ' << strlen(a) << '\n' << b << ' ' << strlen(b) << '\n';

  return 0;
}