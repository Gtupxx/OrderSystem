#include"management.h"
#include"window.h"
#pragma comment(lib,"Winmm.lib")

#ifndef _DEBUG
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )	// 隐藏控制台
#endif // _DEBUG
int main()
{

	window w(960, 600, NULL);
	w.set_window_title("万民堂点菜系统");
	PlaySound("./image/bkmusic.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//音乐循环播放
	management m;
	m.run();


	return w.exec();
}