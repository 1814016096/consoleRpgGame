#include "printClass.h"
class AbstractAttribute//属性基类，用于被各个对象继承（怪物类等），包含物品属性和动作
{
	friend AbstractAttribute * appenAttr(int x, int y,AbstractAttribute * pTail,AbstractAttribute * pNew);
	friend AbstractAttribute * FindAttr(int x,int y,AbstractAttribute * pTail);
	friend AbstractAttribute * ClearAttr(AbstractAttribute * pTail);
	friend class CulArction;
	protected:
		int x;
		int y;
		int Harmful;
		int Heal;
		int Level;
		int Health;
		int Attack;
		std::string name;
		AbstractAttribute * pLink;
		public:
	virtual int Action() = 0;
	void HowDirect(int xOut,int yOut);//将坐标信息加载入各个物体中 
};
class MonstorAttribute:public AbstractAttribute//怪物类，基于抽象基类
{
	private:
		int typen;
	public:
	MonstorAttribute(int LevelOut);
	int Action();
	void MonstorType(int n,int LevelOut); 
};
class TrapArribute:public AbstractAttribute//陷阱类，基于抽象基类 
{
	bool Tele;
	bool HarmPlus;
	bool LevUp;
	public:
	TrapArribute(int LevelOut);
	int Action();
};
class MainL :public AbstractAttribute//主角类，基于抽象基类 
{
	public:
	MainL(int LevelOut);
	int Action();	
};
class Healtory :public AbstractAttribute//治疗类，基于抽象基类 
{
	public:
	Healtory(int LevelOut);
	int Action();	
};
AbstractAttribute * initPAttr(int Level);//初始化存放各个物体的链表 
AbstractAttribute * appenAttr(int x, int y,AbstractAttribute * pTail,AbstractAttribute * pNew);//往链表追加一个对象 
AbstractAttribute * FindAttr(int x,int y,AbstractAttribute * pTail);//找到符合坐标的某个物体类 
AbstractAttribute * ClearAttr(AbstractAttribute * pTail);//清空物体链表 
