#include "StructGame.h"
#include "BaseGame.h"
TROLE_PROPERTY* TROLE_PROPERTY::GetData()
{

	// 添加异常处理
	try {
		// +0：人物名字
		szRoleName = (char*)BaseRole;
		// + 80：生命值(红 / HP)
		ndRoleHP = (DWORD)(BaseRole + 0x80);
		// + 84：内功值(蓝 / MP)
		ndRoleMP = (DWORD)(BaseRole + 0x84);
		// + 88：愤怒值
		ndRoleAnger = (DWORD)(BaseRole + 0x88);
		// + 8C：最大生命值
		ndRoleMaxHP = (DWORD)(BaseRole + 0x8c);
		// + 90：最大内功值
		ndRoleMaxMP = (DWORD)(BaseRole + 0x90);
		// + 94：最大值愤怒值
		nqRoleMaxAnger = (QWORD)(BaseRole + 0x94);
		// + 98：当前经验值
		nqRoleExprienceNow = (QWORD)(BaseRole + 0x98);
		// + A0：升级到下一级要的经验值
		ndRoleExperienceNext = (DWORD)(BaseRole + 0xA0);
		// + 36：名声
		szReputation = (char*)(BaseRole + 0x36);
		// + 34：一字节空间表示等级
		nbClassValue = *(BYTE*)(BaseRole + 0x34);
		// + 35：一字节空间表示 几转
		nbJZ = *(BYTE*)(BaseRole + 0x35);
		// + AC：历练
		ndExprience = (DWORD)(BaseRole + 0xac);
		// + C8：攻击
		ndAttack = (DWORD)(BaseRole + 0xc8);
		// + CC：防御
		ndDefense = (DWORD)(BaseRole + 0xcc);
		// + D4：回避
		ndAvoid = (DWORD)(BaseRole + 0xd4);
		// + B0：心
		ndHeart = (DWORD)(BaseRole + 0xb0);
		// + B4：气
		ndGas = (DWORD)(BaseRole + 0xb4);
		// + B8：体
		ndBody = (DWORD)(BaseRole + 0x8c);
		// + BC：魂
		ndSoul = (DWORD)(BaseRole + 0xbc);
		// + E4：金币值
		nqMoney = (QWORD)(BaseRole + 0xe4);

		for (int i = 0; i < 32; i++) {
			ndQg[i] = *(BYTE*)(BaseRole + 0xf0 + 4 * (i + 1));
		}
	}
	catch (...) {
		// 处理所有的异常
		OutputDebugStringA("读取人物数据异常\r\n");
	}



	return this;
}

// 获取角色的名称、
char* TROLE_PROPERTY::GetRoleName() {
	return GetData()->szRoleName;
}