#if defined(_WIN32) || defined(__WIN32__)

#include <unistd.h>
#include <windows.h>
#include "Files.hpp"

void	*Files::open(const char *filename)
{
}

void	*Files::next(void *handle, const char *sym)
{
}

bool	Files::close(void *handle)
{
}

#endif
