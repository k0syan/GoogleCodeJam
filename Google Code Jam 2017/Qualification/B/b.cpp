#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long ull;

string tidy(ull n) {
  string str = to_string(n);
  
  if (str.size() == 1) {
    return str;
  }
  
  for (int i = str.size() - 1; i > 0; --i) {
    if (str[i] < str[i - 1]) {
      str[i - 1] = (str[i - 1] - '0' - 1) + '0';
      for (int j = i; j < str.size(); ++j) {
        str[j] = '9';
      }
    }
  }
  
  string ans = "";
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] != '0') {
      ans += str[i];
    }
  }
  
  return ans;
}

int main() {
  int t;
  cin >> t;
  
  for (int i = 1; i <= t; ++i) {
    ull number;
    cin >> number;
    cout << "Case #" << i << ": " << tidy(number) << "\n";
  }
  
  return 0;
}
