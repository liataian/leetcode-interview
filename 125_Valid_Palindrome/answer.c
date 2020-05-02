#include <iostream>
#include <string>

using namespace std;

#if 0
bool valid_alpha(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))  {
            //cout << c << endl;
            return true;
        } else
            return false;
}
#endif

bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
        while (isalnum(s[i]) == false && i < j)
            i++; // Increment left pointer if not alphanumeric

        while (isalnum(s[j]) == false && i < j)
            j--; // Decrement right pointer if no alphanumeric

        if (toupper(s[i]) != toupper(s[j]))
            return false; // Exit and return error if not match
    }
    return true;
}

int main() {
//    string s = "A man, a plan, a canal: Panama";
    string s = "0P";
    bool res = isPalindrome(s);
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
