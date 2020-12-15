// InjectDll.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//获取游戏进程，附加DLL

#include <iostream>
#include <windows.h>

using namespace std;

#define GameClassName "AIONClientWndClass1.0"
#define DllPath "D:\\MFC_DLL\\Debug\\MFC_DLL.dll"


// 针对XP提高程序的访问权限
BOOL ImproveAccessPrivilege()
{
	HANDLE tokenHandle;
	LUID privilegeValue;

	if (!::OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &tokenHandle)) return FALSE;

	if (!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &privilegeValue))
	{
		::CloseHandle(tokenHandle);
		return FALSE;
	}

	TOKEN_PRIVILEGES privileges;
	privileges.PrivilegeCount = 1;
	privileges.Privileges[0].Luid = privilegeValue;
	privileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	if (!::AdjustTokenPrivileges(tokenHandle, FALSE, &privileges, sizeof(privileges), NULL, NULL))
	{
		::CloseHandle(tokenHandle);
		return FALSE;
	}

	return TRUE;
}


void InjectDll(void)
{
    DWORD pid = 0;
    HANDLE hProcess = NULL;
    LPDWORD lpAddr = NULL;
    SIZE_T size = NULL;
    HANDLE threadHandle = NULL;

    //获取游戏窗口句柄
    HWND GameH = FindWindow((LPCTSTR)GameClassName, NULL);
    if (GameH != 0)
    {
		//句柄获取成功
		// 获取进程PID
        cout << "获取窗口句柄成功" << endl;
        GetWindowThreadProcessId(GameH, &pid);
        if (pid != 0)
        {
			// PID 获取成功
			// 获取进程句柄
			// 开启所以权限打开进程
            cout << "获取PID成功" << endl;
            hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
                if (hProcess != NULL)
                {
					// 打开进程成功
				    // 分配内存空间，写入动态链接库的全路径名
                    //G:\个人资料\MFC_DLL\Debug\MFC_DLL.dll

                    cout << "打开进程成功" << endl;
                    lpAddr = (LPDWORD)VirtualAllocEx(hProcess,NULL,256,MEM_COMMIT,PAGE_READWRITE);
                        if (lpAddr !=NULL)
                        {
                            //// 地址分配成功, 写入DLL 的全路径
                            cout << "地址分配成功" << endl;
                            //WriteProcessMemory(hProcess,lpAddr,DllPath,strlen(DllPath) + 1,&size);
                            WriteProcessMemory(hProcess,lpAddr,DllPath,strlen(DllPath) + 1,&size);
                                if (size >= strlen(DllPath))
                                {
                                    cout << "注入DLL成功" << endl;
                                    threadHandle = CreateRemoteThread(hProcess,NULL,NULL,(LPTHREAD_START_ROUTINE)LoadLibraryA,lpAddr,NULL,NULL);
                                        // 等待注入DLL 的线程执行完再执行下一步(等待的进程句柄， 等到多少毫秒)
                                    WaitForSingleObject(threadHandle, 0XFFFFFFFF);
                                        // 关闭线程
                                        CloseHandle(threadHandle);
                                    // 释放进程
                                     VirtualFreeEx(hProcess, lpAddr, 256, MEM_COMMIT);
                                    // 关闭句柄
                                    CloseHandle(hProcess);
                                    //清除内存数据
                                }
                                else
                                {
                                    cout << "写入DLL失败" << endl;
                                }
                        }
						else
						{
							cout << "地址分配失败" << endl;
						}
                }
				else
				{
					cout << "打开进程失败" << endl;
				}
        }
		else
		{
			cout << "获取PID失败" << endl;
		}

    }
	else
	{
		cout << "获取窗口句柄失败" << endl;
	}
}

int main()
{
    // 添加注入DLL 代码
    cout << "开始注入DLL" << endl;
    ImproveAccessPrivilege();
    InjectDll();
    cout <<  "注入DLL结束" << endl;
   // getchar();
}

