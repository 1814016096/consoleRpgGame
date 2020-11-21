#include "AllArrtibuteClass.h"
using namespace std;
void printHSH(string name,int H, int L, int He, int x, int y);
void printBuff(string name,string buffname,int x,int y);
void setColor(unsigned short ForeColor=7,unsigned short BackGroundColor=0)
{
HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);//获取当前窗口句柄
SetConsoleTextAttribute(handle,ForeColor+BackGroundColor*0x10);//设置颜色
}
class CulArction
{
	friend int main();
	private:
		printTheBlock DBMap;
		int nowlevel;
		AbstractAttribute * initPOjt;
		AbstractAttribute * PMainL;
		AbstractAttribute * POjt;
		int Initx;
		int Inity;
	public:
		void startGame()
		{
			srand((unsigned) time(0));
			nowlevel = 1;
			DBMap.bornRandMap();
			initPOjt = initPAttr(nowlevel);
			initPOjt -> HowDirect(-1,-1);
			for(int Ty = 5;Ty < 26;Ty++)
				for(int Tx = 5;Tx< 120;Tx++)
				{
					if(DBMap.blockStatus[Ty][Tx] != 0 && DBMap.blockStatus[Ty][Tx] != 1)
					{
						if(DBMap.blockStatus[Ty][Tx] == 2)
						{
							initPOjt = appenAttr(Tx, Ty,initPOjt,new MonstorAttribute(nowlevel));
						}
						else if(DBMap.blockStatus[Ty][Tx] == 3)
						{
							initPOjt = appenAttr(Tx, Ty,initPOjt,new TrapArribute(nowlevel));	
						}
						else if(DBMap.blockStatus[Ty][Tx] == 5)
						{
							initPOjt = appenAttr(Tx, Ty,initPOjt,new Healtory(nowlevel));
						}
					}
				}
				Initx = 50;
				Inity = 23;
			PMainL = new MainL(nowlevel);
			PMainL -> HowDirect(Initx,Inity);
			DBMap.Pos(Initx,Inity);
			printHSH("主角",PMainL -> Harmful, PMainL -> Level, PMainL -> Health,5,25);
			printBuff(PMainL -> name,"无",0,27);
		}
	void Act()
	{
		while(PMainL -> Health > 0)
		{
				char ch;
				ch = getch();
				switch(ch)
				{
					case 'w':
						if(!(DBMap.blockStatus[Inity-1][Initx]))
						{
						Inity--;
						DBMap.Pos(Initx,Inity);
						cout<<"!";
						DBMap.Pos(Initx,Inity + 1);
						cout<<DBMap.judgeHP(DBMap.blockStatus[Inity+1][Initx]);
						break;
						}
						else
							Diract(Initx,Inity-1);
						break;
					case 's':
						if(!(DBMap.blockStatus[Inity+1][Initx])) 
						{
						Inity++;
						DBMap.Pos(Initx,Inity);
						cout<<"!";
						DBMap.Pos(Initx,Inity - 1);
						cout<<DBMap.judgeHP(DBMap.blockStatus[Inity-1][Initx]);
						break;
						}
						else
							Diract(Initx,Inity+1);
						break;
					case 'a':
						if(!(DBMap.blockStatus[Inity][Initx - 1]))
						{
							Initx--;
							DBMap.Pos(Initx,Inity);
							cout<<"!";
							DBMap.Pos(Initx + 1,Inity);
							cout<<DBMap.judgeHP(DBMap.blockStatus[Inity][Initx + 1]);
							break;	
						}
						else
							Diract(Initx - 1,Inity);
						break;
					case 'd':
						if(!(DBMap.blockStatus[Inity][Initx + 1]))
						{
						Initx++;
						DBMap.Pos(Initx,Inity);
						cout<<"!";
						DBMap.Pos(Initx - 1,Inity);
						cout<<DBMap.judgeHP(DBMap.blockStatus[Inity][Initx - 1]);
						break;
						}
						else
							Diract(Initx + 1,Inity);
						break;
				}
				printBuff(PMainL -> name,"无",0,28);
		}
		system("cls");
		DBMap.Pos(50,10);
		cout<<"你死了,游戏结束"<<endl;
		getch();
	}
	void Diract(int x,int y)
	{
		int tempHaM = 0;
		int tempHeM = 0;
		int statueCnt = 0;
		int statue = 0;
		int tempHaO = 0;
		int tempHeO = 0;
		if(DBMap.blockStatus[y][x] == 1){}
		else if(DBMap.blockStatus[y][x] == 4)
		{
			initPOjt = ClearAttr(initPOjt);
			setColor(7,0);
			DBMap.bornRandMap();
			nowlevel++;
			for(int Ty = 5;Ty < 26;Ty++)
				for(int Tx = 5;Tx< 120;Tx++)
				{
					if(DBMap.blockStatus[Ty][Tx] != 0 && DBMap.blockStatus[Ty][Tx] != 1)
					{
						if(DBMap.blockStatus[Ty][Tx] == 2)
						{
							initPOjt = appenAttr(Tx, Ty,initPOjt,new MonstorAttribute(nowlevel));
						}
						else if(DBMap.blockStatus[Ty][Tx] == 3)
						{
							initPOjt = appenAttr(Tx, Ty,initPOjt,new TrapArribute(nowlevel));	
						}
						else if(DBMap.blockStatus[Ty][Tx] == 5)
						{
							initPOjt = appenAttr(Tx, Ty,initPOjt,new Healtory(nowlevel));
						}
					}
				}
			Initx = 50;
			Inity = 23;
			DBMap.Pos(Initx,Inity);
			PMainL -> Health += (rand()%50 + 10*nowlevel)*nowlevel;
			PMainL -> Harmful += rand()%(nowlevel*nowlevel) + nowlevel;
			printHSH(PMainL -> name,PMainL -> Harmful, PMainL -> Level, PMainL -> Health,5,25);
		} 
		else
		{
			POjt = FindAttr(x,y,initPOjt);
			while(PMainL->Health > 0 && POjt->Health > 0)
			{
				judgeHowAct(PMainL -> Action(),statueCnt, PMainL, tempHaM);
				judgeHowAct(POjt -> Action(),statueCnt,POjt,tempHaO);
				POjt -> Health = POjt -> Health - PMainL -> Attack;
				printHSH(POjt -> name,POjt -> Attack, POjt -> Level, POjt -> Health,45,25);
				PMainL -> Health = PMainL -> Health - POjt -> Attack;
				PMainL -> Health = PMainL -> Health + POjt -> Heal;
				printHSH(PMainL -> name,PMainL -> Attack, PMainL -> Level, PMainL -> Health,5,25);
				Sleep(1000);
			}
			statueCnt = 0;
		DBMap.blockStatus[POjt -> y][POjt -> x] = 0;
		DBMap.Pos(x,y);
		cout<<DBMap.judgeHP(DBMap.blockStatus[Inity][Initx]);
		}
	}
	void judgeHowAct(int Status,int &statueCnt,AbstractAttribute * p,int tempHaM)
	{
		if(statueCnt == 0)
			p -> Attack = p -> Harmful;
		switch (Status)
		{
			case 1:
				if(rand()%10 == 1)
				{
					p -> Attack = p -> Harmful*1.5;
					printBuff(p -> name,"暴击",50,28);	
				}
			break;
			case 2:
				if(rand()%10 == 1)
				{
					p -> Attack = p -> Harmful*1.5;
					printBuff(p -> name,"暴击",50,28);
				}
				else if(rand()%10 == 2)
				{
					PMainL -> Attack = PMainL -> Harmful/1.2;
					printBuff(PMainL -> name,"减伤",0,28);
					statueCnt = 1;
				}
			break;
			
			case 3:
				if(rand()%10 == 1)
				{
					p -> Attack = p -> Harmful*1.5;
					printBuff(p -> name,"暴击",050,28);
				}
				else if(rand()%10 == 2)
				{
					p -> Attack = p -> Harmful*2;
					statueCnt = 1;
				}
				break;
			case 4:
				if(rand()%10 != 5)
				{
					PMainL -> Attack = 0;
					printBuff(PMainL -> name,"虚无",0,28);
					statueCnt = 1;
				}
				else
				{
					printBuff(PMainL -> name,"无",0,28);
				}
				break;
			case -1:
				Initx = rand()%80 + 5;
				Inity = rand()%15 + 5;
				printBuff(PMainL -> name,"随机传送",0,28);
				break;
			case -2:
				PMainL -> Harmful += (rand()%5 + 2)*nowlevel;
				printBuff(PMainL -> name,"永久增伤",0,28);
			case -3:
				PMainL -> Harmful -= (rand()%2)*nowlevel;
				printBuff(PMainL -> name,"永久减伤",0,28);
			case 1001:
				printBuff(PMainL -> name,"治疗",0,28);
				break;
		}
		if(statueCnt)
		{
			if(statueCnt <= 3)
			{
				statueCnt++;
			}
			else
			{
				statueCnt=0;
				printBuff(PMainL -> name,"无",0,28);
			}
		}
	}
};
void pos(int x, int y)//窗口初始化 
	{
    COORD pos;
    HANDLE hOutput;
    pos.X = x;
    pos.Y = y;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput, pos);
	}
