#include <iostream>
#include <string>    

using namespace std;

string addBinary(string a, string b) {
        int len_a = a.length();
        int len_b = b.length();
        string res("");
        int carry = 0;
        
        int round = (len_a>=len_b) ? len_a : len_b;
        int interval = (len_a>=len_b) ? len_a - len_b : len_b - len_a;
        
        while(interval--) {
            if (len_a<len_b) {
                a.insert(a.begin(), '0');
            } else {
                b.insert(b.begin(), '0');
            }
       }
        //cout << "a=" << a << ", b=" << b << endl;
        const char *str_a = a.c_str();
        const char *str_b = b.c_str();
        cout << "str_a=" << str_a << ", str_b=" <<  str_b << ", round=" << round << endl;
        
        for (int i=round-1; i>=0; i--) {
                if ((str_a[i]-'0') != (str_b[i]-'0')) {  //0+1 or 1+0 case
                    //cout << "Enter case 0+1 or 1+0" << endl;
                    if (carry) {  //there is a carry in previous calculate
                        res.insert(res.begin(), '0');
                        carry = 1;
                        continue;
                    } else {
                        res.insert(res.begin(), '1');
                        carry = 0;
                        continue;
                    }
                }
            
                if ((str_a[i]-'0') == 0 && (str_b[i]-'0') == 0) { //0+0 case
                    //cout << "Enter case 0+0" << endl;
                    if (carry) {
                        res.insert(res.begin(), '1');
                        carry = 0;
                        continue;
                    } else {
                        res.insert(res.begin(), '0');
                        carry = 0;
                        continue;
                    }
                }
            
                if ((str_a[i]-'0') == 1 && (str_b[i]-'0') == 1) { //1+1 case
                    //cout << "Enter case 1+1" << endl;
                    if (carry) {
                        res.insert(res.begin(), '1');
                        carry = 1;
                        continue;
                    } else {
                        res.insert(res.begin(), '0');
                        carry = 1;
                        continue;
                    }
                }
        }
        if (carry) //After finish last calculation, there is still a carry
            res.insert(res.begin(), '1');
        return res;
    }

int main() {
    char str_a[10];
    char str_b[10];
    cout << "Please enter a string(e.g \"1011\"):" << endl;
    scanf("%9s", str_a); //need one space for '\0'
    cout << "Please enter a string again(e.g \"1011\"):" << endl;
    scanf("%9s", str_b);
    //string a("1010");
    //string b("1011");
    string res;
    res = addBinary(str_a, str_b);
    cout << "After adding , result=" << res << endl;
    return 0;
}
