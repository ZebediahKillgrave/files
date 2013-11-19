#ifndef FILES_HPP_
# define FILES_HPP_

class Files
{
public:
  static void		*open(const char *);
  static const char	*next(void *);
  static bool		close(void *);
};

#endif /* FILES_HPP_ */
