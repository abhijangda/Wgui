#include "main.h"

bool on_window_close()
{
	//MessageBoxW(NULL,L"Hello",L"Title",MB_OK);
	return true;
}

void on_window_show(bool _b)
{
	MessageBoxW(NULL,L"Hello",L"Title",MB_OK);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	Window* _w = window_new(hInstance);	
	
	HorizontalLayout* hlayout = horizontal_layout_new((Widget*)_w);

	CheckButton* widget = check_button_new((Widget*)_w);
	container_xy_add_widget_at((ContainerXY*)_w,(Widget*)hlayout,100,100,100,100);
	layout_add((Layout*)hlayout, (Widget*)widget);
	widget_set_height_width((Widget*)hlayout,50,50);

	window_show(_w,nCmdShow);
	window_update(_w);
	
	start_main_loop();
	window_destroy(_w);
	return 0;
}
