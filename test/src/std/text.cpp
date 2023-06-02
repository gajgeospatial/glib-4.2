#include "src/glib_src.h"

u_int32 glib_language = LANGUAGE_DEFAULT;

void glibSetLanguage(u_int32 lang)
{
	glib_language = lang;
}

inline Text glibCreateText(char * str, ARGB font, ARGB back)
{
	Text t;
	t.str = str;
	t.font = font;
	t.back = back;
	return t;
}

void glibDrawText(Image im, Point pos, Text text)
{
	EX_DrawText(im, pos, text.str, -1, text.font, text.back);
}

w_char glibConvertCharacter(char c)
{
	if (glib_language & LANGUAGE_ENGLISH)
		if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
			return (w_char)(c);

	if (glib_language & LANGUAGE_RUSSIAN)
	{
		if (c >= '�' && c <= '�' || c >= '�' && c <= '�')
			return (w_char)(c + 1104);
		if (c == '�') return L'�';
		if (c == '�') return L'�';
	}

	return (w_char)(c);
}

void glibConvertString(char * c, w_char * buf)
{
	while (*c != 0)
		*buf++ = glibConvertCharacter(*c++);
	*buf = 0;
}

u_int strlen(char * ptr)
{
	u_int len = 0;
	while (*ptr++) len++;
	return len;
}

u_int strlen(w_char * ptr)
{
	u_int len = 0;
	while (*ptr++) len++;
	return len;
}
