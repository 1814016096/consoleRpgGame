#include "printClass.h"
using namespace std;

	ReadSeed::ReadSeed()
	{
		cntSeeds = 0;
		stringstream StrC;
		int n = 1;
		string s = "Seeds\\seed_";
		string s1 = ".txt";
		ifstream GetIn;
		GetIn.open("Seeds\\seed_1.txt",ios::in);
		string sT;
		while(GetIn.is_open())
		{
			stringstream StrC;
			cntSeeds++;
			GetIn.close();
			n++;
			StrC<<n;
			StrC>>sT;
			string finalS = s + sT + s1;
			GetIn.open(finalS.c_str(), ios::in);
		}
		GetIn.close();
	}
	void ReadSeed::InputSeed(int n)
	{
		if(n <= cntSeeds)
		{
			stringstream rSi;
			rSi<<n;
			string s = "Seeds\\seed_";
			string s1 = ".txt";
			string finalS;
			rSi>>finalS;
			finalS = s + finalS + s1;
			ifstream Inter;
			Inter.open(finalS.c_str(),ios::in);
			for(int T1 = 0;T1 < 5;T1++)
				for(int T2 = 0;T2 < 10;T2++)
				{
					char chT = Inter.get();
					if(chT != '\n')
					{
						a[T1][T2] = chT - 48;
					}
					else
						T2--;
				}
			
			Inter.close();
		}
	}

	printTheBlock::printTheBlock():blockStatus({{0}}),blockStatusSet(0),electHowToPrint('#'),initx(5),inity(5)//初始化一些基本数据 
	{
	}
	
	void printTheBlock::Pos(int x, int y)//窗口初始化 
	{
    COORD pos;
    HANDLE hOutput;
    pos.X = x;
    pos.Y = y;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput, pos);
	}
	void printTheBlock::electHowToPr(status block)//选择打印的类型 
	{
		switch (block)
		{
			case GRAND:
			electHowToPrint = '.';
			blockStatusSet = 0;
			break;
			case WALL:
			electHowToPrint = '#';
			blockStatusSet = 1;
			break;
			case MONSTOR:
			electHowToPrint = '@';
			blockStatusSet = 2;
			break;
			case TRAP:
			electHowToPrint = 'T';
			blockStatusSet = 3;
			break;
			case EXIT:
			electHowToPrint = '&';
			blockStatusSet = 4;
			break;
			case HEALTH:
			electHowToPrint = 'H';
			blockStatusSet = 5;
		}
	}
	void printTheBlock::printSingle(int x, int y)//打印单个方块 
	{
		Pos(x,y);
		cout<<electHowToPrint;
		blockStatus[y][x] = blockStatusSet;
	}
	void printTheBlock::printBlockBig(int x, int y,int n)//打印一个正方形块 
	{
		printClosed(n-1, n-1, x, y);
		int templeY = y;
		int templeX = x;
		for(y;templeY <= y + n - 1; templeY++)
		{
			printWall(n,templeX,templeY);
		}
	}
	void printTheBlock::printWall(int n,int x, int y)//打印墙 
	{
		Pos(x,y);
		for(int t = 0;t <= n - 1;t++)
		{
			Pos(x+t,y);
			cout<<electHowToPrint;
			blockStatus[y][x+t] = blockStatusSet;
		}
	}
	void printTheBlock::printWallH(int n,int x, int y)//打印竖墙 
	{
		Pos(x,y);
		for(int t = 0;t <= n - 1;t++)
		{
			Pos(x,y+t);
			cout<<electHowToPrint;
			blockStatus[y+t][x] = blockStatusSet;
		}
	}
	void printTheBlock::printClosed(int a, int b,int x, int y)//打印围墙 
	{
		printWall(a,x,y);
		printWallH(b,x,y);
		x+=a - 1;
		printWallH(b,x,y);
		x-=a - 1;
		y+=b - 1;
		printWall(a,x,y);
	}
	void printTheBlock::printOrange()//打印空白地图 
	{
		electHowToPr(WALL);
		printClosed(MAXLENGTH, MAXHEIGHT,initx,inity);
		electHowToPr(GRAND);
		int x = initx;
		int y = inity;
		x++;
		for(y = y+1;y <= MAXHEIGHT + inity - 2;y++)
		{
			printWall(MAXLENGTH - 2,x,y);
		}
		x = initx;
		y = initx;
		cout<<endl;
	}
	void printTheBlock::printArry()//打印数组原型 
	{
		for(int templef = 0;templef <= 39; templef++)
		{
			for(int temples = 0; temples<=119;temples++)
			{
				cout<<blockStatus[templef][temples];
			}
			cout<<endl;
		}
	}
	char printTheBlock::judgeHP(int t)
	{
		if(t == 0)
		{
			return '.';
		}
		else if ( t == 1)
		{
			return '#';
		}
		else if (t == 2)
		{
			return '@';
		}
		else if(t == 3)
		{
			return 'T';
		}
		else if(t == 4)
		{
			return '&';
		}
		else if(t == 5)
		{
			return 'H';
		}
	}
	void printTheBlock::easyWriter()
	{
		if(!blockStatus[5][5])
			printOrange();
		Pos(initx + 5,inity +5);
		int x = initx + 5;
		int y = inity + 5;
		char whatDrection = '0';
		electHowToPr(WALL);
		while(true)//简单画图程序 
		{
			whatDrection = getch();
			switch(whatDrection)
			{
			case 'w':
					y--;
					if(blockStatus[y][x] == 0)
					{
						cout<<judgeHP(blockStatus[y+1][x]);
						Pos(x,y);
						cout<<electHowToPrint;
						Pos(x,y);
					}
					else
					{
						y++;
					}
					break;
				case 's':
					y++;
					if(blockStatus[y][x] == 0)
					{
						cout<<judgeHP(blockStatus[y-1][x]);
						Pos(x,y);
						cout<<electHowToPrint;
						Pos(x,y);
					}
					else
					{
						y--;
					}
					break;
				case 'd':
					x++;
					if(blockStatus[y][x] == 0)
					{
						cout<<judgeHP(blockStatus[y][x-1]);
						Pos(x,y);
						cout<<electHowToPrint;
						Pos(x,y);
					}
					else
					{
						x--;
					}
					break;
				case 'a':
					x--;
					if(blockStatus[y][x] == 0)
					{
						cout<<judgeHP(blockStatus[y][x+1]);
						Pos(x,y);
						cout<<electHowToPrint;
						Pos(x,y);
					}
					else
					{
						x++;
					}
					break;
				case 'q':
					Pos(0,0);
					system("cls");
					return;
					break;
				case 'b':
					electHowToPr(WALL);
					break;
				case 't':
					electHowToPr(TRAP);
					break;
				case 'm':
					electHowToPr(MONSTOR);
					break;
				case 'e':
					electHowToPr(EXIT);
					break;
				case ' ':
					printSingle(x,y);
					break;
				case 'c':
					printBlockBig(x,y,4);
					break;
			}
		} 
	}
	void printTheBlock::printEnireMap()
	{
		system("cls");
		for(int t = inity;t < 25;t++)
		{
			for(int temple = initx; temple <105;temple++)
			{
				electHowToPrint = judgeHP(blockStatus[t][temple]);
				Pos(temple,t);
				cout<<electHowToPrint;
			}
		}
		electHowToPr(GRAND);
	}
	void printTheBlock::bornRandMap()
	{
		system("cls");
		printOrange();
		srand((unsigned)time(0));
		for(int templeH = 5;templeH < 32; templeH+=4)
		{
			for(int templeL = 5;templeL < 114; templeL+=10)
			{
				int cnt = Seeds.cntSeeds;
				int n1 = (rand()%cnt+1);
				Seeds.InputSeed(n1);
				for(int Ty = 0;Ty < 5;Ty++)
					for(int Tx = 0;Tx < 10;Tx++)
					{
						blockStatus[templeH + Ty][templeL + Tx] = Seeds.a[Ty][Tx]; 
					}
			} 
		}
		electHowToPr(WALL);
		printClosed(MAXLENGTH, MAXHEIGHT,initx,inity);
		electHowToPr(EXIT);
		printSingle(rand()%99 + 6,6);
		printEnireMap();
		writeMap();
		return;
	}
	void printTheBlock::writeMap()
	{
		ofstream outer;
		outer.open("map.txt", ios::trunc);
		for(int i = 5;i < 5 + MAXHEIGHT;i++)
		{
			for(int j = 5;j < MAXLENGTH + 5;j++)
			{
				outer<<blockStatus[i][j]; 
			}
			outer<<endl;
		}
		outer.close();
		return;
	}
	void printTheBlock::readMap()
	{
		ifstream inner;
		inner.open("map.txt",ios::in);
		char templeCh = 0;
			for(int i = 5;i <= 5 + MAXHEIGHT;i++)
			{
				for(int j = 5;j <= MAXLENGTH + 5;j++)
				{
					templeCh = inner.get();
					blockStatus[i][j] = int(templeCh) - 48;
				}
			}
			inner.close();
	}
