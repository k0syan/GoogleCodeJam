#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    int r, c;
    cin >> r >> c;
    char **tort = new char*[r];
    
    for (int j = 0; j < r; ++j) {
      tort[j] = new char[c];
      for (int k = 0; k < c; ++k) {
        cin >> tort[j][k];
      }
    }
    
    for (int j = 0; j < r; ++j) {
      for (int k = 0; k < c; ++k) {
        if (tort[j][k] != '?') {
          for (int l = 0; l < k; ++l) {
            if (tort[j][l] == '?') {
              tort[j][l] = tort[j][k];
            }
          }
          for (int l = k + 1; l < c; ++l) {
            if (tort[j][l] == '?') {
              tort[j][l] = tort[j][k];
            } else {
              break;
            }
          }
        }
      }
    }
    
    for (int j = 0; j < r; ++j) {
      bool t = true;
      for (int k = 0; k < c; ++k) {
        if (tort[j][k] != '?') {
          t = false;
        }
      }
      
      if (t) {
        if (j != 0) {
          for (int k = 0; k < c; ++k) {
            tort[j][k] = tort[j - 1][k];
          }
        } else {
          for (int k = j + 1; k < r; ++k) {
            if (tort[k][0] != '?') {
              for (int l = 0; l < c; ++l) {
                tort[j][l] = tort[k][l];
              }
              break;
            } else {
              continue;
            }
          }
        }
      }
    }
    
    cout << "Case #" << i << ":" << "\n";
    for (int j = 0; j < r; ++j) {
      for (int k = 0; k < c; ++k) {
        cout << tort[j][k];
      }
      cout << "\n";
    }
  }
  
  return 0;
}

