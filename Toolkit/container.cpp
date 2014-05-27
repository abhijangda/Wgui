#include "container.h"

Container* container_new(Widget* parent)
{
	Container* _w = (Container*)malloc(sizeof(Container));
	_w->widget = *widget_new(parent);

	_w->child_widget_array_size=0;
	_w->child_widget_array=NULL;
	_w->signal_on_add=NULL;
	_w->signal_on_remove=NULL;
	_w->signal_on_size_change=NULL;	
	return _w;
}

void container_add_widget(Container* _c,Widget* widget)
{	
	if(_c->child_widget_array_size==0)
		_c->child_widget_array = (Widget**)malloc(sizeof(Widget*));
	else
		_c->child_widget_array = (Widget**)realloc(_c->child_widget_array,sizeof(Widget*)*(_c->child_widget_array_size+1));

	_c->child_widget_array[_c->child_widget_array_size] = widget;
	_c->child_widget_array_size++;

	if(_c->signal_on_add!=NULL)
		_c->signal_on_add(widget);
}

void container_remove_widget(Container* _c,Widget* widget)
{
	int i;
	for(i = 0; i<_c->child_widget_array_size;i++)
		if(widget==_c->child_widget_array[i])
			break;
	
	int index = i;
	for(i=index;i<_c->child_widget_array_size-1;i++)
		_c->child_widget_array[i] = _c->child_widget_array[i+1];

	_c->child_widget_array = (Widget**)realloc(_c->child_widget_array,sizeof(Widget*)*(_c->child_widget_array_size-1));
	_c->child_widget_array_size--;

	if(_c->signal_on_remove)
		_c->signal_on_remove(widget);	
}