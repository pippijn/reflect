/* strcpy */
char *
(strcpy) (char * s1, const char * s2)
{
  char *dst = s1;
  const char *src = s2;
  /* Do the copying in a loop.  */
  while ((*dst++ = *src++) != '\0')
    ;
  /* Return the destination string.  */
  return s1;
}
