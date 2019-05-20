
//#include "StdAfx.h"
#include <time.h>
#include <stdlib.h>
#include "Cards.h"
#include "StateVariables.h"
#include "Enemy.h"
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
