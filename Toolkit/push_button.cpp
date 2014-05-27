#include"push_button.h"

extern HINSTANCE hInstance;

PushButton* push_button_new(Widget* parent)
{
	PushButton* b = (PushButton*)malloc(sizeof(PushButton));
	b->widget = *widget_new(parent);
	b->text = (wchar_t*)malloc(sizeof(wchar_t)*6);
	b->text=L"Button";
	b->widget.hwnd = CreateWindow( L"BUTTON", b->text,  WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,0,0,100,100,((Widget*)parent)->hwnd,NULL,hInstance,NULL);
	push_button_set_text(b,b->text);
	return b;
}

void push_button_get_ideal_size(PushButton* _b,Rect* _r)
{
	SIZE size;
	Button_GetIdealSize(((Widget*)_b)->hwnd,&size);
	_r->height=size.cy;
	_r->width=size.cx;
}

void push_button_get_text(PushButton* _b,wchar_t* text)
{
	text = (wchar_t*)malloc(sizeof(wchar_t)*wcslen(text));
	text = _b->text;
}

int push_button_get_text_length(PushButton* _b)
{
	return GetWindowTextLength(((Widget*)_b)->hwnd);
}
void push_button_get_text_margin(PushButton* _b,Rect* _r)
{
	RECT r;
	Button_GetTextMargin(((Widget*)_b)->hwnd,&r);
	_r->height = r.bottom-r.top;
	_r->width = r.right-r.left;
	_r->x=r.left;
	_r->y=r.top;
}
void push_button_set_text(PushButton* _b,wchar_t* text)
{
	_b->text=text;
	SetWindowText(((Widget*)_b)->hwnd,text);
}
void push_button_set_text_margin(PushButton* _b,Rect* _r)
{
}
void push_button_destroy(PushButton* _b)
{
}