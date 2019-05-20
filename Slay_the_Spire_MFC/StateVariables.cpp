#include "StdAfx.h"
#include "StateVariables.h"
#include <time.h>
#define random(x) (rand()%x)
#define damage(x) target->EnemyBlock -= int((x + Strength) * WeakCoefficient * target->Vulnerable)

Cards::Cards(void)
{
}


Cards::~Cards(void)
{
}

int Cards::EnergyConsume(int x, StateVariables* player)
{
	if (player->Energy < x)
		return 0;
	else
	{
		player->Energy -= x;
		return 1;
	}
}

StateVariables::StateVariables(void)
{
	Block = 0;
	Dexterity = 0;
	Energy = 3;
	EnergyMax = 3;
	Gold = 99;
	HP = 70;
	HPMax = 70;
	Deck[0] = GameDeck[1];
	Deck[1] = GameDeck[1];
	Deck[2] = GameDeck[1];
	Deck[3] = GameDeck[1];
	Deck[4] = GameDeck[1];
	Deck[5] = GameDeck[3];
	Deck[6] = GameDeck[3];
	Deck[7] = GameDeck[3];
	Deck[8] = GameDeck[3];
	Deck[9] = GameDeck[2];//生成只有十张初始牌的牌库
	int i;
	for(i = 10; i <= 99; i++)
	{
		Deck[i] = 0;//剩下的空位用0表示
	}
	DrawNum = 5;//每回合抽5张牌
	CanDraw = 1;
	FlameBarrier = 0;
	Berserk = 0;
}


StateVariables::~StateVariables(void)
{
}


void StateVariables::draw(int drawnum)
{
	for(int i = 0; i < drawnum; i++)
	{
		Hand[HandPoint + i + 1] = DrawPile[DrawPoint - i];
		DrawPile[DrawPoint - i] = 0;
	}
	HandPoint = HandPoint + drawnum;
	DrawPoint = DrawPoint - drawnum;
};

void StateVariables::addToDrawPile(int cardnum)
{
	srand((unsigned int)(time(NULL)));
	int i = random(DrawPoint);
	int temp = i;
	for (; i < DrawPoint; i++)
	{
		DrawPile[i + 1] = DrawPile[i];
	}
	DrawPile[temp] = cardnum;
}

