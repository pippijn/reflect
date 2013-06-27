int
(strcmp) (char const *s1, char const *s2)
{
  unsigned char uc1, uc2;

  /* Move s1 and s2 to the first differing characters
   * in each string, or the ends of the strings if they
   * are identical.  */
  while (*s1 != '\0' && *s1 == *s2)
    {
      s1++;
      s2++;
    }
  /* Compare the characters as unsigned char and
   * return the difference.  */
  uc1 = *(unsigned char const *)s1;
  uc2 = *(unsigned char const *)s2;
  return uc1 < uc2 ? -1 : uc1 > uc2;
}
