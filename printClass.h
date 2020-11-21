#ifndef PRINTCLASS_H
#define PRINTCLASS_H
#include "iostream" 
#include "windows.h"
#include "conio.h"
#pragma comment(lib,"user32.lib")
#define MAXLENGTH 100
#define MAXHEIGHT 20
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
enum status
{
	GRAND, WALL, MONSTOR, TRAP,EXIT,HEALTH
};
class ReadSeed//从地图中读取种子的类 
{
	friend class printTheBlock; 
	private:
	int a[5][10];
	int cntSeeds;
	ReadSeed();//构造函数，初始化时检测Seeds\文件夹中有几个种子 
	void InputSeed(int n);//读取地n个种子的具体内容 
};
class printTheBlock
{
	friend class CulArction;
	private:
	const int initx;
	const int inity;
	char electHowToPrint;
	int blockStatus[40][120];
	int blockStatusSet;
	ReadSeed Seeds;
	public:
	printTheBlock();//构造函数初始化 
	public:
	char judgeHP(int t);//解码，数字转换为符号 
	void printEnireMap();//从数组读取地图 
	void easyWriter();//简易地图制作工具 
	void Pos(int x, int y);//窗口初始化
	void electHowToPr(status block);//选择打印的类型
	void printSingle(int x, int y);//打印单个方块 
	void printBlockBig(int x, int y,int n);//打印一个正方形块
	void printWall(int n,int x, int y);//打印墙 
	void printWallH(int n,int x, int y);//打印竖墙
	void printClosed(int a, int b,int x, int y);//打印围墙
	void printOrange();//打印空白地图
	void printArry();//打印数组原型
	void bornRandMap();//随机生成地图（基于种子） 
	void writeMap();//把地图写入map.txt文件中 
	void readMap();//从map.txt中读文件 
};
#endif
