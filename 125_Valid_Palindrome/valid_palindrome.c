#include <iostream>
#include <string>

using namespace std;

bool valid_alpha(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))  {
            //cout << c << endl;
            return true;
        } else
            return false;
}

bool isPalindrome(string s) {
          if (s.empty() || s.length() ==1)
              return true;
        
          string::iterator it_left=s.begin();
          string::iterator it_right=s.end()-1;
          //cout << "it_left=" << *it_left << ", it_right=" << *it_right << endl;
        
          while (it_left <= it_right) {
                  if (!valid_alpha(*it_left)) {
                      it_left++;
                      if (it_left > it_right) return false; 
                      continue;
                  }
                  if (!valid_alpha(*it_right)) {
                      it_right--;
                      if (it_right < it_left) return false; 
                      continue;
                  }
                  int upper_right =  toupper(*it_right);
                  int upper_left = toupper(*it_left);
                  //cout << toupper(*it_right) << "," << toupper(*it_left) << endl;
                  if (upper_right == upper_left) {
                      it_left++;
                      it_right--;
                      continue;
                  } else {
                      return false;
                  }
          }
          return true;
}

int main() {
//    string s = "A man, a plan, a canal: Panama";
    string s = ",.";
    bool res = isPalindrome(s);
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
