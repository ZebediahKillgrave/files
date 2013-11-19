#if defined(linux) || defined(__linux)

#include <cstring>
#include <cstddef>
#include <sys/types.h>
#include <dirent.h>
#include "Files.hpp"

void	*Files::open(const char *dirname)
{
  void	*dir = NULL;

  dir = (void *) opendir(dirname);
  return (dir);
}

const char *Files::next(void *dir)
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

#endif
