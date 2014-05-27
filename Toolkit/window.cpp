#include "window.h"
#include "mainloop.h"

extern Widget** widget_ptr_array;
extern int widget_ptr_array_size;

HINSTANCE hInstance;
Window* window_new(HINSTANCE _hInstance)
{
	hInstance = _hInstance;
	Window* _w = (Window*)malloc(sizeof(Window));
	_w->containerxy = *container_xy_new(NULL);
	//widget_ptr_array[widget_ptr_array_size]=(Widget*)_w;

	_w->wc.style = CS_HREDRAW|CS_VREDRAW;
	_w->wc.cbClsExtra = 0;
	_w->wc.cbWndExtra = 0;
	_w->wc.lpszClassName = L"Window";
	((Widget*)_w)->class_name = (wchar_t*)malloc(sizeof(char)*6);
	((Widget*)_w)->class_name = L"Window";	
	_w->wc.hInstance = hInstance;
	_w->hInstance = hInstance;
	_w->wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	_w->wc.lpszMenuName = NULL;
	_w->wc.lpfnWndProc = WndProc;
	_w->wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	_w->wc.hIcon = LoadIcon(NULL,IDI_APPLICATION);

	RegisterClassW(&(_w->wc));
	((Widget*)_w)->hwnd = CreateWindowW(_w->wc.lpszClassName, L"Window", WS_OVERLAPPEDWINDOW|WS_VISIBLE,100,100,350,250,NULL,NULL,hInstance,NULL);

	_w->signal_activate=NULL;
	_w->signal_close=NULL;
	_w->signal_enabled=NULL;
	_w->signal_hscroll=NULL;
	_w->signal_moved=NULL;	
	_w->signal_show=NULL;
	_w->signal_size_changed=NULL;
	_w->signal_vscroll=NULL;
	
	return _w;
}

void window_destroy(Window* _w)
{
	//free(_w->containerxy);
	free(_w);
}

void window_show(Window* _w,int nCmdShow)
{
	ShowWindow(((Widget*)_w)->hwnd,nCmdShow);
	if(_w->signal_show!=NULL)
		_w->signal_show(_w,true);
}

void window_update(Window* _w)
{
	UpdateWindow(((Widget*)_w)->hwnd);
}