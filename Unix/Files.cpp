#if defined(linux) || defined(__linux)

#include <cstring>
#include <cstddef>
#include <sys/types.h>
#include <dirent.h>
#include "Files.hpp"

void	*Files::first(const char *dirname, char **filename)
{
  void	*dir = NULL;
  void	*handle = NULL;

  if (!(dir = (void *) opendir(dirname)) || !(handle = readdir((DIR *)dir)))
    return (NULL);
  if (((struct dirent *)handle)->d_type != DT_REG)
    return (Files::next(dir));
  *filename = new char[256];
  memcpy(*filename, ((struct dirent *)handle)->d_name, 256);
  return (dir);
}

char *Files::next(void *dir)
{
  char	*filename = new char[256];
  void		*handle = NULL;

  if (!(handle = readdir((DIR *)dir)))
    return (NULL);
  if (((struct dirent *)handle)->d_type != DT_REG)
    return (Files::next(dir));
  memcpy(filename, ((struct dirent *)handle)->d_name, 256);
  return (filename);
}

bool	Files::close(void *dir)
{
  bool	closed = false;

  closed = (closedir((DIR *)dir) == 0);
  return (closed);
}

bool    Files::isFile(const char *filename)
{
  struct stat buff;

  stat(filename, &buff);
  return (S_ISREG(buff.st_mode));
}

#endif
