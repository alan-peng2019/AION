#pragma once
#include <windows.h>
typedef unsigned __int64 QWORD;
// ��Ϸ�ṹ�Լ�ƫ�����Ĺ���

typedef struct TROLE_PROPERTY {

	// +0����������
	char* szRoleName;
	// + 80������ֵ(�� / HP)
	DWORD ndRoleHP;
	// + 84���ڹ�ֵ(�� / MP)
	DWORD ndRoleMP;
	// + 88����ŭֵ
	DWORD ndRoleAnger;
	// + 8C���������ֵ
	DWORD ndRoleMaxHP;
	// + 90������ڹ�ֵ
	DWORD ndRoleMaxMP;
	// + 94�����ֵ��ŭֵ
	QWORD nqRoleMaxAnger;
	// + 98����ǰ����ֵ
	QWORD nqRoleExprienceNow;
	// + A0����������һ��Ҫ�ľ���ֵ
	DWORD ndRoleExperienceNext;
	// + 36������
	char* szReputation;
	// + 34��һ�ֽڿռ��ʾ�ȼ�
	BYTE nbClassValue;
	// + 35��һ�ֽڿռ��ʾ ��ת
	BYTE nbJZ;
	// + AC������
	DWORD ndExprience;
	// + C8������
	DWORD ndAttack;
	// + CC������
	DWORD ndDefense;
	// + D4���ر�
	DWORD ndAvoid;
	// + B0����
	DWORD ndHeart;
	// + B4����
	DWORD ndGas;
	// + B8����
	DWORD ndBody;
	// + BC����
	DWORD ndSoul;
	// + E4�����ֵ
	QWORD nqMoney;
	// ����
	DWORD ndQg[32];

	TROLE_PROPERTY* GetData();

	char* GetRoleName();

}_TROLE_PROPERTY;