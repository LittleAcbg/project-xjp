#include <bits/stdc++.h>
using namespace std;
vector<string> c1,c2;
string s,t;
int main()
{
    freopen("xjp.settings", "r", stdin);
    freopen("xjp.h", "w", stdout);
    while (cin >> s >> t)
    {
        string _s = "",_t = "";
        for (auto c : s)
        {
            if (c == '"' || c == '\\') _s += '\\';
            _s += c;
        }
        for (auto c : t)
        {
            if (c == '"' || c == '\\') _t += '\\';
            _t += c;
        }
        c1.push_back(_s);
        c2.push_back(_t);
        c1.push_back(_t);
        c2.push_back(_s);
    }
    cout << "#ifndef _XJP_SETTINGS\n#define _XJP_SETTINGS\n#include <string>\n";
    cout << "const int N = " << c1.size() << ";\n";
    cout << "const std::string c1[N+1] = {\"\",";
    for (int i = 0; i < c1.size(); ++i) cout << '"' << c1[i] << '"' << ",}"[i == c1.size() - 1];
    cout << ",c2[N+1] = {\"\",";
    for (int i = 0; i < c2.size(); ++i) cout << '"' << c2[i] << '"' << ",}"[i == c2.size() - 1];
    cout << ";\n#endif";
    return 0;
}