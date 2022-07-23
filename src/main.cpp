#include <string>
#include <cstdint>
#include <iostream>
#include <filesystem>

#include "pe32.h"
#include "pe64.h"

using namespace std;


int wmain(int argc,wchar_t* argv[]) {

	if (argc < 3) {
		wcout << "[E]Error : too few parameters\n";
		return -1;
	}

	wstring fileName = argv[1];
	wstring funcName = argv[2];

	if (!filesystem::exists(fileName)) {
		wcout << "[E]Error : wrong file path ?\n" << endl;
		return -1;
	}

	wcout << format(L"[I]fileName : {}   funcName : {}\n", fileName, funcName);

	//x64exe cant load x86 dll,and x86exe cant load x64 dll
	const char* base = (const char*)LoadLibraryExW(fileName.c_str(), NULL, DONT_RESOLVE_DLL_REFERENCES);
	if (!base) {
		auto error = GetLastError();
		wcout << "[E]Error : moduel load failed\n" << error;
		return -1;
	}
	
	
	




	return 0;
}