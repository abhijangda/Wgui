#include"mainloop.h"

extern Widget** widget_ptr_array;
extern int widget_ptr_array_size;

LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	Window *win = (Window*)widget_ptr_array[0];
	bool call_def_proc = true;
	int x = (int)(short)LOWORD(lParam);
	int y = (int)(short)HIWORD(lParam);

	switch(msg)
	{
	case WM_CREATE:		
		return 0;

	//case WM_CLOSE:				
		if(win->signal_close!=NULL && win->signal_close(win)==true)
			call_def_proc=false;
		break;

	case WM_SHOWWINDOW:
		if(win->signal_show!=NULL)
		{
			if(wParam)
			    win->signal_show(win,true);
			else
				win->signal_show(win,false);
		}
		break;

	case WM_ACTIVATEAPP:

		if(win->signal_activate!=NULL)
			if(wParam)
			    win->signal_activate(win,true);
			else
				win->signal_activate(win,false);			
		break;

	case WM_ENABLE:

		if(win->signal_enabled!=NULL)
			if(wParam)
			    win->signal_enabled(win,true);
			else
				win->signal_enabled(win,false);			
		break;

	case WM_MOVE:
		
		if(win->signal_moved!=NULL)
			win->signal_moved(win,x,y);
		break;

	case WM_SIZE:

		if(win->signal_size_changed!=NULL)
			win->signal_size_changed(win,(int)wParam);
		break;

	case WM_DESTROY:		
		PostQuitMessage(WM_QUIT);
		return 0;	
	}
	
	//if(call_def_proc)
	//{
		return DefWindowProcW(hwnd,msg,wParam,lParam);		
	//}
	return 0;
}

void start_main_loop()
{
	MSG msg;
	while((GetMessage(&msg,NULL,0,0)))
	{
		TranslateMessage (&msg) ;
		DispatchMessage(&msg);
	}
}