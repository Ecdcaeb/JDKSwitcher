#include <io.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>

std::string* getJava(){
	return new std::string(getenv("JAVA_HOME"));
}
std::string* quoteString(std::string* str){
	str->insert(0,1,'\"');
	str->insert(str->length(),1,'\"');
	return str;
}
void setJava(char* var){
	std::string* cmd=new std::string("");//empty
	std::string* junk1;
	cmd->append("setx ");
	cmd->append("\"JAVA_HOME\" ");
	junk1 = quoteString(new std::string(var));
	cmd->append(junk1->c_str());
	//cmd->append(" /U ");
	//cmd->append(username);
	const char * cmdConstant=cmd->c_str();
	system(cmdConstant);
	delete cmd;
	delete junk1; 
}
void getAllFiles(std::string path, std::vector<std::string>& files) 
{
	// 文件句柄
	long hFile = 0;
	// 文件信息
	struct _finddata_t fileinfo;  

	std::string p;

	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) {
		do {
			// 保存文件的全路径
			files.push_back(p.assign(path).append("\\").append(fileinfo.name));

		   } while (_findnext(hFile, &fileinfo) == 0);  //寻找下一个，成功返回0，否则-1

		_findclose(hFile);
	}
}
void readFromProgram(std::vector<std::string>& jdks){
	std::vector<std::string> s;
	getAllFiles("C:\\Program Files\\Java",s);
	std::vector<std::string>::iterator i;
	for(i=s.begin();i!=s.end();++i){
		if((*i).find("jdk1.8",0)!=std::string::npos || (*i).find("jdk-1.8",0)!=std::string::npos || ((*i).find("j")!=std::string::npos )){
			jdks.push_back(*i);
		}
	}
}
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
	std::cout<<"按任意键继续"<<std::endl;
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
std::pair <int,int> getxy(){
    HANDLE hStdout;
    CONSOLE_SCREEN_BUFFER_INFO pBuffer; 
    hStdout=GetStdHandle(STD_OUTPUT_HANDLE); 
    GetConsoleScreenBufferInfo(hStdout,&pBuffer); 
    return std::make_pair(pBuffer.dwCursorPosition.X,pBuffer.dwCursorPosition.Y);
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
void tellraw(std::string s,LL num1=0,LL num2=0,LL num3=0){
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
void tellrawfast(std::string s,LL num1=0,LL num2=0,LL num3=0){
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
char readkey(std::string s,std::string range=""){
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
std::string inputbox(std::string s){
    tellraw(s+"|n");
    cursorshow();
    std::string t;
    color(white);
    std::cin>>t;
    cursorhide();
    return t;
}
int chosenbox(std::string s){
    int len=s.size();
    int i=0;
    std::string t="";
    while (s[i]!='@' && i<len) t=t+s[i],i++;
    tellraw(t);
    putchar('\n');
    std::pair <int,int> tmp=getxy(); 
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
    std::pair <int,int> tmp2=getxy();
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
std::string getJavaChosen(std::vector<std::string>& jdks){	
	std::vector<std::string>::iterator o;
	std::string cho;
	cho=cho+"@";
	//vector<string> choice;
	std::string Java8List[100];
	std::string Java8ListPath[100];
	int ioindex=1;
	for(o=jdks.begin();o!=jdks.end();++o){
		std::string p_1=(*o);
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


	std::cout<<std::endl;
	std::cout<<std::endl;
	std::cout<<std::endl;
	
	return Java8ListPath[index];
}
void readFromConfig(std::vector<std::string>& jdks){
	DWORD attribs=GetFileAttributes("jdks.cfg");
	if(attribs == INVALID_FILE_ATTRIBUTES){
		//create file
		std::ofstream oc;
		oc.open("jdks.cfg",std::ios::app);
		if(!oc){
			tellraw("&rcreate config fail");
		}
		oc.close();
		return;
	}
	
	if(!(attribs&FILE_ATTRIBUTE_DIRECTORY)){
		std::ifstream ic;
		ic.open("jdks.cfg",std::ios::in);
		if(ic.bad() || !ic.is_open()){
			tellraw("&rread config fail");
		}else{
			std::string line; 
			while(std::getline(ic,line)){
				if(line.empty())continue;
				jdks.push_back(line);
			}
		}
		ic.close();
		return;
	}
}
void printMainScreen(){
	tellraw("&aJDK Sitcher\n");
	tellraw("&a    Copyright (c) 2024 Hileb\n");
	tellraw("&a  this is a Software enable you change the \"JAVA_HOME\" fastly.\n");
	printf("Current JAVA_HOME : %s \n",quoteString(getJava())->c_str());
	tellraw("\n\n&yChoose your jdk(in  C:\\Program Files\\Java\\    or  jdks.cfg each line) \n");
}

int main(){
	//pre Launching
	SetConsoleTitle("JDKSwitcher");
	printMainScreen();
	//launch
	std::vector<std::string> jdks;
	readFromConfig(jdks);
	readFromProgram(jdks);
	std::string cur=getJavaChosen(jdks);
	setJava((char*)cur.c_str());
}

