#if defined(_WIN32) || defined(__WIN32__)

#include <cstring>
#include <cstddef>
#include <windows.h>
#include "Files.hpp"

void	*Files::first(const char *dirname, char **filename)
{
  void			*dir = NULL;
  WIN32_FIND_DATA	handle = NULL;

  if ((dir = FindFirstFile(dirname, &handle)) == INVALID_HANDLE_VALUE)
    return (NULL);
  *filename = new char[256];
  memcpy(*filename, handle.cFileName, 256);
  return (dir);
}

char *Files::next(void *dir)
{
  char			*filename = new char[256];
  WIN32_FIND_DATA	data = NULL;

  if (FindNextFile(dirname, &handle) == 0)
    return (NULL);
  memcpy(filename, handle.cFileName, 256);
  return (filename);
}

bool	Files::close(void *dir)
{
  bool	closed = false;

  closed = (FindFree(dir) != 0);
  return (closed);
}

#endif
