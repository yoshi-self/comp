#include <bits/stdc++.h>

// whole string tolower
void stringToLower(std::string &str) {
  std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}
// whole string toupper
void stringToUpper(std::string &str) {
  std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

// split a string to vector<string>
std::vector<std::string> split(const std::string &str, char delim) {
  std::istringstream stream(str);
  std::string element;
  std::vector<std::string> result;
  while(std::getline(stream, element, delim)) {
    result.push_back(element);
  }
  return result;
}

// join vector<string> to a string with delimiter
std::string join(const std::vector<std::string> &v, const std::string delim = "") {
  std::string result;
  for(unsigned int i = 0; i < v.size(); ++i) {
    result += v[i];
    if(i != v.size() - 1) {
      result += delim;
    }
  }
  return result;
}

template <class C>
void printContainer(C &container, const char *delim=",") {
#ifdef LOCAL
  for(const auto &e : container) {
    std::cout << e << delim;
  }
  std::cout << "\n";
#endif
}

template <class K, class V>
void printMap(std::map<K, V> m, const char *delim=",") {
  for(const auto &e : m) {
    std::cout << e.first << ":" << e.second << delim;
  }
  std::cout << "\n";
}

int ctoi(char c) {
  return c - '0';
}

// Greatest common divisor
template<class T>
T gcd(T x, T y) {
  if(x < y) {
    std::swap(x, y);
  }
  T r = x % y;
  while(r != 0) {
    x = y;
    y = r;
    r = x % y;
  }
  return y;
}

// Least common multiple
template<class T>
T lcm(T x, T y) {
  return x/gcd(x,y) * y;
}

// whether x is in str or not
template <class T>
bool inString(const T &x, const std::string &str) {
  if(str.find(x) != std::string::npos) {
    return true;
  }
  else {
    return false;
  }
}

// whether x is in s or not
template <class T>
bool inSet(const T &x, const std::set<T> &s) {
  auto iter = s.find(x);
  if(iter != s.end()) {
    return true;
  }
  else {
    return false;
  }
}

// whether x is in v or not
template <class T>
bool inVector(const T &x, const std::vector<T> &v) {
  auto iter = std::find(v.begin(), v.end(), x);
  if(iter != v.end()) {
    return true;
  }
  else {
    return false;
  }
}

// nth element of set s
template <class T>
T setAt(const std::set<T> &s, const int n) {
  auto iter = s.begin();
  std::advance(iter, n);
  return *iter;
}

// replace all from in s to to;
void replaceString(std::string &s, const std::string &from, const std::string &to) {
  std::size_t pos = 0;
  std::size_t from_size = from.size();
  std::size_t to_size = to.size();
  while((pos = s.find(from, pos)) != std::string::npos) {
    s.replace(pos, from_size, to);
    pos += to_size;
  }
}

// count digit number of n
template<class T>
T digit(T n) {
  T count = 1;
  while((n /= 10) != 0) {
    count++;
  }
  return count;
}

// calculate pow with mod
template <class T>
T powmod(T x, T y, T mod) {
  if(y == 0) {
    return (T)1;
  }
  else if(y == 1) {
    return x % mod;
  }
  else if(y % 2 == 0) {
    T d = powmod(x, y/2, mod);
    return (d * d) % mod;
  }
  else {
    return (powmod(x, y-1, mod) * x) % mod;
  }
}

// convert degree to radian
double dtor(double d) {
  return d * 3.1415926535897932384626433832795 / 180;
}

// return vector v[prime]==true v[composit]==false
std::vector<int> makePrimeCheckVector(int maxnum) {
  std::vector<int> v(maxnum + 1, true);
  v[0] = v[1] = false;
  for(int i = 2; i < ceil(sqrt(maxnum)) + 1; ++i) {
    for(int j = 1; i * j <= maxnum; ++j) {
      if(j != 1) {
        v[i * j] = false;
      }
    }
  }
  return v;
}

// return vector<int> of prime numbers
std::vector<int> makePrimeNumberVector(int maxnum) {
  std::vector<int> check = makePrimeCheckVector(maxnum);
  std::vector<int> res;
  for(int i = 2; i < check.size(); ++i) {
    if(check[i]) {
      res.push_back(i);
    }
  }
  return res;
}

using namespace std;
int main() {
}
