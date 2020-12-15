#include "StructGame.h"
#include "BaseGame.h"
TROLE_PROPERTY* TROLE_PROPERTY::GetData()
{

	// ����쳣����
	try {
		// +0����������
		szRoleName = (char*)BaseRole;
		// + 80������ֵ(�� / HP)
		ndRoleHP = (DWORD)(BaseRole + 0x80);
		// + 84���ڹ�ֵ(�� / MP)
		ndRoleMP = (DWORD)(BaseRole + 0x84);
		// + 88����ŭֵ
		ndRoleAnger = (DWORD)(BaseRole + 0x88);
		// + 8C���������ֵ
		ndRoleMaxHP = (DWORD)(BaseRole + 0x8c);
		// + 90������ڹ�ֵ
		ndRoleMaxMP = (DWORD)(BaseRole + 0x90);
		// + 94�����ֵ��ŭֵ
		nqRoleMaxAnger = (QWORD)(BaseRole + 0x94);
		// + 98����ǰ����ֵ
		nqRoleExprienceNow = (QWORD)(BaseRole + 0x98);
		// + A0����������һ��Ҫ�ľ���ֵ
		ndRoleExperienceNext = (DWORD)(BaseRole + 0xA0);
		// + 36������
		szReputation = (char*)(BaseRole + 0x36);
		// + 34��һ�ֽڿռ��ʾ�ȼ�
		nbClassValue = *(BYTE*)(BaseRole + 0x34);
		// + 35��һ�ֽڿռ��ʾ ��ת
		nbJZ = *(BYTE*)(BaseRole + 0x35);
		// + AC������
		ndExprience = (DWORD)(BaseRole + 0xac);
		// + C8������
		ndAttack = (DWORD)(BaseRole + 0xc8);
		// + CC������
		ndDefense = (DWORD)(BaseRole + 0xcc);
		// + D4���ر�
		ndAvoid = (DWORD)(BaseRole + 0xd4);
		// + B0����
		ndHeart = (DWORD)(BaseRole + 0xb0);
		// + B4����
		ndGas = (DWORD)(BaseRole + 0xb4);
		// + B8����
		ndBody = (DWORD)(BaseRole + 0x8c);
		// + BC����
		ndSoul = (DWORD)(BaseRole + 0xbc);
		// + E4�����ֵ
		nqMoney = (QWORD)(BaseRole + 0xe4);

		for (int i = 0; i < 32; i++) {
			ndQg[i] = *(BYTE*)(BaseRole + 0xf0 + 4 * (i + 1));
		}
	}
	catch (...) {
		// �������е��쳣
		OutputDebugStringA("��ȡ���������쳣\r\n");
	}



	return this;
}

// ��ȡ��ɫ�����ơ�
char* TROLE_PROPERTY::GetRoleName() {
	return GetData()->szRoleName;
}