#ifndef FILES_HPP_
# define FILES_HPP_

class Files
{
public:
  static void		*first(const char *, char **);
  static char		*next(void *);
  static bool		close(void *);
};

#endif /* FILES_HPP_ */
