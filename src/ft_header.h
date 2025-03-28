#ifndef FT_HEADER_H
# define FT_HEADER_H

# define MAX_X 16000
# define MAX_Y (MAX_X * LINES / COLS)

typedef struct s_game
{
	int	score;
	int	padl_pos;
	int	ball_pos[2];
	int	ball_vel[2];
} t_game;

t_game	*start_game(t_game *game);
void	render_game(t_game *game);
void	update_game(t_game *game, int utime);

#endif
