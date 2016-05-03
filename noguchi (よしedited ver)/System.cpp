#include "DxLib.h"
#include "Suken.h"

#define FPS 60

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	SetWindowText("Title");
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK );

	Awake();

	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){
		GameLoop();
		Sleep((int)(1000/FPS));
	}
        
	DxLib_End();
	return 0;
} 