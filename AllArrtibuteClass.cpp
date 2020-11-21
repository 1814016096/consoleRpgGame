#include "AllArrtibuteClass.h"


	void AbstractAttribute::HowDirect(int xOut,int yOut)
	{
		x = xOut;
		y = yOut;
	}

	MonstorAttribute::MonstorAttribute(int LevelOut)
	{
		typen = (rand()%4+1);
		MonstorType(typen, LevelOut);
	}
	int MonstorAttribute::Action()
	{
		return typen;
	}
	void MonstorAttribute::MonstorType(int n, int LevelOut)
	{
		switch(n)
		{
			case 1:
				typen = 1;
				Level = LevelOut;
				Heal = 0;
				name = "Ð¡¹Ö";
				Health = ((rand()%50 + 50)*Level);
				Harmful = ((rand()%5 + 5)*Level);
				Attack = Harmful;
				pLink = this;
			break;
			case 2:
				typen = 2;
				Level = LevelOut;
				Heal = 0;
				name = "±ùËª¾ÞÈË";
				Health = ((rand()%70 + 70)*Level);
				Harmful = ((rand()%5 + 5)*Level);
				Attack = Harmful;
				pLink = this;
			break;
			case 3:
				typen = 3;
				Level = LevelOut;
				Heal = 0;
				name = "°«ÈË";
				Health = ((rand()%30 + 30)*Level);
				Harmful = ((rand()%3 + 5)*Level);
				Attack = Harmful;
				pLink = this;
			break;
			case 4:
				typen = 4;
				Level = LevelOut;
				Heal = 0;
				name = "ÓÄÁé";
				Health = 1;
				Harmful = ((rand()%1 + 1)*Level);
				Attack = Harmful;
				pLink = this;
			break;
		}
	}
	
	TrapArribute::TrapArribute(int LevelOut)
	{
		Level = LevelOut;
		name = "ÏÝÚå";
		Health = 1;
		Harmful = 0;
		Heal = 0;
		//srand(((unsigned) time(0)*x+y));
		int r = rand()%11;
		Tele = false;
		HarmPlus = false;
		LevUp = false;
		switch(r)
		{
			case 9:
			case 0:
			case 5:
				Harmful = ((rand()%5 + 5)*Level);
				Attack = Harmful;
			break;
			case 2:
			case 6:
			case 1:
				Heal = ((rand()%4 + 4)*Level);
			break;
			case 7:
			case 3:
				Tele = true;
			break;
			case 8:
			case 4:
				HarmPlus = true;
			break;
			case 10:
				LevUp = true; 
			break;
		}
		pLink = this;
	}
	int TrapArribute::Action()
	{
		Health--;
		if(Tele)
		{
			return -1;
		}
		else if(HarmPlus)
		{
			return -2;
		}
		else
		{
			return -3;
		}
	}

	MainL::MainL(int LevelOut)
	{
		Level = LevelOut;
		Heal = 0;
		name = "Ö÷½Ç";
		Health = (rand()%100 + 100);
		Harmful = (rand()%15 + 10);
		Attack = Harmful;
		pLink = this;
	}
	int MainL::Action()
	{
		Attack = Harmful;
		srand(time(0));
		if(rand()%10 == 1)
		{
			Attack *= 1.5;
			return Attack;
		}
		else
			return Attack;
	}

	Healtory::Healtory(int LevelOut)
	{
		Level = LevelOut;
		Health = 1;
		name = "ÖÎÁÆ";
		srand(time(0));
		Harmful = 0;
		Attack = Harmful;
		Heal = ((rand()%15 + 20)*Level);
		pLink = this;
	}
	int Healtory::Action()
	{
		Health--;
		return 1001;
	}
AbstractAttribute * initPAttr(int Level)
{
	AbstractAttribute * p = new MonstorAttribute(Level);
	p->HowDirect(-1,-1);
	return p;
}
AbstractAttribute * appenAttr(int x, int y,AbstractAttribute * pTail,AbstractAttribute * pNew)
{
	pNew->HowDirect(x,y);
	AbstractAttribute * pF = pTail -> pLink;
	pTail -> pLink = pNew;
	pTail = pNew;
	pTail -> pLink = pF;
	return pTail;
}
AbstractAttribute * FindAttr(int x,int y,AbstractAttribute * pTail)
{
	AbstractAttribute * pT = pTail -> pLink -> pLink;
	while(pT != pTail -> pLink)
	{
		if(pT->x == x && pT->y == y)
		{
			return pT;
		}
		pT = pT -> pLink;
	}
	return 0;
}
AbstractAttribute * ClearAttr(AbstractAttribute * pTail)
{
	AbstractAttribute * pA = pTail -> pLink -> pLink;
	pTail = pTail -> pLink;
	while(pA != pTail)
	{
		AbstractAttribute * pB = pA;
		pA = pA -> pLink;
		delete pB;
	}
	pA -> pLink = pA;
}
