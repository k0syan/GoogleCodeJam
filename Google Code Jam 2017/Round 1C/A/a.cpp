#include <iostream>
#include <iomanip>
#include <math.h>
#include <queue>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

struct Cake {
  int r;
  int h;
  
  friend bool operator<(const Cake& a, const Cake& b) {
    double s1 = 2 * M_PI * a.r * a.h;
    double s2 = 2 * M_PI * b.r * b.h;
    if (s1 == s2) {
      return a.r < b.r;
    } else {
      return s1 < s2;
    }
  }
};

int main() {
  int T;
  cin >> T;
  
  for (int t = 1; t <= T; ++t) {
    int n, k;
    cin >> n >> k;
    
    priority_queue<Cake> q;
    
    for (int i = 0; i < n; ++i) {
      Cake c;
      cin >> c.r;
      cin >> c.h;
      q.push(c);
    }
    
    vector<Cake> answer(k);
    for (int i = 0; i < k; ++i) {
      answer[i] = q.top();
      q.pop();
    }
    
    sort(begin(answer), end(answer), [](const Cake& a, const Cake& b) {
      return a.r > b.r;
    });
    
    double area = 0.0;
    for (int i = 0; i < k; ++i) {
      double si = 2 * M_PI * answer[i].r * answer[i].h + M_PI * answer[i].r * answer[i].r;
      area += si;
      if (i != k - 1) {
        area -= M_PI * answer[i + 1].r * answer[i + 1].r;
      }
    }
    
    cout << "Case #" << t << ": ";
    cout << fixed << setprecision(9);
    cout << area << "\n";
  }
  
  return 0;
}

