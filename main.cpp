#include<bits/stdc++.h>
#include<windows.h>
#include"JieDevFu_v1.0.h"

#define setcolor SetConsoleTextAttribute
#define hc hConsole

using namespace std;

struct CHARACTER{
    int x,y;
    char w;
};

const int maxn=19;
CHARACTER dis[maxn][maxn];

inline void setC(char x,char y,char w){
    CHARACTER psh;
    psh.x=x;
    psh.y=y;
    psh.w=w;
    dis[x][y]=psh;
}

int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

bool dfs(int x,int y,int dep,int dir){
    if(dep==6){
        return true;
    }
    bool ans=true;
    if(x+dx[dir]>=1 && y+dy[dir]>=1 && x+dx[dir]<maxn && y+dy[dir]<maxn){
        bool tmp= dis[x][y].w == dis[x+dx[dir]][y+dy[dir]].w;
        if(tmp){
            tmp=tmp && dfs(x+dx[dir],y+dy[dir],dep+1,dir);
        }
        else{
            return false;
        }
        ans=ans && tmp;
        return ans;
    }
    else{
        return false;
    }
}

bool start_dfs(char x,char y){
    bool ans=false;
    for(int i=0;i^8;i++){
        ans=ans || dfs(x,y,dis[x][y].w,i);
    }
    return ans;
}

void print(char color,string putt){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if(color>='0' && color<='9'){
        setcolor(hc,color);
    }
    else{
        setcolor(hc,color);
    }

    cout<<putt;

    // setcolor(hc,0x7);
}

char pts[18]={'1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I'};
void printx(int ux,int uy){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    setcolor(hc,0x61);
    cout<<"  ";
    int cnt=-1;
    for(int i=0;i^18;i++){
        cout<<pts[i]<<' ';
    }
    setcolor(hc,0x7);
    cout<<'\n';
    for(int i=1;i<=18;i++){
        ++cnt;
        setcolor(hc,0x61);
        cout<<pts[cnt]<<' ';
        for(int j=1;j<=18;j++){
            if(i==ux && j==uy){
                print(0x64,"■");
                setcolor(hc,0x61);
                continue;
            }
            if(dis[i][j].w){
                if(dis[i][j].w==1){
                    print(0x60,"■");
                    setcolor(hc,0x61);
                }
                else{
                    print(0x6f,"■");
                    setcolor(hc,0x61);
                }
            }
            else{
                print(0x61,"□");
            }
        }
        setcolor(hc,0x7);
        cout<<'\n';
    }

}

int main(){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    string op;
    char x,y;
    char w=1;
    START("双人五子棋");
    cout<<"提示：黑方为先手\n\n\n";
    while(1){
        cin>>op;
        if(op=="set"){
            cin>>x>>y;
            bool chk=true;
            if(!((x>='1' && x<='9')||(x>='A' && x<='I'))){
                chk=false;
            }
            if(!((y>='1' && y<='9')||(y>='A' && y<='I'))){
                chk=false;
            }
            if(x>='0' && x<='9'){
                x-=48;
            }
            else{
                x-=55;
            }
            if(y>='0' && y<='9'){
                y-=48;
            }
            else{
                y-=55;
            }
            if(dis[x][y].w){
                chk=false;
            }
            if(!chk){
                setcolor(hc,0x4);
                cout<<"命令有错误 请检查命令并重新输入正确的命令\n";
                setcolor(hc,0x7);
            }
            setC(x,y,w);
            if(w==1){
                w=2;
            }
            else{
                w=1;
            }
            cout<<"\n\n\n\n";
            printx(x,y);
            bool brk=true;
            for(int i=1;i<=18;i++){
                for(int j=1;j<=18;j++){
                    if(dis[i][j].w)
                    if(start_dfs(x,y)){
                        cout<<"\n\n\n";
                        if(w==1){
                            cout<<"白";
                        }
                        else{
                            cout<<"黑";
                        }
                        cout<<"方胜\n请输入 replay 重开一局 或者 输入exit退出\n";
                        brk=false;
                        system("pause");
                        break;
                    }
                }
                if(!brk){
                    break;
                }
            }
            setcolor(hc,0x7);
            cout<<"\n\n\n";
        }
        else if(op=="exit"){
            system("pause");
            return 0;
        }
        else if(op=="replay"){
            CHARACTER Std;
            Std.x=0;
            Std.y=0;
            Std.w=0;
            for(int i=1;i<maxn;i++){
                for(int j=1;j<maxn;j++){
                    dis[i][j]=Std;
                }
            }
            cout<<"\n棋盘重置完毕 现在可以开始了\n\n";
        }
        else if(op=="cls"){
            system("cls");
            printx(0,0);
        }
        else if(op=="check"){
            if(w==1){
                cout<<"你是黑方\n";
            }
            else{
                cout<<"你是白方\n";
            }
        }
        else if(op=="print"){
            cout<<"\n";
            printx(0,0);
            cout<<"\n\n";
        }
        else{
            setcolor(hc,0x4);
            cout<<"未知的命令\n";
            setcolor(hc,0x7);
        }
    }
    return 0;
}