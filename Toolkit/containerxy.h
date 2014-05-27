#include"container.h"

#ifndef CONTAINERXY_H
#define CONTAINERXY_H

struct _containerxy
{
	Container container;
};

typedef _containerxy ContainerXY;

void container_xy_add_widget_at(ContainerXY*,Widget*, int, int,int,int);
ContainerXY* container_xy_new(Widget*);
void container_xy_set_child_pos(ContainerXY*,Widget*, int, int);

#endif