#include <bits/stdc++.h>
using namespace std;
vector<string> c1,c2,a1,a2,a3,d1,d2,d3;
string s,t,u;
int main()
{
    ifstream fin("xjp.settings");
    ifstream gin("interaction.settings");
    ifstream din("duel.settings");
    freopen("xjp.h", "w", stdout);
    while (fin >> s >> t)
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
    while (gin >> s >> t >> u)
    {
        string _s = "",_t = "",_u = "";
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
        for (auto c : u)
        {
            if (c == '"' || c == '\\') _u += '\\';
            _u += c;
        }
        a1.push_back(_s);
        a1.push_back(_t);
        a1.push_back(_u);
        a2.push_back(_t);
        a2.push_back(_u);
        a2.push_back(_s);
        a3.push_back(_u);
        a3.push_back(_s);
        a3.push_back(_t);
    }
    while (din >> s >> t >> u)
    {
        string _s = "",_t = "",_u = "";
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
        for (auto c : u)
        {
            if (c == '"' || c == '\\') _u += '\\';
            _u += c;
        }
        d1.push_back(_s);
        d2.push_back(_t);
        d3.push_back(_u);
    }
    cout << "#ifndef _XJP_SETTINGS\n#define _XJP_SETTINGS\n#include <string>\n";
    cout << "const int N = " << c1.size() << ";\nconst std::string c1[N+1] = {\"\",";
    for (int i = 0; i < c1.size(); ++i) cout << '"' << c1[i] << '"' << ",}"[i == c1.size() - 1];
    cout << ",c2[N+1] = {\"\",";
    for (int i = 0; i < c2.size(); ++i) cout << '"' << c2[i] << '"' << ",}"[i == c2.size() - 1];
    cout << ";\nconst int INTER = " << a1.size() << ";\nconst std::string a1[INTER+1] = {\"\",";
    for (int i = 0; i < a1.size(); ++i) cout << '"' << a1[i] << '"' << ",}"[i == a1.size() - 1];
    cout << ",a2[INTER+1] = {\"\",";
    for (int i = 0; i < a2.size(); ++i) cout << '"' << a2[i] << '"' << ",}"[i == a2.size() - 1];
    cout << ",a3[INTER+1] = {\"\",";
    for (int i = 0; i < a3.size(); ++i) cout << '"' << a3[i] << '"' << ",}"[i == a3.size() - 1];
    cout << ";\nconst int DUEL = " << d1.size() << ";\nconst std::string d1[DUEL+1] = {\"\",";
    for (int i = 0; i < d1.size(); ++i) cout << '"' << d1[i] << '"' << ",}"[i == d1.size() - 1];
    cout << ",d2[DUEL+1] = {\"\",";
    for (int i = 0; i < d2.size(); ++i) cout << '"' << d2[i] << '"' << ",}"[i == d2.size() - 1];
    cout << ",d3[DUEL+1] = {\"\",";
    for (int i = 0; i < d3.size(); ++i) cout << '"' << d3[i] << '"' << ",}"[i == d3.size() - 1];
    cout << ";\n#endif\n";
    return 0;
}
