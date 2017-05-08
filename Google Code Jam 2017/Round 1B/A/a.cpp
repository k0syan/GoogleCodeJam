#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

typedef unsigned long long ull;

int main() {
  int t;
  cin >> t;
  for (int c = 1; c <= t; ++c) {
    ull d;
    int n;
    cin >> d >> n;
    vector<ull> k(n);
    vector<ull> s(n);
    double max = -1; 
    for (int i = 0; i < n; ++i) {
      cin >> k[i] >> s[i];
      k[i] = d - k[i];
      if (max < (double)k[i] / s[i]) {
        max = (double)k[i] / s[i];
      } 
    }
    
    cout << "Case #" << c << ": "; 
    cout << fixed << setprecision(6) << (double) d / max <<  "\n";
  }
  
  return 0;
}
