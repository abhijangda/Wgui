#include"check_button.h"

CheckButton* check_button_new(Widget* parent)
{
	CheckButton* _ch = (CheckButton*)malloc(sizeof(CheckButton));
	_ch->push_button = *push_button_new(parent);
	Button_SetStyle(((Widget*)_ch)->hwnd,BS_AUTOCHECKBOX,TRUE);
	return _ch;
}

void check_button_set_state(CheckButton* _c,int state)
{	
	Button_SetCheck(((Widget*)_c)->hwnd,state);
}

void check_button_destroy(CheckButton*)
{
}