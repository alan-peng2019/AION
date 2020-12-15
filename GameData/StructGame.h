#pragma once
#include <windows.h>
typedef unsigned __int64 QWORD;
// 游戏结构以及偏移量的管理

typedef struct TROLE_PROPERTY {

	// +0：人物名字
	char* szRoleName;
	// + 80：生命值(红 / HP)
	DWORD ndRoleHP;
	// + 84：内功值(蓝 / MP)
	DWORD ndRoleMP;
	// + 88：愤怒值
	DWORD ndRoleAnger;
	// + 8C：最大生命值
	DWORD ndRoleMaxHP;
	// + 90：最大内功值
	DWORD ndRoleMaxMP;
	// + 94：最大值愤怒值
	QWORD nqRoleMaxAnger;
	// + 98：当前经验值
	QWORD nqRoleExprienceNow;
	// + A0：升级到下一级要的经验值
	DWORD ndRoleExperienceNext;
	// + 36：名声
	char* szReputation;
	// + 34：一字节空间表示等级
	BYTE nbClassValue;
	// + 35：一字节空间表示 几转
	BYTE nbJZ;
	// + AC：历练
	DWORD ndExprience;
	// + C8：攻击
	DWORD ndAttack;
	// + CC：防御
	DWORD ndDefense;
	// + D4：回避
	DWORD ndAvoid;
	// + B0：心
	DWORD ndHeart;
	// + B4：气
	DWORD ndGas;
	// + B8：体
	DWORD ndBody;
	// + BC：魂
	DWORD ndSoul;
	// + E4：金币值
	QWORD nqMoney;
	// 气功
	DWORD ndQg[32];

	TROLE_PROPERTY* GetData();

	char* GetRoleName();

}_TROLE_PROPERTY;