#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> sortedSquares(vector<int>& A) {
   int n = A.size();
    vector<int> squares(n);
    int highestIdx = n-1;
    int l=0, r=n-1;
    while(l <= r) {
      int leftSquare = pow(A[l], 2);
      int rightSquare = pow(A[r], 2);

      if(leftSquare >= rightSquare) {
        squares[highestIdx--] = leftSquare;
        l++;
      }
      else {
        squares[highestIdx--] = rightSquare;
        r--;
      }
    }
    return squares;
}

int main() {
    vector<int> A{-4, -2, 0, 1, 3};
    vector<int> B  = sortedSquares(A);
    vector<int>::iterator iter = B.begin();
    for(auto i : B) {
        cout << i << ",";
    }
    cout << endl;
}