void printHSH(string name,int H, int L, int He,int x,int y)
{
	He = He < 0? 0 : He;
	pos(x,y);
	cout<<"                            "<<endl;
	pos(x,y+1);
	cout<<"             "<<endl;
	pos(x,y+2);
	cout<<"             "<<endl;
	pos(x,y);
	setColor(12,0);
	cout<<name<<"的 ";
	cout<<"伤害:"<<H<<endl;
	pos(x,y+1);
	cout<<"等级:"<<L<<endl;
	pos(x,y+2);
	cout<<"血量:"<<He<<endl;
}
void printBuff(string name,string buffname,int x,int y)
{
	pos(x,y);
	cout<<"                           ";
	pos(x,y);
	setColor(12,0);
	cout<<name<<"的 ";
	cout<<"buff:"<<buffname<<endl;
}
int main()
{
	CulArction GameMain;
	pos(25,7);
	cout<<"###############################################"<<endl;
	for(int t = 8;t <= 14;t++)
	{
		pos(25,t);
		cout<<"#                                             #"<<endl;
	}
	pos(25,15);
	cout<<"###############################################"<<endl;
	pos(43,11);
	cout<<"地下城游戏"<<endl;
	pos(20,25);
	cout<<"[s] 开始游戏"<<"    "<<"[m] 随机生成并写入地图(map.txt)"<<endl;
	char ch = 0;
	while(true)
	{
		ch = getch();
		switch(ch)
		{
			case 's':
				GameMain.startGame();
				GameMain.Act();
			break;
			case 'm':
				GameMain.DBMap.bornRandMap();
				break;	
		}
		break;
	}
	
	return 0;
}
