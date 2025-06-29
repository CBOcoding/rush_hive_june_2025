#ifndef GET_NEXT_LINE_WORDLE_H
# define GET_NEXT_LINE_WORDLE_H

//----------------------------------------------------------------------------------
// Library Headers
//----------------------------------------------------------------------------------

# include "wordle.h"

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

//----------------------------------------------------------------------------------
// Macro Definitions
//----------------------------------------------------------------------------------

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//----------------------------------------------------------------------------------
// Function Prototypes
//----------------------------------------------------------------------------------

char	*ft_fill_line_gnl(int fd, char *line, t_wordle *wordle);
char	*ft_next_line_gnl(char *line, t_wordle *wordle);
char	*ft_remaining_line_gnl(char *line, t_wordle *wordle);
char	*ft_strchr_gnl(char *string, int c);
char	*ft_strjoin_gnl(char *str1, char *buffer, t_wordle *wordle);
size_t	ft_strlen_gnl(char *s);
char	*get_next_line(int fd, t_wordle *wordle);

#endif
