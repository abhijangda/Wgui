#include"container.h"

#ifndef LAYOUT_H
#define LAYOUT_H

struct _layout
{
	Container container;
};
typedef struct _layout Layout;

Layout* layout_new(Widget*);
void layout_add(Layout*,Widget*);
void layout_remove(Layout*,Widget*);
void layout_destroy(Widget*);
#endif