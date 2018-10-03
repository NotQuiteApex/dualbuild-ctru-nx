/* The simple "Hello World!" for 3DS and Switch */
/*              but in one main.cpp             */
/*          Don't try this at home kids         */

#include <cstdio>


#if defined(_3DS) // if building for 3ds

#include <3ds.h>

#elif defined(__SWITCH__) // or for switch

#include <switch.h>
#define aptMainLoop appletMainLoop	// These defines are purely to lessen some
#define KEY_START KEY_PLUS			// the number of times we do an if elif
#define KEY_SELECT KEY_MINUS		// check for 3ds or switch, since they're
									// mostly the same functions.
#endif


int main(int argc, char **argv)
{
	gfxInitDefault();

#if defined(_3DS)					// Here's an example of dealing with
	consoleInit(GFX_TOP, NULL);		// the minor changes between libctru and
#elif defined(__SWITCH__)			// libnx. As you can see, its syntax isn't
	consoleInit(NULL);				// too pretty.
#endif

	printf("\x1b[16;20HHello World!");
	printf("\x1b[30;16HPress Start to exit.");

	// No need to change this due to the macro.
	while(aptMainLoop())
	{
		// Some functions do retain their name between the libraries.
		hidScanInput();

		// Though some functions require different arguments.
#if defined(_3DS)
		u32 kDown = hidKeysDown();
#elif defined(__SWITCH__)
		u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
#endif
		// The solution is always more macros.

		// When building for Switch, it will change to KEY_PLUS.
		// Could be a problem with for sideways joycons, I've yet to test it.
		if(kDown & KEY_START) break;

		gfxFlushBuffers();
		gfxSwapBuffers();

#if defined(_3DS)
		gspWaitForVBlank();
#endif
	}

	gfxExit();
	return 0;
}