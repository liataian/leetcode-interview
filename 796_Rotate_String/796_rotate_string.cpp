#include <iostream>
#include <string>

using namespace std;

bool rotateString(string A, string B) {
    if (A.length() != B.length() || A.length() > 100 || B.length() > 100) //never PASS 
        return false;
    string AA = "";
    AA = A.append(A, 0, A.length()); //再append自己一次，就會包含所有旋轉可能
    return (AA.find(B, 0) != std::string::npos);
}

int main() {
    string A = "abcde";
    string B = "cdeab";
    bool res = rotateString(A, B);
    if (res)
    	cout << "Yes, A contains B" << endl;
    else
	cout << "No" << endl;

    return 0;
}
