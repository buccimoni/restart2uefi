#include <windows.h>

int run_reboot_to_uefi(void)
{
	STARTUPINFO strinfo = { sizeof(strinfo) };
	PROCESS_INFORMATION procinfo;

	const char* cmd = "shutdown /r /fw /t 0";
	size_t return_value;
	wchar_t commandline[512];
	mbstowcs_s( &return_value, commandline, sizeof(commandline), cmd, _TRUNCATE );

	CreateProcess( NULL, (LPTSTR)commandline, NULL, NULL, FALSE, 0, NULL, NULL, &strinfo, &procinfo );

	return 1;
}

int WINAPI WinMain( _In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd )
{
	int button;
	button = MessageBox( NULL, TEXT( "Windows ÇçƒãNìÆÇµÇƒ UEFI Ç…ì¸ÇËÇ‹Ç∑Ç©?" ),
		TEXT( "Restart2UEFI" ), MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2 );

	if ( button == IDYES ) {
		run_reboot_to_uefi();

	}

	return 0;
}