#include "ft_header.h"
#include <ncurses.h>

void	put_rectangle(	int ulcorner_x, int ulcorner_y,
			int drcorner_x, int drcorner_y);

void	render_game(t_game *game)
{
	erase();
	put_rectangle(	game->ball_pos[0]-250, game->ball_pos[1]-250,
			game->ball_pos[0]+250, game->ball_pos[1]+250);
	put_rectangle(	game->padl_pos - 1000, MAX_Y - 300,
			game->padl_pos + 1000, MAX_Y - 200);
	move(2, COLS/2);
	printw("%d", game->score);
	refresh();
}

void	put_rectangle(	int ulcorner_x, int ulcorner_y,
			int drcorner_x, int drcorner_y)
{
	int	y;
	
	ulcorner_x = (ulcorner_x / ((MAX_X * 2) / COLS)) + COLS / 2;
	ulcorner_y = (ulcorner_y / ((MAX_Y * 2) / LINES)) + LINES / 2;
	drcorner_x = (drcorner_x / ((MAX_X * 2) / COLS)) + COLS / 2;
	drcorner_y = (drcorner_y / ((MAX_Y * 2) / LINES)) + LINES / 2;
	while (ulcorner_x <= drcorner_x)
	{
		y = ulcorner_y;
		while(y <= drcorner_y)
		{
			mvaddch(y, ulcorner_x, ACS_BLOCK);
			y++;
		}
		ulcorner_x++;
	}
}
