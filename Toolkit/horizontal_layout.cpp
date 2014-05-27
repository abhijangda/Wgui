#include"horizontal_layout.h"

HorizontalLayout* horizontal_layout_new(Widget* parent)
{
	HorizontalLayout* _h = (HorizontalLayout*)malloc(sizeof(HorizontalLayout));
	_h->layout = *layout_new(parent);

	((Container*)_h)->signal_on_size_change = horizontal_layout_on_size_change;
	return _h;
}

void horizontal_layout_on_size_change(Container* _c)
{
	Rect r = ((Widget*)_c)->rect;
	int visible_widgets=0;
	for(int i =0;i<_c->child_widget_array_size;i++)
	{
		if(widget_is_visible((Widget*)_c))
			visible_widgets++;
	}
	if(!visible_widgets)
		return;

	int width_of_child = r.width/visible_widgets;
	int height_of_child = r.height;
	int x_child=0,y_child=0;
	for(int i=0;i<_c->child_widget_array_size;i++)
	{
		if(widget_is_visible((Widget*)_c))
		{
			x_child = i*width_of_child;
			MoveWindow(((Widget*)_c)->hwnd,x_child,y_child,width_of_child,height_of_child,TRUE);
		}
	}
}

void horizontal_layout_destroy(HorizontalLayout*)
{
}