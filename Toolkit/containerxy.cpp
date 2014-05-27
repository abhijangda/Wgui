#include"containerxy.h"

void container_xy_add_widget_at(ContainerXY* _c, Widget* _w, int x, int y, int height, int width)
{
	_w->rect.x=x;
	_w->rect.y=y;
	_w->rect.height=height;
	_w->rect.width=width;

	container_add_widget((Container*)_c,_w);
	SetWindowPos(((Widget*)_w)->hwnd,0,x,y,height,width,SWP_NOZORDER|SWP_NOSIZE);
}

ContainerXY* container_xy_new(Widget* parent)
{
	ContainerXY* containerxy = (ContainerXY*)malloc(sizeof(ContainerXY));
	containerxy->container = *container_new(parent);
	return containerxy;
}

void container_xy_set_child_pos(Widget* _w, int x, int y)
{
	_w->rect.x=x;
	_w->rect.y=y;

	SetWindowPos(((Widget*)_w)->hwnd,0,x,y,_w->rect.height,_w->rect.width,SWP_NOZORDER|SWP_NOSIZE);
}