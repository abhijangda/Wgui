#include "push_button.h"

#ifndef CHECK_BUTTON_H
#define CHECK_BUTTON_H

struct _check
{
	PushButton push_button;
	void (*signal_state_changed)(int);
};

typedef struct _check CheckButton;

CheckButton* check_button_new(Widget*);
void check_button_set_state(CheckButton*,int);
void check_button_destroy(CheckButton*);
#endif