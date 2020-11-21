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
class ReadSeed//�ӵ�ͼ�ж�ȡ���ӵ��� 
{
	friend class printTheBlock; 
	private:
	int a[5][10];
	int cntSeeds;
	ReadSeed();//���캯������ʼ��ʱ���Seeds\�ļ������м������� 
	void InputSeed(int n);//��ȡ��n�����ӵľ������� 
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
	printTheBlock();//���캯����ʼ�� 
	public:
	char judgeHP(int t);//���룬����ת��Ϊ���� 
	void printEnireMap();//�������ȡ��ͼ 
	void easyWriter();//���׵�ͼ�������� 
	void Pos(int x, int y);//���ڳ�ʼ��
	void electHowToPr(status block);//ѡ���ӡ������
	void printSingle(int x, int y);//��ӡ�������� 
	void printBlockBig(int x, int y,int n);//��ӡһ�������ο�
	void printWall(int n,int x, int y);//��ӡǽ 
	void printWallH(int n,int x, int y);//��ӡ��ǽ
	void printClosed(int a, int b,int x, int y);//��ӡΧǽ
	void printOrange();//��ӡ�հ׵�ͼ
	void printArry();//��ӡ����ԭ��
	void bornRandMap();//������ɵ�ͼ���������ӣ� 
	void writeMap();//�ѵ�ͼд��map.txt�ļ��� 
	void readMap();//��map.txt�ж��ļ� 
};
#endif
