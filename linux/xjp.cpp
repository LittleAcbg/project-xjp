#include <bits/stdc++.h>
#include "xjp.h"
using namespace std;
int n,m,l,cnt,pr[30],pc[30],qr[30],qc[30],qw[30],pl,curstrk,bststrk;
double base,score,dt;
bool vis[30],wa[30],inter[30];
string s,seed;
char c;
chrono::high_resolution_clock::time_point ti,ti2;
string mp[30][40][40];
void setcolor(string s) {
    if (s=="red") cout<<"\033[1;31m";
    else if (s=="cyan") cout<<"\033[1;36m";
    else if (s=="green") cout<<"\033[1;32m";
    else if (s=="yellow") cout<<"\033[1;33m";
    else cout<<"\033[m";
}
void setcolor() {
    cout<<"\033[m";
}
void setcolor(int x) {
    cout<<"\033[3"<<x<<"m";
}
int render(int k) {
    ti2=chrono::high_resolution_clock::now();
    chrono::duration<double> d=ti2-ti;
    ti=ti2;
    base-=dt*d.count();
    if (base<30) return 0;
    system("clear");
    for (int i=1;i<=l;++i) {
        setcolor(vis[i]?"green":(wa[i]?"red":""));
        cout<<" ["[i==k]<<char(i+'A'-1)<<" ]"[i==k];
        cout<<" \n"[i==l];
    }
    setcolor();
    cout<<"\nThis problem is "<<(inter[k]?"Interactive":"Traditional")<<".\n"<<endl;
    for (int i=1;i<=n;++i) {
        cout<<(i==qr[k]&&1==qc[k]?'[':' ');
        for (int j=1;j<=m;++j) {
            cout<<mp[k][i][j];
            cout<<(i==qr[k]&&j==qc[k]?']':i==qr[k]&&j==qc[k]-1?'[':' ');
        }
        putchar('\n');
    }
    cout<<endl;
    cout<<"Base pt "<<base<<" | Current score "<<score<<"\nGuess (Arrow Keys) | Check (0) | Exit (quit) | Pause (=) | Jump (Letters): ";
    getline(cin,s);
    if (!s.size()) return 1;
    else if (s.size()>=4&&s.substr(0,4)=="quit") return 0;
    c=s[0];
    if (islower(c)) c=toupper(c);
    if (isupper(c)) {
        if (c-'A'+1<=l&&c-'A'+1!=k) {
            pl=c-'A'+1;
            system("clear");
        }
    }
    else if (c=='0') {
        if (!vis[k]) {
            system("clear");
            if (pr[k]==qr[k]&&pc[k]==qc[k]) vis[k]=1,score+=base;
            else wa[k]=1;
        }
    }
    else if (c==27) {
        c=s[2];
        if (!vis[k]) {
            if (c==65) qr[k]=(qr[k]+n-2)%n+1;
            else if (c==66) qr[k]=qr[k]%n+1;
            else if (c==68) qc[k]=(qc[k]+m-2)%m+1;
            else if (c==67) qc[k]=qc[k]%m+1;
        }
    }
    else if (c=='=') return 2;
    return 1;
}
int infinite(int k) {
    system("clear");
    cout << "Training mode\n\n";
    for (int i=1;i<=n;++i) {
        cout<<(i==qr[k]&&1==qc[k]?'[':' ');
        for (int j=1;j<=m;++j) {
            cout<<(i==pr[k]&&j==pc[k]?c2[qw[k]]:c1[qw[k]]);
            cout<<(i==qr[k]&&j==qc[k]?']':i==qr[k]&&j==qc[k]-1?'[':' ');
        }
        putchar('\n');
    }
    cout<<endl;
    cout<<"Current streak: "<<curstrk<<" | Best: "<<bststrk<<"\nGuess (Arrow Keys) | Check (0) | Exit (quit) | Skip (skip): ";
    getline(cin,s);
    if (!s.size()) return 1;
    c=s[0];
    if (c=='0') {
        if (!vis[k]) {
            if (pr[k]==qr[k]&&pc[k]==qc[k]) vis[k]=1,score+=base;
            else wa[k]=1;
        }
    }
    else if (c==27) {
        c=s[2];
        if (!vis[k]) {
            if (c==65) qr[k]=(qr[k]+n-2)%n+1;
            else if (c==66) qr[k]=qr[k]%n+1;
            else if (c==68) qc[k]=(qc[k]+m-2)%m+1;
            else if (c==67) qc[k]=qc[k]%m+1;
        }
    }
    else if (s.size()>=4&&s.substr(0,4)=="quit") return 2;
    else if (s.size()>=4&&s.substr(0,4)=="skip") wa[k] = 1;
    return 1;
}
void training_mode()
{
    system("clear");
    cout<<"Codeforces (Training mode)\nSelect Division ((20,20),(15,15),(10,10)): ";
    cin >> n;
    if (n==0) {
        n=30;
        m=30;
    }
    else if (n==1) {
        n=20;
        m=20;
    }
    else if (n==2) {
        n=15;
        m=15;
    }
    else {
        n=10;
        m=10;
    }
    cout<<"Seed: ";
    cin>>seed;
    mt19937 rnd(hash<string>()(seed));
    cout<<"Press <Enter> to start\n";
    getchar();
    getchar();
    while (1) {
        system("clear");
        pr[1]=rnd()%n+1;
        pc[1]=rnd()%m+1;
        qw[1]=rnd()%N+1;
        qr[1]=1;
        qc[1]=1;
        while (1) {
            int x=infinite(1);
            if (x==2) {
                cout<<"\nok Finished best streak = "<<bststrk<<endl;
                return;
            }
            else if (vis[1]) {
                vis[1] = 0;
                setcolor("green");
                printf("\nAccepted!\n");
                setcolor();
                cout<<"Press <Enter> to continue\n";
                getchar();
                if (++curstrk > bststrk) bststrk = curstrk;
                break;
            }
            else if (wa[1]) {
                wa[1] = 0;
                curstrk = 0;
                system("clear");
                cout << "Training mode\n\n";
                qr[1]=pr[1];
                qc[1]=pc[1];
                for (int i=1;i<=n;++i) {
                    cout<<(i==qr[1]&&1==qc[1]?'[':' ');
                    for (int j=1;j<=m;++j) {
                        cout<<(i==pr[1]&&j==pc[1]?c2[qw[1]]:c1[qw[1]]);
                        cout<<(i==qr[1]&&j==qc[1]?']':i==qr[1]&&j==qc[1]-1?'[':' ');
                    }
                    putchar('\n');
                }
                cout<<endl;
                cout<<"Current streak: "<<curstrk<<" | Best: "<<bststrk<<"\nGuess (Arrow Keys) | Check (0) | Exit (quit) | Skip (skip): ";
                setcolor("red");
                printf("\nWrong Answer!\n");
                setcolor();
                cout<<"Press <Enter> to continue\n";
                getchar();
                break;
            }
            else if (!x) {
                break;
            }
        }
    }
}
void contest() {
    system("clear");
    cout<<"Codeforces (Contest mode)\nSelect Division ((20,20,12),(15,15,10),(10,10,6)): ";
    cin>>n;
    dt=0.1;
    if (n==0) {
        n=30;
        m=30;
        l=15;
    }
    else if (n==1) {
        n=20;
        m=20;
        l=12;
    }
    else if (n==2) {
        n=15;
        m=15;
        l=10;
    }
    else {
        n=10;
        m=10;
        l=6;
    }
    cout<<"Seed: ";
    cin>>seed;
    cout<<"Interaction prob (0-100 integer): ";
    int prob;
    cin>>prob;
    if (prob<0) prob=0;
    else if (prob>100) prob=100;
    mt19937 rnd(hash<string>()(seed));
    cout<<"Press <Enter> to start\n";
    getchar();
    getchar();
    for (int k=1;k<=l;++k)
        if (rnd()%100<prob) {
            inter[k]=1;
            pr[k]=rnd()%n+1;
            pc[k]=rnd()%m+1;
            qw[k]=rnd()%INTER+1;
            qr[k]=1;
            qc[k]=1;
            for (int i=1;i<=n;++i) for (int j=1;j<=m;++j)
                if (i==pr[k]&&j==pc[k]) mp[k][i][j]=a1[qw[k]];
                else if (rnd()&1) mp[k][i][j]=a2[qw[k]];
                else mp[k][i][j]=a3[qw[k]];
        }
        else {
            pr[k]=rnd()%n+1;
            pc[k]=rnd()%m+1;
            qw[k]=rnd()%N+1;
            qr[k]=1;
            qc[k]=1;
            for (int i=1;i<=n;++i) for (int j=1;j<=m;++j)
                if (i==pr[k]&&j==pc[k]) mp[k][i][j]=c1[qw[k]];
                else mp[k][i][j]=c2[qw[k]];
        }
    pl=1;
    cout<<fixed<<setprecision(3);
    ti=chrono::high_resolution_clock::now();
    base=100;
    while (1)
    {
        int x=render(pl);
        if (!x) break;
        if (x == 2)
        {
            ti2=chrono::high_resolution_clock::now();
            chrono::duration<double> d=ti2-ti;
            ti=ti2;
            base-=dt*d.count();
            system("clear");
            cout<<"Press <Enter> to continue\n";
            getchar();
            ti=chrono::high_resolution_clock::now();
        }
    }
    cout<<"ok Finished "<<score<<" pts\n";
}
int interact() {
    system("clear");
    cout << "Interaction Training\n\n";
    for (int i=1;i<=n;++i) {
        cout<<(i==qr[0]&&1==qc[0]?'[':' ');
        for (int j=1;j<=m;++j) {
            cout<<mp[0][i][j];
            cout<<(i==qr[0]&&j==qc[0]?']':i==qr[0]&&j==qc[0]-1?'[':' ');
        }
        putchar('\n');
    }
    cout<<endl;
    cout<<"Current streak: "<<curstrk<<" | Best: "<<bststrk<<"\nGuess (Arrow Keys) | Check (0) | Exit (quit) | Skip (skip): ";
    getline(cin,s);
    if (!s.size()) return 1;
    c=s[0];
    if (c=='0') {
        if (!vis[0]) {
            if (pr[0]==qr[0]&&pc[0]==qc[0]) vis[0]=1,score+=base;
            else wa[0]=1;
        }
    }
    else if (c==27) {
        c=s[2];
        if (!vis[0]) {
            if (c==65) qr[0]=(qr[0]+n-2)%n+1;
            else if (c==66) qr[0]=qr[0]%n+1;
            else if (c==68) qc[0]=(qc[0]+m-2)%m+1;
            else if (c==67) qc[0]=qc[0]%m+1;
        }
    }
    else if (s.size()>=4&&s.substr(0,4)=="quit") return 2;
    else if (s.size()>=4&&s.substr(0,4)=="skip") wa[0] = 1;
    return 1;
}
void find_C_in_A_and_B()
{
    system("clear");
    cout<<"Codeforces (Interaction Training)\nSelect Division ((20,20),(15,15),(10,10)): ";
    cin >> n;
    if (n==0) {
        n=30;
        m=30;
    }
    else if (n==1) {
        n=20;
        m=20;
    }
    else if (n==2) {
        n=15;
        m=15;
    }
    else {
        n=10;
        m=10;
    }
    cout<<"Seed: ";
    cin>>seed;
    mt19937 rnd(hash<string>()(seed));
    cout<<"Press <Enter> to start\n";
    getchar();
    getchar();
    while (1) {
        system("clear");
        pr[0]=rnd()%n+1;
        pc[0]=rnd()%m+1;
        qw[0]=rnd()%INTER+1;
        qr[0]=1;
        qc[0]=1;
        for (int i=1;i<=n;++i) for (int j=1;j<=m;++j)
            if (i==pr[0]&&j==pc[0]) mp[0][i][j]=a1[qw[0]];
            else if (rnd()&1) mp[0][i][j]=a2[qw[0]];
            else mp[0][i][j]=a3[qw[0]];
        while (1) {
            int x=interact();
            if (x==2) {
                cout<<"\nok Finished best streak = "<<bststrk<<endl;
                return;
            }
            else if (vis[0]) {
                vis[0] = 0;
                setcolor("green");
                printf("\nAccepted!\n");
                setcolor();
                cout<<"Press <Enter> to continue\n";
                getchar();
                if (++curstrk > bststrk) bststrk = curstrk;
                break;
            }
            else if (wa[0]) {
                wa[0] = 0;
                curstrk = 0;
                system("clear");
                cout << "Training mode\n\n";
                qr[0]=pr[0];
                qc[0]=pc[0];
                for (int i=1;i<=n;++i) {
                    cout<<(i==qr[0]&&1==qc[0]?'[':' ');
                    for (int j=1;j<=m;++j) {
                        cout<<mp[0][i][j];
                        cout<<(i==qr[0]&&j==qc[0]?']':i==qr[0]&&j==qc[0]-1?'[':' ');
                    }
                    putchar('\n');
                }
                cout<<endl;
                cout<<"Current streak: "<<curstrk<<" | Best: "<<bststrk<<"\nGuess (Arrow Keys) | Check (0) | Exit (quit) | Skip (skip): ";
                setcolor("red");
                printf("\nWrong Answer!\n");
                setcolor();
                cout<<"Press <Enter> to continue\n";
                getchar();
                break;
            }
            else if (!x) {
                break;
            }
        }
    }
}
void duel()
{
    cout<<"Duel is currently in development. Wait until the next update!\n";
    return;
}
int main()
{
    cout << "Codeforces\nSelect Section (Contest, Training, Interactive, Duel): ";
    cin >> n;
    if (n == 1) contest();
    else if (n == 2) training_mode();
    else if (n == 3) find_C_in_A_and_B();
    else if (n == 4) duel();
    else cout << "Invalid input.\nTerminated.\n";
    return 0;
}
