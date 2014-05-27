#include"widget.h"

#ifndef CONTAINER_H
#define CONTAINER_H

struct _container
{
	Widget widget;
	Widget** child_widget_array;
	int child_widget_array_size;

	void (*signal_on_add)(Widget*);
	void (*signal_on_remove)(Widget*);
	void (*signal_on_size_change)(struct _container*);
};

typedef struct _container Container;

Container* container_new(Widget*);
void container_add_widget(Container*,Widget*);
void container_remove_widget(Container*,Widget*);
#endif