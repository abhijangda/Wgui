#include <Windows.h>
#include <CommCtrl.h>
#include<WindowsX.h>
#include <stdlib.h>
#include "rect.h"

#ifndef WIDGET_H
#define WIDGET_H
struct _widget
{
	wchar_t* class_name;
	HWND hwnd;
	int id;
	Rect rect;

	struct _widget* parent;
	void (*signal_button_press)();
	void (*signal_button_release)();
	void (*signal_created)();
	void (*signal_destroyed)();
	void (*signal_hide)();
	void (*signal_key_press)();
	void (*signal_key_release)();
	void (*signal_paint)();
	void (*signal_show)();
};

typedef struct _widget Widget;

Widget* widget_new(Widget*);
void widget_destroy(Widget*);
void widget_set_height_width(Widget*,int,int);
void widget_show(Widget*);
void widget_hide(Widget*);
void widget_enabled(Widget*);
void widget_disabled(Widget*);
bool widget_is_visible(Widget*);
bool widget_is_enabled(Widget*);
int create_id();
#endif