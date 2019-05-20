#pragma once
#include "stdafx.h"

class Enemy;
class Cards;

class StateVariables
{
public:
	StateVariables(void);
	~StateVariables(void);
	int HP;//生命值
	int HPMax;//生命值上限
	int Energy;//法力值
	int EnergyMax;//法力值上限
	int Block;//护盾
	int Strength;//力量
	int StrengthUpTemp;//单回合增加的力量
	int Dexterity;//敏捷
	int DexterityUpTemp;//单回合增加的敏捷
	int Gold;//金币
	unsigned int Hand[10];//手牌
	Cards* GameDeck[300];//游戏牌库
	unsigned int GameDeckPoint;//游戏牌库指针
	Cards* Deck[100];//玩家牌库
	unsigned int DeckPoint;//玩家牌库指针
	int DrawNum;
	int DrawPile[100];//抽牌堆数组
	int DiscardPile[100];
	int DrawPoint;//抽牌堆指针
	int DiscardPoint;//弃牌堆指针
	int HandPoint;//手牌指针
	int StrengthUp;//每回合增加力量
	int Vulnerable;//易伤
	int Weak;//虚弱
	int Berserk;//下回合开始获得Energy
	int Frail;//破甲
	float WeakCoefficient;//虚弱系数
	int CanDraw;//是否可继续摸牌
	int FlameBarrier;//FB效果
	int Juggernaut;//Juggernaut效果
	int Combust;//Combust效果
	int Evolve;//Evolve效果
	int Metallicize;//Metallicize效果
	int Rage;//Rage效果
	int RampageTime;//Rampage使用次数
	int Rupture;//Rupture效果
	int Barricade;//Barricade效果
	int Brutality;//Brutality效果

	void draw(int drawnum);
	void usecard(int cardnum, Enemy* target, int n);
	void addToDrawPile(int cardnum);

};

class Enemy
{
public:
	Enemy(int hp, unsigned int damage1, unsigned int attackTimes1 = 1, unsigned int damage2 = 0, unsigned int attackTimes2 = 0, unsigned int damage3 = 0, unsigned int attackTimes3 = 0);
	~Enemy(void);
	int EnemyHP;//怪物血量
	unsigned int EnemyBlock;//怪物护盾
	unsigned int Damage1;//怪物攻击方案1伤害
	unsigned int AttackTimes1;//怪物攻击方案1次数
	unsigned int Damage2;//怪物攻击方案2伤害
	unsigned int AttackTimes2;//怪物攻击方案2次数
	unsigned int Damage3;//怪物攻击方案3伤害
	unsigned int AttackTimes3;//怪物攻击方案3次数

	int State_Weak;//虚弱
	int State_Vulnerable;//易伤
	int State_Poison;//中毒
	int State_Ritual;//仪式：回合结束加攻
	unsigned int strength;//力量，攻击附加伤害
	float Vulnerable;
	int intend;//下次执行命令

	void debuffWeak(int n, StateVariables* player);//上n层虚弱
	void debuffMucus(int n, StateVariables* player);//给粘液牌
	void debuffVulnerable(int n, StateVariables* player);//上n层易伤
	void buffRitual();//仪式效果
	void buffStrengthUp(unsigned int n);//加n力量
	void buffFrail(int n, StateVariables* player);//上n层破甲
};

class Cards
{
public:
	Cards(void);
	~Cards(void);
	unsigned int CardsNum;//卡牌编号
	unsigned int EnergyCost;//费用
	unsigned int EnergyCost_Up;//升级后费用
	int GainBlock;//获得护甲值
	int GainBlock_Up;//升级后获得护甲值
	int Damage;//造成伤害值
	int Damage_Up;//升级后造成伤害值
	int LevelUp;//是否已升级，1表示升级，0表示未升级

	int EnergyConsume(int x, StateVariables* player);
};