#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
const int MAX_LEN_PROD = 130;
list<bool> getComputeSequence(int x) {
  bool b[ 10 ];
  int i = 0;
  for(i = 0; (i < 10) && (x > 1); ++i) {
    b[ i ] = ((x % 2) == 0);
    x /= 2;
  }  
  list<bool> ret(b, b + i);
  ret.reverse();
  return ret;
}

list<char> mult(list<char> a, list<char> b) {
  //int ia, ib, ic(0), carry(0), c;
  int carry, c, ic;
  list<char>::reverse_iterator ia, ib;
  int lena = a.size();
  int lenb = b.size();
  char crev[ MAX_LEN_PROD * 2 + 3 ];
  memset(crev, '0', MAX_LEN_PROD * 2 + 3);
  for(ib = b.rbegin(); ib != b.rend(); ++ib) {    
    ic = distance(b.rbegin(),ib);
    carry = 0;
    for(ia = a.rbegin(); ia != a.rend(); ++ia) {      
      c = (*ib - '0') * (*ia - '0') + carry + crev[ic] - '0';
      carry = c / 10;
      crev[ ic++ ] = c % 10 + '0';
    }
    crev[ ic ] = carry + '0';
  }
  list<char> ret(crev, crev + ic + (carry > 0 ? 1 : 0));
  ret.reverse();
  return ret;
}

list<char> sq(list<char> a) {
  return mult(a, a);
}

list<char> mult(char* a, char* b) {
  return mult(list<char>(a, a + strlen(a)), list<char>(b, b + strlen(b)));
}

int mainh() {
  char a[ 7 ], b[ 3 ];  
  list<char> lstA, lst;
  size_t posDeci;
  list<bool> order;
  list<char>::iterator it, itdeci;
  
  while(cin >> a >> b) {
    lstA = list<char>(a, a + strlen(a));
    it = find(lstA.begin(), lstA.end(), '.');
    posDeci = std::distance(lstA.begin(), it);
    lstA.remove('.');
    lst = lstA;
    order = getComputeSequence(atoi(b));
    for(list<bool>::iterator it = order.begin(); it != order.end(); ++it) {
      lst = sq(lst);
      if(!(*it)){
        lst = mult(lst, lstA);
      }
    }
    itdeci = lst.begin();
    posDeci = lst.size() - (lstA.size() - posDeci) * atoi(b);
    
    for(int i = 0; i < posDeci; ++itdeci, ++i);    
    lst.insert(itdeci, '.');
    bool hitdecimal = false;
    if(find(lst.begin(), lst.end(), '.') != lst.end()) {
      for(list<char>::reverse_iterator itrev = lst.rbegin(); itrev != lst.rend() && *itrev == '0' && !hitdecimal; ++itrev) {
        if(*itrev == '.') {
          hitdecimal = true;
        } else {
          *itrev = 'x';
        }
      }
      lst.remove('x');
    }

    if(*(lst.rbegin()) == '.') lst.pop_back();
    if(*(lst.begin()) == '0') lst.pop_front();
    if(lst.size() == 0) lst.push_back('0');

    for(list<char>::iterator it = lst.begin(); it != lst.end(); ++it) {
      cout << *it;
    }
    cout << '\n';
  }
  
  return 0;
}
