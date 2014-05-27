#include"widget.h"

Widget** widget_ptr_array;
int widget_ptr_array_size=0;
int* widget_ptr_array_empty_pos_array;

int create_id()
{
	if(widget_ptr_array_size==0)
	{
		widget_ptr_array = (Widget**)malloc(sizeof(Widget*));
		widget_ptr_array_empty_pos_array = (int*)malloc(sizeof(int));
		widget_ptr_array_empty_pos_array[0] = -1;
	}
	else
		widget_ptr_array = (Widget**)realloc(widget_ptr_array,sizeof(Widget*)*(widget_ptr_array_size+1));

	if(widget_ptr_array_empty_pos_array[0]!=-1)
	{
		int id = widget_ptr_array_empty_pos_array[0];
		int size=-1;
		while(widget_ptr_array_empty_pos_array[++size]!=-1);
		for(int i = size;i>=0;i--)
			widget_ptr_array_empty_pos_array[i-1]=widget_ptr_array_empty_pos_array[i];

		return id;
	}
	else
		return widget_ptr_array_size;
}

Widget* widget_new(Widget* parent)
{
	Widget* _w = (Widget*) malloc(sizeof(Widget));
	_w->id=create_id();
	//widget_ptr_array[widget_ptr_array_size]=(Widget*)_w;
	_w->rect.height=-1;
	_w->rect.width=-1;
	_w->rect.x=-1;
	_w->rect.y=-1;

	_w->parent = parent;

	_w->signal_button_press=NULL;
	_w->signal_button_release=NULL;
	_w->signal_created=NULL;
	_w->signal_destroyed=NULL;
	_w->signal_hide=NULL;
	_w->signal_key_press=NULL;
	_w->signal_key_release=NULL;
	_w->signal_paint=NULL;
	_w->signal_show=NULL;

	return _w;
}

void widget_destroy(Widget* _w)
{
	DestroyWindow(_w->hwnd);
	widget_ptr_array[_w->id]=NULL;
	int size=-1;
	while(widget_ptr_array_empty_pos_array[++size]!=-1);
	widget_ptr_array_empty_pos_array[size]=_w->id;
	widget_ptr_array_empty_pos_array = (int*)realloc(widget_ptr_array_empty_pos_array,(size+1)*sizeof(int));
	if(_w->signal_destroyed!=NULL)
		_w->signal_destroyed();
	free((void*)_w);
}

void widget_set_height_width(Widget* _w,int h,int w)
{
	_w->rect.height = h;
	_w->rect.width = w;
	MoveWindow(_w->hwnd,_w->rect.x,_w->rect.y,h,w,TRUE);
}

void widget_show(Widget* _w)
{
	ShowWindow(_w->hwnd,TRUE);
}
void widget_hide(Widget* _w)
{
	ShowWindow(_w->hwnd,FALSE);
}
void widget_enabled(Widget* _w)
{
	EnableWindow(_w->hwnd,TRUE);
}

void widget_disabled(Widget* _w)
{
	EnableWindow(_w->hwnd,FALSE);
}

bool widget_is_visible(Widget* _w)
{
	if(IsWindowVisible(_w->hwnd))
		return true;
	return false;
}
bool widget_is_enabled(Widget* _w)
{
	if(IsWindowEnabled(_w->hwnd))
		return true;
	return false;
}