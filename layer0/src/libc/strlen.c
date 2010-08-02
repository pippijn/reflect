size_t
(strlen) (char const *s)
{
  char const *p = s;

  /* Loop over the data in s.  */
  while (*p != '\0')
    p++;
  return (size_t)(p - s);
}
