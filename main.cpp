#include <iostream>
#include "Files.hpp"

int main(void)
{
  void	*dir = NULL;
  char *file = NULL;

  if (!(dir = Files::first("aze", &file)))
    return (0);
  std::cout << "first : " << file << std::endl;
  while (file = Files::next(dir))
    std::cout << "next : " << file << std::endl;
  Files::close(dir);
  return (0);
}
