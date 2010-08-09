#include <strutil.h>

static char chars[255][5];

static void
init_chars (void)
{
  unsigned char c;
  static bool initialised = false;
  if (initialised)
    return;

  g_trace ("initialising flyweight string representations of characters");

  for (c = 0; c < UCHAR_MAX; c++)
    {
      int i = 0;
      chars[c][i++] = '\'';
      if (c == '\\' || c == '\'')
        chars[c][i++] = '\\';
      chars[c][i++] = c;
      chars[c][i++] = '\'';
    }

  initialised = true;
}

char const *
char_to_string (char c)
{
  init_chars ();
  return chars[(unsigned char)c];
}
