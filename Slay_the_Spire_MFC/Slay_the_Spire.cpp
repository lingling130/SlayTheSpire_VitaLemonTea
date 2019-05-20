#include "stdafx.h"


#include "Slay_the_Spire.h"
#include "StateVariables.h"

void main()
{
	StateVariables* player = new StateVariables();//生成初始信息
	/*准备战斗！！*/
	//生成DrawPile

	/*检测遗物并结算*/
	player->draw(player->DrawNum);

	return;
}