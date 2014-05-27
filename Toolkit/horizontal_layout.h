#include"layout.h"

#ifndef HORIZONTAL_LAYOUT_H
#define HORIZONTAL_LAYOUT_H

struct _horiz_layout
{
	Layout layout;
};

typedef struct _horiz_layout HorizontalLayout;

HorizontalLayout* horizontal_layout_new(Widget*);
void horizontal_layout_on_size_change(Container*);
void horizontal_layout_destroy(HorizontalLayout*);
#endif