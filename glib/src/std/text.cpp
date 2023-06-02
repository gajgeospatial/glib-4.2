#include "src/glib_src.h"

u_int32 glib_language = LANGUAGE_DEFAULT;

void glibSetLanguage(u_int32 lang)
{
	glib_language = lang;
}

void glibDrawText(Image im, int32 x, int32 y, char * str, u_int32 format)
{
	//============================================================
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
