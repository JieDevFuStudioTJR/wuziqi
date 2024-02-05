#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

void START(string name){
    system("color 4");
	cout<<"■■■■  ■■■■   ■■■■"<<endl;
	_sleep(0.10*1000);
	cout<<"      ■  ■     ■  ■"<<endl;
	_sleep(0.10*1000);
	cout<<"      ■  ■     ■  ■"<<endl;
	_sleep(0.10*1000);
	cout<<"      ■  ■     ■  ■■■■"<<endl;
	_sleep(0.10*1000);
	cout<<"      ■  ■     ■  ■"<<endl;
	_sleep(0.10*1000);
	cout<<"      ■  ■     ■  ■"<<endl;
	_sleep(0.10*1000);
	cout<<"  ■■■  ■■■■   ■"<<endl;
	_sleep(0.10*1000);
	cout<<endl;
	_sleep(0.10*1000);
	cout<<"    接地府-软件科技"<<endl;
	cout<<"基于C++语言构建的应用程序"<<endl;
	cout<<" 项目:"<<name<<'\n';
	cout<<"        正在加载..."<<endl;

    int temp=15;
    while(temp--){
        cout<<"■";
		_sleep(0.15*1000);
    }
	system("color 07");
	system("cls");
}