#include"check_button.h"

#ifndef RADIO_BUTTON_H
#define RADIO_BUTTON_H

struct _r
{
	CheckButton check_button;
};

typedef struct _r RadioButton;

RadioButton* radio_button_new(Widget*);
void radio_button_destroy(Widget*);
#endif