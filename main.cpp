#include <iostream>
#include "Files.hpp"

int main(void)
{
  void	*dir = NULL;
  char *file = NULL;

  if (!(dir = Files::first(".", &file)))
    return (0);
  if (Files::isFile(file))
    std::cout << "first : " << file << std::endl;
  while (file = Files::next(dir))
    if (Files::isFile(file))
      std::cout << "next : " << file << std::endl;
  Files::close(dir);
  return (0);
}
