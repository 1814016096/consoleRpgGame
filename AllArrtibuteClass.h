#include "printClass.h"
class AbstractAttribute//���Ի��࣬���ڱ���������̳У�������ȣ���������Ʒ���ԺͶ���
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
	void HowDirect(int xOut,int yOut);//��������Ϣ��������������� 
};
class MonstorAttribute:public AbstractAttribute//�����࣬���ڳ������
{
	private:
		int typen;
	public:
	MonstorAttribute(int LevelOut);
	int Action();
	void MonstorType(int n,int LevelOut); 
};
class TrapArribute:public AbstractAttribute//�����࣬���ڳ������ 
{
	bool Tele;
	bool HarmPlus;
	bool LevUp;
	public:
	TrapArribute(int LevelOut);
	int Action();
};
class MainL :public AbstractAttribute//�����࣬���ڳ������ 
{
	public:
	MainL(int LevelOut);
	int Action();	
};
class Healtory :public AbstractAttribute//�����࣬���ڳ������ 
{
	public:
	Healtory(int LevelOut);
	int Action();	
};
AbstractAttribute * initPAttr(int Level);//��ʼ����Ÿ������������ 
AbstractAttribute * appenAttr(int x, int y,AbstractAttribute * pTail,AbstractAttribute * pNew);//������׷��һ������ 
AbstractAttribute * FindAttr(int x,int y,AbstractAttribute * pTail);//�ҵ����������ĳ�������� 
AbstractAttribute * ClearAttr(AbstractAttribute * pTail);//����������� 
