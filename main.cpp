#include <io.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
using namespace std;
#define white 0
#define red 1
#define blue 2
#define yellow 3
#define green 4
#define purple 5
#define cyan 6
#define gray 7
#define black 8
#define DEBUG 0
#define LL long long
int getawaw(){
	cout<<"按任意键继续"<<endl;
	char a=_getch();
}
void color(LL n){
    if (n==0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED);
    if (n==1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
    if (n==2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
    if (n==3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED);
    if (n==4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
    if (n==5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED);
    if (n==6) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
    if (n==7) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
    if (n==8) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
}
void cursorhide(){
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle,&CursorInfo);
    CursorInfo.bVisible=false;
    SetConsoleCursorInfo(handle,&CursorInfo);
}
void cursorshow(){
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle,&CursorInfo);
    CursorInfo.bVisible=true;
    SetConsoleCursorInfo(handle,&CursorInfo);
}
pair <int,int> getxy(){
    HANDLE hStdout;
    CONSOLE_SCREEN_BUFFER_INFO pBuffer; 
    hStdout=GetStdHandle(STD_OUTPUT_HANDLE); 
    GetConsoleScreenBufferInfo(hStdout,&pBuffer); 
    return make_pair(pBuffer.dwCursorPosition.X,pBuffer.dwCursorPosition.Y);
}
void gotoxy(int x,int y){
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;                            
    HANDLE hConsoleOut;
    hConsoleOut=GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
    csbiInfo.dwCursorPosition.X=x;                                    
    csbiInfo.dwCursorPosition.Y=y;                                    
    SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);   
}
void tellraw(string s,LL num1=0,LL num2=0,LL num3=0){
	//system("color 1A");
    color(white);
    bool colorful=false;
    bool pausing=false;
    int len=s.size();
    char c;
    for (LL i=0;i<len;++i){
        if (s[i]=='&'){
            i++;
            if (s[i]=='w') color(white);
            if (s[i]=='r') color(red);
            if (s[i]=='b') color(blue);
            if (s[i]=='y') color(yellow);
            if (s[i]=='c') color(cyan);
            if (s[i]=='p') color(purple);
            if (s[i]=='g') color(green);
            if (s[i]=='a') color(gray);
            if (s[i]=='n') color(black);
            if (s[i]=='+') pausing=true;
            else if (s[i]=='-') pausing=false;
            if (s[i]=='*') colorful=true;
            else colorful=false;
        }else if (s[i]=='%'){
            i++;
            if (s[i]=='1') printf("%lld",num1);
            if (s[i]=='2') printf("%lld",num2);
            if (s[i]=='3') printf("%lld",num3);
        }else if (s[i]=='|'){
            i++;
            if (s[i]=='n') putchar('\n');
            if (s[i]=='t') putchar('\t');
            if (s[i]=='|') putchar('|');
            if (s[i]=='%') printf("%%");
            if (s[i]=='&') putchar('&');
            if (s[i]=='p') c=_getch();
            if (s[i]=='c') system("cls");
            if (s[i]=='k') Sleep((DEBUG)?10:500);
        }else{
            if (colorful==true) color(rand()%8);
            if (pausing==true) Sleep((DEBUG)?2:100);
            putchar(s[i]);
        }
    }
    color(white);
}
void tellrawfast(string s,LL num1=0,LL num2=0,LL num3=0){
	//system("color 1A");
    color(white);
    bool colorful=false;
    bool pausing=false;
    int len=s.size();
    char c;
    for (LL i=0;i<len;++i){
        if (s[i]=='&'){
            i++;
            if (s[i]=='w') color(white);
            if (s[i]=='r') color(red);
            if (s[i]=='b') color(blue);
            if (s[i]=='y') color(yellow);
            if (s[i]=='c') color(cyan);
            if (s[i]=='p') color(purple);
            if (s[i]=='g') color(green);
            if (s[i]=='a') color(gray);
            if (s[i]=='n') color(black);
            if (s[i]=='+') pausing=true;
            else if (s[i]=='-') pausing=false;
            if (s[i]=='*') colorful=true;
            else colorful=false;
        }else if (s[i]=='%'){
            i++;
            if (s[i]=='1') printf("%lld",num1);
            if (s[i]=='2') printf("%lld",num2);
            if (s[i]=='3') printf("%lld",num3);
        }else if (s[i]=='|'){
            i++;
            if (s[i]=='n') putchar('\n');
            if (s[i]=='t') putchar('\t');
            if (s[i]=='|') putchar('|');
            if (s[i]=='%') printf("%%");
            if (s[i]=='&') putchar('&');
            if (s[i]=='p') c=_getch();
            if (s[i]=='c') system("cls");
            if (s[i]=='k') Sleep((DEBUG)?10:500);
        }else{
            if (colorful==true) color(rand()%8);
            if (pausing==true) Sleep((1)?2:100);
            putchar(s[i]);
        }
    }
    color(white);
}
char readkey(string s,string range=""){
    tellraw(s);
    int len=range.size();
    char c=_getch();
    while (true){
        for (int i=0;i<len;++i){
            if (c==range[i]) return c;
        }
        c=_getch();
    }
}
string inputbox(string s){
    tellraw(s+"|n");
    cursorshow();
    string t;
    color(white);
    cin>>t;
    cursorhide();
    return t;
}
int chosenbox(string s){
    int len=s.size();
    int i=0;
    string t="";
    while (s[i]!='@' && i<len) t=t+s[i],i++;
    tellraw(t);
    putchar('\n');
    pair <int,int> tmp=getxy(); 
    int j=i;
    t="";
    int item=0;
    for (int i=j+1;i<len;++i){
        if (s[i]=='#'){
            j=i;
            break;
        }else if (s[i]=='@'){
            item++;
            tellraw("    &c%1. &w"+t+"|n",item);
            t="";
        }else{
            t=t+s[i];
        }
    }
    t="";
    for (int i=j+1;i<len;++i){
        t=t+s[i];
    }
    tellraw(t);
    pair <int,int> tmp2=getxy();
    gotoxy(0,tmp.second);
    tellraw("&w>>");
    char c=_getch();
    int chosen=1;
    while (c!=13){
        if (c==72 || c==72){
            if (chosen>1){
                gotoxy(0,tmp.second+chosen-1);
                chosen--;
                printf("   ");
                gotoxy(0,tmp.second+chosen-1);
                tellraw("&w>>");
            }
        }else if (c==80 || c==80){
            if (chosen<item){
                gotoxy(0,tmp.second+chosen-1);
                chosen++;
                printf("   ");
                gotoxy(0,tmp.second+chosen-1);
                tellraw("&w>>");
            }           
        }else if (c>='1' && c<='9' && c-48<=item){
            gotoxy(0,tmp.second+chosen-1);
            chosen=c-48;
            printf("   ");
            gotoxy(0,tmp.second+chosen-1);
            tellraw("&w>>");           
        }else if (c==75 || c==75){
            gotoxy(0,tmp.second+chosen-1);
            chosen=1;
            printf("   ");
            gotoxy(0,tmp.second+chosen-1);
            tellraw("&w>>");           
        }else if (c==77 || c==77){
            gotoxy(0,tmp.second+chosen-1);
            chosen=item;
            printf("   ");
            gotoxy(0,tmp.second+chosen-1);
            tellraw("&w>>");           
        }
        c=_getch();
    }
    gotoxy(tmp2.first,tmp2.second);
    return chosen;
}
void getAllFiles(string path, vector<string>& files) 
{
	// 文件句柄
	long hFile = 0;
	// 文件信息
	struct _finddata_t fileinfo;  

	string p;

	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) {
		do {
			// 保存文件的全路径
			files.push_back(p.assign(path).append("\\").append(fileinfo.name));

		   } while (_findnext(hFile, &fileinfo) == 0);  //寻找下一个，成功返回0，否则-1

		_findclose(hFile);
	}
}
void start(){
	cout<<"这个程序用来自动编写gradle.bat，免除JAVA_HOME的烦恼。"<<endl;
	cout<<"作者的Java安装在默认位置（C:\\Program Files\\Java），作者推荐你也这么做。"<<endl;
	cout<<"如果你更改了Java的安装位置，";
	color(red);
	cout<<"该程序不会帮助你找到它";
	color(white);
	cout<<"，你需要使用JAVA_HOME。这个链接也许可以帮助你 https://www.xiaokong.space/" <<endl; 
	system("title 1.无JAVA_HOME之1_其一,setupDecomp,请先运行此脚本,再打开IDE"); 

}
string getJava2(){
	vector<string> s;
	getAllFiles("C:\\Program Files\\Java",s);
	vector<string>::iterator i;
	vector<string> java8;
	for(i=s.begin();i!=s.end();++i){
		if((*i).find("jdk1.8",0)!=string::npos || (*i).find("jdk-1.8",0)!=string::npos || ((*i).find("j")!=string::npos )){
			java8.push_back(*i);
		}
	}
	
	if(java8.size()==0){
		tellraw("&r 没有找到JDK8，你可能没有安装JDK8或JDK8不在默认安装位置！");
		return "%JAVA_HOME%";
	}
	
	vector<string>::iterator o;
	string cho;
	cho=cho+"@";
	//vector<string> choice;
	string Java8List[100];
	string Java8ListPath[100];
	int ioindex=1;
	for(o=java8.begin();o!=java8.end();++o){
		string p_1=(*o);
		for(int p_2=0;p_2<p_1.size();p_2++){
			if(p_1[p_2]=='\\'){
				p_2++;
				p_1.insert(p_2,"\\");
			}
		}
		Java8List[ioindex]=p_1;
		Java8ListPath[ioindex]=(*o);
		ioindex++;
		//choice.push_back(p_1);
		cho=cho+(*o)+"@";
	}
	cho=cho+"#"; 
	
	
	int index=chosenbox(cho);

	cout<<endl;
	cout<<endl;
	cout<<endl;
	
	return Java8ListPath[index];
}
string getJava(){
	vector<string> s;
	getAllFiles("C:\\Program Files\\Java",s);
	vector<string>::iterator i;
	vector<string> java8;
	for(i=s.begin();i!=s.end();++i){
		if((*i).find("jdk1.8",0)!=string::npos || (*i).find("jdk-1.8",0)!=string::npos){
			java8.push_back(*i);
		}
	}
	
	if(java8.size()==0){
		tellraw("&r 没有找到JDK8，你可能没有安装JDK8或JDK8不在默认安装位置！");
		return "%JAVA_HOME%";
	}
	
	vector<string>::iterator o;
	string cho;
	cho=cho+"@";
	//vector<string> choice;
	string Java8List[100];
	string Java8ListPath[100];
	int ioindex=2;
	cho=cho+"没有找到我的Java"+"@";
	for(o=java8.begin();o!=java8.end();++o){
		string p_1=(*o);
		for(int p_2=0;p_2<p_1.size();p_2++){
			if(p_1[p_2]=='\\'){
				p_2++;
				p_1.insert(p_2,"\\");
			}
		}
		Java8List[ioindex]=p_1;
		Java8ListPath[ioindex]=(*o);
		ioindex++;
		//choice.push_back(p_1);
		cho=cho+(*o)+"@";
		//printf("%s \n",(*o).c_str());
	}
	cho=cho+"#"; 
	
	
	int index=chosenbox(cho);

	cout<<endl;
	cout<<endl;
	cout<<endl;
	
	if(index==1)return getJava2();
	else {
		if(index<=ioindex){
			return Java8ListPath[index];
		}
	}
}
int out_bat(string java_home){
	//printf("%s\n",java_home.c_str());
	string java_exe=java_home+"/bin/java.exe";
	string bef("@if \"%DEBUG%\" == \"\" @echo off\n@rem ##########################################################################\n@rem\n@rem  Gradle startup script for Windows\n@rem\n@rem ##########################################################################\n\n@rem Set local scope for the variables with windows NT shell\nif \"%OS%\"==\"Windows_NT\" setlocal\n\nset DIRNAME=%~dp0\nif \"%DIRNAME%\" == \"\" set DIRNAME=.\nset APP_BASE_NAME=%~n0\nset APP_HOME=%DIRNAME%\n\n@rem Add default JVM options here. You can also use JAVA_OPTS and GRADLE_OPTS to pass JVM options to this script.\nset DEFAULT_JVM_OPTS=\n\n@rem Find java.exe\nif defined JAVA_HOME goto findJavaFromJavaHome\n\nset JAVA_EXE=java.exe\n%JAVA_EXE% -version >NUL 2>&1\nif \"%ERRORLEVEL%\" == \"0\" goto init\n\necho.\necho ERROR: JAVA_HOME is not set and no 'java' command could be found in your PATH.\necho.\necho Please set the JAVA_HOME variable in your environment to match the\necho location of your Java installation.\n\ngoto fail\n\n:findJavaFromJavaHome\nset JAVA_HOME=");
	string mid("\nset JAVA_EXE=");
	string aft("\nif exist \"%JAVA_EXE%\" goto init\n\necho.\necho ERROR: JAVA_HOME is set to an invalid directory: %JAVA_HOME%\necho.\necho Please set the JAVA_HOME variable in your environment to match the\necho location of your Java installation.\n\ngoto fail\n\n:init\n@rem Get command-line arguments, handling Windows variants\n\nif not \"%OS%\" == \"Windows_NT\" goto win9xME_args\n\n:win9xME_args\n@rem Slurp the command line arguments.\nset CMD_LINE_ARGS=\nset _SKIP=2\n\n:win9xME_args_slurp\nif \"x%~1\" == \"x\" goto execute\n\nset CMD_LINE_ARGS=%*\n\n:execute\n@rem Setup the command line\n\nset CLASSPATH=%APP_HOME%\\gradle\\wrapper\\gradle-wrapper.jar\n\n@rem Execute Gradle\n\"%JAVA_EXE%\" %DEFAULT_JVM_OPTS% %JAVA_OPTS% %GRADLE_OPTS% \"-Dorg.gradle.appname=%APP_BASE_NAME%\" -classpath \"%CLASSPATH%\" org.gradle.wrapper.GradleWrapperMain %CMD_LINE_ARGS%\n\n:end\n@rem End local scope for the variables with windows NT shell\nif \"%ERRORLEVEL%\"==\"0\" goto mainEnd\n\n:fail\nrem Set variable GRADLE_EXIT_CONSOLE if you need the _script_ return code instead of\nrem the _cmd.exe /c_ return code!\nif  not \"\" == \"%GRADLE_EXIT_CONSOLE%\" exit 1\nexit /b 1\n\n:mainEnd\nif \"%OS%\"==\"Windows_NT\" endlocal\n\n:omega");
	ofstream pp("outGradlew.bat");
	pp<<bef<<java_home<<mid<<java_exe<<aft;
	tellraw("&y out file : outGradlew.bat |n");
	pp.close();
	
	ofstream outBat("runOutGradlew.bat");
	outBat<<"@echo off\n\"C:\\Windows\\System32\\chcp.com\" 65001\ncd /d \"%~dp0\"\necho %JAVA_TOOL_OPTIONS% | \"C:\\Windows\\System32\\findstr.exe\" /C:\"-Dfile.encoding=\" > nul\nif errorlevel 1 (\n    if defined JAVA_TOOL_OPTIONS (\n        \"C:\\Windows\\System32\\setx.exe\" JAVA_TOOL_OPTIONS \"%JAVA_TOOL_OPTIONS% -Dfile.encoding=UTF-8\"\n        set \"JAVA_TOOL_OPTIONS=%JAVA_TOOL_OPTIONS% -Dfile.encoding=UTF-8\"\n    ) else (\n        \"C:\\Windows\\System32\\setx.exe\" JAVA_TOOL_OPTIONS \"-Dfile.encoding=UTF-8\"\n        set \"JAVA_TOOL_OPTIONS=-Dfile.encoding=UTF-8\"\n    )\n)\ncall outGradlew.bat setupDecompWorkspace genIntellijRuns\npause";
	outBat.close();
	
	tellraw("&y out file : runOutGradlew.bat |n");



}
int main(){
	start();
	string java8=getJava();
	//printf("----%s",java8.c_str());
	out_bat(java8);
	color(yellow);
	printf("run  runOutGradlew.bat \n");
	printf("run  outGradlew.bat \n");
	color(white);
	system("runOutGradlew.bat");
	system("pause");
}
