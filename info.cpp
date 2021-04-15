/* Paste in your R_Lua.h or Address File */
#define ASLR(x) (x - 0x400000 + (DWORD)GetModuleHandleA(0))

typedef int(print_CCV* printr)(int, const char*, ...);
printr printerf = (printr)(ASLR(print_addr)); // IF ASLR Errors

/* Paste in your main cpp file (entry) */

	int info_print(DWORD rL)
	{
		const char* infokey = r_lua_tostring(rL, -1);
		std::string lolii = infokey;
		printerf(1, lolii.c_str());
		return 1;
	}
  
  /* Register Function */
	r_luaL_register(RL, "info", info_print); // RL is DWORD.
