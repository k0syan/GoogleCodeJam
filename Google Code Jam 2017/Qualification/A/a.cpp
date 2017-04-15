#include <iostream>
#include <string>
using namespace std;

int flips(string s, int k) {
  int flips = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '-') {
      if (i + k - 1 < s.size()) {
        ++flips;
        for (int j = i; j < i + k; ++j) {
          if (s[j] == '-') {
            s[j] = '+';
          } else {
            s[j] = '-';
          }
        }
      } else {
        flips = -1;
        break;
      }
    }
  }
  
  return flips;
}

int main() {
  int t;
  cin >> t;
  
  for (int i = 1; i <= t; ++i) {
    string s;
    int k;
    cin >> s >> k;
    
    int answer = flips(s, k);
    if (answer == -1) {
      cout << "Case #" << i << ": IMPOSSIBLE\n";
    } else {
      cout << "Case #" << i << ": " << answer << "\n";
    }
  }
  
  return 0;
}

