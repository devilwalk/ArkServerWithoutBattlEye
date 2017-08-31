#include <Windows.h>
#include <tchar.h>
#include <string>
int main(int argc,char *argv[])
{
	std::string args;
	for(int i=1;i<argc;++i)
	{
		args+=" ";
		args+=argv[i];
	}
	args+=" -NoBattlEye";
	STARTUPINFOA start_up_info={0};
	PROCESS_INFORMATION pi={0};
	if(args.empty())
		CreateProcessA("ShooterGameServer_.exe",nullptr,nullptr,nullptr,FALSE,0,nullptr,nullptr,&start_up_info,&pi);
	else
		CreateProcessA("ShooterGameServer_.exe",&args[0],nullptr,nullptr,FALSE,0,nullptr,nullptr,&start_up_info,&pi);
	CloseHandle(start_up_info.hStdError);
	CloseHandle(start_up_info.hStdInput);
	CloseHandle(start_up_info.hStdOutput);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}