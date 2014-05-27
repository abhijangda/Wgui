#include"containerxy.h"

#ifndef WINDOW_H
#define WINDOW_H
struct _window
{
	ContainerXY containerxy;
	WNDCLASSW wc;
	HINSTANCE hInstance;

	void (*signal_activate)(struct _window*,bool); //Done
	bool (*signal_close)(struct _window*);//Done
	void (*signal_enabled)(struct _window*,bool);//Done
	void (*signal_hscroll)(struct _window*);
	void (*signal_moved)(struct _window*,int,int);//Done
	void (*signal_show)(struct _window*,bool);//Done
	void (*signal_size_changed)(struct _window*,int);//Done
	void (*signal_vscroll)(struct _window*);
};

typedef struct _window Window;

Window* window_new(HINSTANCE hInstance);
void window_destroy(Window*);
void window_show(Window*,int);
void window_update(Window*);

#endif