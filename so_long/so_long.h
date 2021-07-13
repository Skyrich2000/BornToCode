#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct		s_list
{
	void			*data;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct		s_sprite
{
	char			*path;
	int				width;
	int				height;
}					t_sprite;

t_sprite	*create_sprite(char *path);

void		draw_sprite(t_sprite *spr, int subimg, int x, int y);

void		draw();

#endif
