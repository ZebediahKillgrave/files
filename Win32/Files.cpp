#if defined(_WIN32) || defined(__WIN32__)

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstring>
#include <cstddef>
#include <windows.h>
#include "Files.hpp"

void	*Files::first(const char *dirname, char **filename)
{
  void			*dir = NULL;
  WIN32_FIND_DATA	handle;
  char *name = new char[strlen(dirname) + 3];

  memcpy(name, dirname, strlen(dirname));
  memcpy(name + strlen(dirname), "/*", 2);
  if ((dir = FindFirstFile(name, &handle)) == INVALID_HANDLE_VALUE)
    return (NULL);
  *filename = new char[256];
  memcpy(*filename, handle.cFileName, 256);
  return (dir);
}

char *Files::next(void *dir)
{
  char			*filename = new char[256];
  WIN32_FIND_DATA	handle;

  if (FindNextFile(dir, &handle) == 0)
    return (NULL);
  memcpy(filename, handle.cFileName, 256);
  return (filename);
}

bool	Files::close(void *dir)
{
  bool	closed = false;

  closed = (FindClose(dir) != 0);
  return (closed);
}

bool    Files::isFile(const char *filename)
{
  struct _stat buff;

  _stat(filename, &buff);
  return (S_ISREG(buff.st_mode));
}

#endif
