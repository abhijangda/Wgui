#include"widget.h"

#ifndef PUSH_BUTTON_H
#define PUSH_BUTTON_H

struct _button
{
	Widget widget;
	wchar_t* text;

	void (*signal_double_clicked)(struct _button*);
	void (*signal_clicked)(struct _button*);
};

typedef struct _button PushButton;

PushButton* push_button_new(Widget*);
void push_button_get_ideal_size(PushButton*,Rect*);
void push_button_get_text(PushButton*,wchar_t*);
int push_button_get_text_length(PushButton*);
void push_button_get_text_margin(PushButton*,Rect*);
void push_button_set_text(PushButton*,wchar_t*);
void push_button_set_text_margin(PushButton*,Rect*);
void push_button_destroy(PushButton*);
#endif