#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int size = digits.size();
    vector<int>::iterator it = digits.begin();
    //cout << "size of digits = " << size << endl;

    for(int i=size-1; i>=0; i--) {
        it[i]++;
        //cout << it[i] << endl;
        if (it[i] <= 9) { //no need to carry
            return digits;
        }
        else {
            it[i] = 0;
        }
    }
    //Get here if all number need to carry
    digits.insert(digits.begin(), 1);
    return digits;
}

int main() {
    vector<int> digits{9};
    vector<int> res;
    res = plusOne(digits);
    for (int i=0;i<res.size();i++)
        cout << res[i];
    cout << endl;
    return 0;
}
