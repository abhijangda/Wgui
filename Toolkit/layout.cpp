#include"layout.h"

Layout* layout_new(Widget* parent)
{
	Layout* _l = (Layout*)malloc(sizeof(Layout));
	_l->container = *container_new(parent);
	return _l;
}

void layout_add(Layout* layout,Widget* widget)
{
	container_add_widget((Container*)layout,widget);
}

void layout_remove(Layout* layout,Widget* widget)
{
	container_remove_widget((Container*)layout,widget);
}

void layout_destroy(Widget* widget)
{
}