void StateVariables::usecard(int cardnum, Enemy* target = NULL, int n = 0)
{
	switch (cardnum)
	{
	case 3:
	{
		if (Deck[cardnum]->EnergyConsume(1, this))
			target->EnemyBlock -= int((6 + Strength) * WeakCoefficient * target->Vulnerable);
	}break;
	case 1003:
	{
		if (Deck[cardnum]->EnergyConsume(1, this))
			target->EnemyBlock -= int((9 + Strength) * WeakCoefficient * target->Vulnerable);
	}break;
	case 1:
	{
		if (Deck[cardnum]->EnergyConsume(2, this))
		{
			target->EnemyBlock -= int((8 + Strength) * WeakCoefficient * target->Vulnerable);
			target->State_Vulnerable += 2;
		}
	}break;
	/*
	case 1001:
	{
		if(Deck[cardnum]->EnergyConsume(2, this))
		target->EnemyBlock -= int((10 + Strength) * WeakCoefficient * target->Vulnerable);
		target->State_Vulnerable += 3;
	}break;
	case 2:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		Block += (5 + Dexterity);
	}break;
	case 1002:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		Block += (8 + Dexterity);
	}break;
	case 6:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		target->EnemyBlock -= int((Block + Strength) * WeakCoefficient * target->Vulnerable);
	}break;
	case 1006:
	{
		target->EnemyBlock -= int((Block + Strength) * WeakCoefficient * target->Vulnerable);
	}break;
	case 16:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		target->EnemyBlock -= int((9 + Strength) * WeakCoefficient * target->Vulnerable);
		draw(1);
	}break;
	case 1016:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		target->EnemyBlock -= int((10 + Strength) * WeakCoefficient * target->Vulnerable);
		draw(2);
	}break;
	case 21:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		target->EnemyBlock -= int((5 + Strength) * WeakCoefficient * target->Vulnerable);
		target->EnemyBlock -= int((5 + Strength) * WeakCoefficient * target->Vulnerable);
	}break;
	case 1021:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		target->EnemyBlock -= int((7 + Strength) * WeakCoefficient * target->Vulnerable);
		target->EnemyBlock -= int((7 + Strength) * WeakCoefficient * target->Vulnerable);
	}break;
	case 4:
	{
		target->EnemyBlock -= int((5 + Strength) * WeakCoefficient * target->Vulnerable);
		DiscardPile[DiscardPoint] = 4;
		DiscardPoint++;
	}break;
	case 1004:
	{
		target->EnemyBlock -= int((7 + Strength) * WeakCoefficient * target->Vulnerable);
		DiscardPile[DiscardPoint] = 1004;
		DiscardPoint++;
	}break;
	case 23:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		damage(12);
		addToDrawPile(131);
	}break;
	case 1023:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		damage(17);
		addToDrawPile(131);
	}break;
	case 17:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		Block += (8 + Dexterity);
		draw(1);
	}break;
	case 1017:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		Block += (11 + Dexterity);
		draw(1);
	}break;
	case 13:
	{
		if(Deck[cardnum]->EnergyConsume(2, this))
		target->EnemyBlock -= int((14 + 3 * Strength) * WeakCoefficient * target->Vulnerable);
	}break;
	case 1013:
	{
		if(Deck[cardnum]->EnergyConsume(2, this))
		target->EnemyBlock -= int((14 + 5 * Strength) * WeakCoefficient * target->Vulnerable);
	}break;
	case 9:
	{
		if(Deck[cardnum]->EnergyConsume(2, this))
		target->EnemyBlock -= int((12 + Strength) * WeakCoefficient * target->Vulnerable);
		target->State_Weak += 2;
	}break;
	case 1009:
	{
		if(Deck[cardnum]->EnergyConsume(2, this))
		target->EnemyBlock -= int((14 + Strength) * WeakCoefficient * target->Vulnerable);
		target->State_Weak += 3;
	}break;
	case 14:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		damage(5);
		Block += (5 + Dexterity);
	}break;
	case 1014:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		damage(7);
		Block += (7 + Dexterity);
	}break;
	case 58:
	{
		if(Deck[cardnum]->EnergyConsume(2, this))
		damage(13);
		target->State_Vulnerable += 1;
		target->State_Weak += 1;
	}break;
	case 1058:
	{
		if(Deck[cardnum]->EnergyConsume(2, this))
		damage(13);
		target->State_Vulnerable += 2;
		target->State_Weak += 2;
	}break;
	case 1005:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		Block += (5 + Dexterity);
		int i;
		for (i = 1; i < HandPoint; i++)
		{
			if (Hand[i] < 1000)
				Hand[i] += 1000;
		}
	}break;
	case 10:
	{
		Strength += 2;
		StrengthUpTemp += 2;
	}break;
	case 1010:
	{
		Strength += 4;
		StrengthUpTemp += 4;
	}break;
	case 11:
	{
		usecard(DrawPile[DrawPoint], target, n);
		DrawPile[DrawPoint] = 0;
		DrawPoint -= 1;
	}break;
	case 1011:
	{
		usecard(DrawPile[DrawPoint], target, n);
		DrawPile[DrawPoint] = 0;
		DrawPoint -= 1;
	}break;
	case 18:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		srand((unsigned int)(time(NULL)));
		int t = random(n);
		int i;
		for (i = 0; i < 3; i++)
			(target + t)->EnemyBlock -= int((3 + Strength) * WeakCoefficient * target->Vulnerable);
	}break;
	case 1018:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		srand((unsigned int)(time(NULL)));
		int t = random(n);
		int i;
		for (i = 0; i < 4; i++)
			(target + t)->EnemyBlock -= int((3 + Strength) * WeakCoefficient * target->Vulnerable);
	}break;
	case 19:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		int i;
		for (i = 0; i < n; i++)
		{
			(target + i)->EnemyBlock -= int((4 + Strength) * WeakCoefficient * target->Vulnerable);
			(target + i)->State_Vulnerable += 1;
		}
	}break;
	case 1019:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		int i;
		for (i = 0; i < n; i++)
		{
			(target + i)->EnemyBlock -= int((7 + Strength) * WeakCoefficient * target->Vulnerable);
			(target + i)->State_Vulnerable += 1;
		}
	}break;
	case 20:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		Block += 7;
		srand((unsigned int)(time(NULL)));
		int i = random(HandPoint);
		Hand[i] = Hand[i + 1];
		for (i = i + 1; i < HandPoint - 1; i++)
			Hand[i] = Hand[i + 1];
		HandPoint -= 1;
	}break;
	case 24:
	{
		draw(3);
		CanDraw = 0;
	}
	case 1024:
	{
		draw(4);
		CanDraw = 0;
	}
	case 26:
	{
		HP -= 3;
		Energy += 1;
	}break;
	case 1026:
	{
		HP -= 3;
		Energy += 2;
	}break;
	case 28:
	{
		if(Deck[cardnum]->EnergyConsume(2, this))
		damage(20);
	}break;
	case 1028:
	{
		if(Deck[cardnum]->EnergyConsume(2, this))
		damage(28);
	}break;
	case 32:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		damage(5);
		if (target->State_Vulnerable > 0)
		{
			Energy += 1;
			draw(1);
		}
	}break;
	case 1032:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		damage(8);
		if (target->State_Vulnerable > 0)
		{
			Energy += 1;
			draw(1);
		}
	}break;
	case 34:
	{
		if(Deck[cardnum]->EnergyConsume(2, this))
		Block *= 2;
	}break;
	case 1034:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		Block *= 2;
	}break;
	case 38:
	{
		if(Deck[cardnum]->EnergyConsume(2, this))
		Block += (12 + Dexterity);
		FlameBarrier = 4;
	}break;
	case 1038:
	{
		if(Deck[cardnum]->EnergyConsume(2, this))
		Block += (16 + Dexterity);
		FlameBarrier = 6;
	}break;
	case 40:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		HP -= 3;
		damage(14);
	}break;
	case 1040:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		HP -= 2;
		damage(18);
	}break;
	case 42:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		Strength += 2;
	}break;
	case 1042:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		Strength += 3;
	}break;
	case 61:
	{
		Vulnerable += 3;
		Berserk += 1;
	}break;
	case 1061:
	{
		Vulnerable += 2;
		Berserk += 1;
	}break;
	case 62:
	{
		if(Deck[cardnum]->EnergyConsume(3, this))
		damage(32);
	}break;
	case 1062:
	{
		if(Deck[cardnum]->EnergyConsume(3, this))
		damage(42);
	}break;
	case 65:
	{
		if(Deck[cardnum]->EnergyConsume(3, this))
		StrengthUp += 2;
	}break;
	case 1065:
	{
		if(Deck[cardnum]->EnergyConsume(3, this))
		StrengthUp += 3;
	}break;
	case 70:
	{
		if(Deck[cardnum]->EnergyConsume(2, this))
		int i;
		for (i = 0; i < n; i++)
		{
			(target + i)->EnemyBlock -= 21;
		}
		DiscardPile[DiscardPoint] = 129;
		DiscardPoint++;
	}break;
	case 1070:
	{
		if(Deck[cardnum]->EnergyConsume(2, this))
		int i;
		for (i = 0; i < n; i++)
		{
			(target + i)->EnemyBlock -= 28;
		}
		DiscardPile[DiscardPoint] = 129;
		DiscardPoint++;
	}break;
	case 72:
	{
		if(Deck[cardnum]->EnergyConsume(2, this))
		Juggernaut = 5;
	}break;
	case 1072:
	{
		if(Deck[cardnum]->EnergyConsume(2, this))
		Juggernaut = 7;
	}break;
	case 77:
	{
		damage(7);
		HP += 2;
	}break;
	case 1077:
	{
		damage(8);
		HP += 3;
	}break;
	case 8:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		int i;
		for (i = 0; i < n; i++)
		{
			(target + i)->EnemyBlock -= int((8 + Strength) * WeakCoefficient * target->Vulnerable);
		}
	}break;
	case 1008:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		int i;
		for (i = 0; i < n; i++)
		{
			(target + i)->EnemyBlock -= int((8 + Strength) * WeakCoefficient * target->Vulnerable);
		}
	}break;
	case 29:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		Combust = 5;
	}break;
	case 1029:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		Combust = 7;
	}break;
	case 35:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		Evolve = 1;
	}break;
	case 1035:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		Evolve = 2;
	}break;
	case 44:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		Metallicize = 3;
	}break;
	case 1044:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		Metallicize = 4;
	}break;
	case 45:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		Hand[HandPoint] = 131;
		Hand[HandPoint + 1] = 131;
		HandPoint += 2;
		Block += 15;
	}break;
	case 1045:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		Hand[HandPoint] = 131;
		Hand[HandPoint + 1] = 131;
		HandPoint += 2;
		Block += 20;
	}break;
	case 47:
	{
		Rage = 3;
	}break;
	case 1047:
	{
		Rage = 5;
	}break;
	case 48:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		damage(8 + RampageTime * 5);
		RampageTime += 1;
	}break;
	case 1048:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		damage(8 + RampageTime * 8);
		RampageTime += 1;
	}break;
	case 49:
	{
		damage(7);
		addToDrawPile(130);
	}break;
	case 1049:
	{
		damage(10);
		addToDrawPile(130);
	}break;
	case 50:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		Rupture = 1;
	}break;
	case 1050:
	{
		Rupture = 1;
	}break;
	case 57:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		int i;
		for (i = 0; i < n; i++)
		{
			if ((target + i)->intend == 0)
			{
				Strength += 3;
			}
		}
	}break;
	case 1057:
	{
		if(Deck[cardnum]->EnergyConsume(1, this))
		int i;
		for (i = 0; i < n; i++)
		{
			if ((target + i)->intend == 0)
			{
				Strength += 4;
			}
		}
	}break;
	case 59:
	{
		int i, j;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < Energy; j++)
			{
				(target + i)->EnemyBlock -= int((5 + Strength) * WeakCoefficient * target->Vulnerable);
			}
		}
		Energy = 0;
	}break;
	case 1059:
	{
		int i, j;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < Energy; j++)
			{
				(target + i)->EnemyBlock -= int((8 + Strength) * WeakCoefficient * target->Vulnerable);
			}
		}
		Energy = 0;
	}break;
	case 60:
	{
		if(Deck[cardnum]->EnergyConsume(3, this))
		Barricade = 1;
	}break;
	case 1060:
	{
		if(Deck[cardnum]->EnergyConsume(2, this))
		Barricade = 1;
	}break;
	case 63:
	{
		Brutality = 1;
	}break;*/
	}
}