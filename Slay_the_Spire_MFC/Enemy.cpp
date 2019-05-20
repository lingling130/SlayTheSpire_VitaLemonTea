#include "stdafx.h"
#include "StateVariables.h"

Enemy::Enemy(int hp, unsigned int damage1, unsigned int attackTimes1, unsigned int damage2, unsigned int attackTimes2, unsigned int damage3, unsigned int attackTimes3)
{
	EnemyHP = hp;
	EnemyBlock = 0;
	Damage1 = damage1;
	AttackTimes1 = attackTimes1;
	AttackTimes2 = attackTimes2;
	AttackTimes3 = attackTimes3;
	Damage2 = damage2;
	Damage3 = damage3;
	State_Vulnerable = 0;
	State_Poison = 0;
	State_Ritual = 0;
	strength = 0;
}


Enemy::~Enemy(void)
{
}

void Enemy::debuffWeak(int n, StateVariables* player)
{
	player->Weak += n;
}

void Enemy::debuffMucus(int n, StateVariables* player)
{
	int i;
	for (i = 0; i < n; i++)
	{
		player->DiscardPile[player->DiscardPoint+i] = 0105;
	}
	player->DiscardPoint += n;
}

void Enemy::debuffVulnerable(int n, StateVariables* player)
{
	player->Vulnerable += n;
}

void Enemy::buffRitual()
{
	State_Ritual = 1;
}

void Enemy::buffStrengthUp(unsigned int n)
{
	strength += n;
}

void Enemy::buffFrail(int n, StateVariables* player)
{
	player->Frail += n;
}
