#include <bits/stdc++.h> 

using namespace std; 

string add(string a, string b) { 
    if (a.size() < b.size()) swap(a, b); 

    reverse(a.begin(), a.end()); 
    reverse(b.begin(), b.end()); 

    while (b.size() < a.size()) b += '0'; 

    int carry = 0; 
    string result = ""; 

    for (int i = 0; i < a.size(); ++i) { 
        int sum = (a[i] - '0') + (b[i] - '0') + carry; 
        carry = sum / 10; 
        result += (sum % 10) + '0'; 
    } 

    if (carry) result += carry + '0'; 

    reverse(result.begin(), result.end()); 
    return result; 
} 

string sub(string a, string b) { 
    if (a == b) return "0"; 
    bool neg = false; 
    if (a.size() < b.size() || (a.size() == b.size() && a < b)) { 
        swap(a, b); 
        neg = true; 
    } 

    reverse(a.begin(), a.end()); 
    reverse(b.begin(), b.end()); 

    while (b.size() < a.size()) b += '0'; 

    int borrow = 0; 
    string result = ""; 

    for (int i = 0; i < a.size(); ++i) { 
        int diff = (a[i] - '0') - (b[i] - '0') - borrow; 
        if (diff < 0) { 
            diff += 10; 
            borrow = 1; 
        } else { 
            borrow = 0; 
        } 
        result += diff + '0'; 
    } 

    while (result.size() > 1 && result.back() == '0') result.pop_back(); 
    if (neg) result += '-'; 

    reverse(result.begin(), result.end()); 
    return result; 
} 

string mul(string a, string b) { 
    int n1 = a.size(), n2 = b.size(); 
    vector<int> result(n1 + n2, 0); 

    reverse(a.begin(), a.end()); 
    reverse(b.begin(), b.end()); 

    for (int i = 0; i < n1; ++i) { 
        for (int j = 0; j < n2; ++j) { 
            result[i + j] += (a[i] - '0') * (b[j] - '0'); 
            result[i + j + 1] += result[i + j] / 10; 
            result[i + j] %= 10; 
        } 
    } 

    int i = n1 + n2 - 1; 
    while (i >= 0 && result[i] == 0) i--; 
    if (i == -1) return "0"; 

    string ans = ""; 
    while (i >= 0) ans += result[i--] + '0'; 
    return ans; 
} 

int main() { 
    string a, b; 
    cin >> a >> b; 

    char sign_a = a[0], sign_b = b[0]; 
    a = a.substr(1);  
    b = b.substr(1);  

    string res = ""; 

    string ab = mul(a, b); 
    string _3a = mul("3", a); 
    string _4b = mul("4", b); 

    if (sign_a == '1' && sign_b == '1') { 
        string s1 = add(ab, _4b); 
        res = (s1.size() > _3a.size() || (s1.size() == _3a.size() && s1 > _3a)) 
              ? "1" + sub(s1, _3a) 
              : "0" + sub(_3a, s1); 
    } else if (sign_a == '1' && sign_b == '0') { 
        res = "0" + add(add(ab, _3a), _4b); 
    } else if (sign_a == '0' && sign_b == '0') { 
        string s1 = add(ab, _3a); 
        res = (s1.size() > _4b.size() || (s1.size() == _4b.size() && s1 > _4b)) 
              ? "1" + sub(s1, _4b) 
              : "0" + sub(_4b, s1); 
    } else { 
        string s1 = add(_3a, _4b); 
        res = (s1.size() > ab.size() || (s1.size() == ab.size() && s1 > ab)) 
              ? "1" + sub(s1, ab) 
              : "0" + sub(ab, s1); 
    } 

    cout << res; 
    return 0; 
}
