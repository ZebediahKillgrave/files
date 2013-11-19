#include <iostream>
#include "Files.hpp"

int main(void)
{
  void	*dir;
  const char *file;

  dir = Files::open(".");
  while (file = Files::next(dir))
    std::cout << file << std::endl;
  Files::close(dir);
  return (0);
}
