#include"radio_button.h"

RadioButton* radio_button_new(Widget* parent)
{
	RadioButton* _ch = (RadioButton*)malloc(sizeof(RadioButton));
	_ch->check_button = *check_button_new(parent);
	Button_SetStyle(((Widget*)_ch)->hwnd,BS_AUTORADIOBUTTON,TRUE);
	return _ch;
}
void radio_button_destroy(Widget*)
{
}