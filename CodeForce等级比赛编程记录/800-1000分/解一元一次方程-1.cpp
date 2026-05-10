#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int coef = 0;  // 变量系数
    int constant = 0;  // 常数项
    int sign = 1;  // 当前符号
    int equal_flag = 0;  // 是否遇到等号
    char var;  // 变量名
    
    for (int i = 0; i < s.size(); ) {
        if (s[i] == '=') {
            equal_flag = 1;
            sign = -1;  // 等号后符号反转
            i++;
        }
        else if (s[i] == '+') {
            sign = (equal_flag ? -1 : 1);
            i++;
        }
        else if (s[i] == '-') {
            sign = (equal_flag ? 1 : -1);
            i++;
        }
        else {
            // 解析数字
            int num = 0;
            bool has_num = false;
            while (i < s.size() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                has_num = true;
                i++;
            }
            
            // 处理变量或常数项
            if (i < s.size() && islower(s[i])) {
                var = s[i];
                if (!has_num) num = 1;  // 默认系数1
                coef += sign * num;
                i++;
            }
            else {
                constant += sign * num;
            }
        }
    }
    
    // 解方程
    if (coef == 0) {
        if (constant == 0) cout << "Infinite solutions";
        else cout << "No solution";
    }
    else {
        double ans = -constant * 1.0 / coef;
        cout << var << "=" << fixed << setprecision(3) << ans;  // 保留3位小数
    }
    
    return 0;
}