/* internal helper macros */

#define INDENT(fh, n)                           \
  do {                                          \
    int i;                                      \
                                                \
    for (i = 0; i < n; i++)                     \
      fputc(' ', fh);                           \
  } while (0)
