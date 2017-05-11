#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

int main() {
  int t;
  cin >> t;
  for (int c = 1; c <= t; ++c) {
    int n, r, o, y, g, b, v;
    cin >> n >> r >> o >> y >> g >> b >> v;
    
    vector<char> u(n);
    int first = max(r, max(y, b));
    first = max(first, o);
    first = max(first, g);
    first = max(first, v);
    if (first == r) {
      u[0] = 'R';
      --r;
    } else if (first == y) {
      u[0] = 'Y';
      --y;
    } else if (first == b) {
      u[0] = 'B';
      --b;
    } else if (first == o) {
      u[0] = 'O';
      --o;
    } else if (first == g) {
      u[0] = 'G';
      --g;
    } else if (first == v) {
      u[0] = 'V';
      --v;
    }
    
    bool possible = true;
    
    for (int i = 1; i < n; ++i) {
      int color = max(o, g);
      color = max(color, v);
      if (color == 0) {
        color = max(r, max(y, b));
      }
      
      if (color == 0) {
        possible = false;
        break;
      }
      
      if (color == r) {
      
        if (u[i - 1] == 'R' || u[i - 1] == 'O' || u[i - 1] == 'V') {
          if (y == 0 && b == 0 && g == 0) {
            possible = false;
            break;
          }
          
          int m = max(y, b);
          if (g > 0) {
            u[i] = 'G';
            --g;
          } else {
            if (m == y) {
              u[i] = 'Y';
              --y;
            } else {
              u[i] = 'B';
              --b;
            }
          }
        } else {
          u[i] = 'R';
          --r;
        }
        
      } else if (color == y) {
        
        if (u[i - 1] == 'Y' || u[i - 1] == 'O' || u[i - 1] == 'G') {
          if (r == 0 && b == 0 && v == 0) {
            possible = false;
            break;
          }
          
          int m = max(r, b);
          if (v > 0) {
            u[i] = 'V';
            --v;
          } else {
            if (m == r) {
              u[i] = 'R';
              --r;
            } else {
              u[i] = 'B';
              --b;
            }
          }
        } else {
          u[i] = 'Y';
          --y;
        }
        
      } else if (color == b) {
      
        if (u[i - 1] == 'B' || u[i - 1] == 'G' || u[i - 1] == 'V') {
          if (r == 0 && y == 0 && o == 0) {
            possible = false;
            break;
          }
          
          int m = max(r, y);
          if (o > 0) {
            u[i] = 'O';
            --o;
          } else {
            if (m == r) {
              u[i] = 'R';
              --r;
            } else {
              u[i] = 'Y';
              --y;
            }
          }
        } else {
          u[i] = 'B';
          --b;
        }
        
      } else if (color == o) {
      
        if (u[i - 1] == 'O' || u[i - 1] == 'R' || u[i - 1] == 'Y' || u[i - 1] == 'G' || u[i - 1] == 'V') {
          if (b == 0) {
            possible = false;
            break;
          } else {
            u[i] = 'B';
            --b;
          }
        } else {
          u[i] = 'O';
          --o;
        }
        
      } else if (color == g) {
      
        if (u[i - 1] == 'G' || u[i - 1] == 'Y' || u[i - 1] == 'B' || u[i - 1] == 'O' || u[i - 1] == 'V') {
          if (r == 0) {
            possible = false;
            break;
          } else {
            u[i] = 'R';
            --r;
          }
        } else {
          u[i] = 'G';
          --g;
        }
        
      } else if (color == v) {
      
        if (u[i - 1] == 'V' || u[i - 1] == 'B' || u[i - 1] == 'R' || u[i - 1] == 'O' || u[i - 1] == 'G') {
          if (y == 0) {
            possible = false;
            break;
          } else {
            u[i] = 'Y';
            --y;
          }
        } else {
          u[i] = 'V';
          --v;
        }
        
      }
      
      if (i == n - 1 && u[0] == u[i]) {
        possible = false;
        break;
      }
    }
    
    cout << "Case #" << c << ": ";
    if (possible) {
      for (int i = 0; i < u.size(); ++i) {
        cout << u[i];
      }
      cout << "\n";
    } else {
      cout << "IMPOSSIBLE" << "\n";
    }  
  }
  
  return 0;
}

