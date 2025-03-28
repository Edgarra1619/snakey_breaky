#include "ft_header.h"
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>



t_game	*start_game(t_game* game)
{
	if(!game)
		game = (t_game*) malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->ball_pos[0] = 0;
	game->ball_pos[1] = 0;
	game->ball_vel[0] = 8000;
	game->ball_vel[1] = 2000;
	game->padl_pos = 0;
	return (game);
}

//milliseconds
void	update_game(t_game *game, int mtime)
{
	int	e;
	MEVENT	mouse;
	//take care of input
	while ((e = getch()) != ERR)
	{
		if(e & KEY_MOUSE || e & KEY_MOVE)
		{
			if(getmouse(&mouse) != ERR)
			{
				game->padl_pos = 2 * (mouse.x - COLS / 2) * (MAX_X / COLS);
			}
		}
	}
	
	game->ball_pos[0] += game->ball_vel[0] * mtime / 1000;
	game->ball_pos[1] += game->ball_vel[1] * mtime / 1000;
	if(game->ball_pos[0] >= MAX_X && game->ball_vel[0] > 0)
	{
		game->ball_vel[0] *= -1;
		game->ball_pos[0] = MAX_X * 2 - game->ball_pos[0];
	}
	else if(game->ball_pos[0] <= -MAX_X && game->ball_vel[0] < 0)
	{
		game->ball_vel[0] *= -1;
		game->ball_pos[0] = MAX_X * -2 - game->ball_pos[0];
	}

	if (game->ball_pos[1] >= MAX_Y)
	{
		game->score = 0;
		start_game(game);
	}
	else if (game->ball_pos[1] <= -MAX_Y)
	{
		game->ball_vel[1] *= -1;
		game->ball_pos[1] = MAX_Y * -2 - game->ball_pos[1];
	}
	if(	game->ball_pos[1] >= MAX_Y - 550 &&
		game->ball_pos[1] <= MAX_Y &&
		game->ball_pos[0] >= game->padl_pos - 1250 &&
		game->ball_pos[0] <= game->padl_pos + 1250)
	{
		//game->ball_vel[0] -= 2000 - abs(game->ball_pos[1] - game->padl_pos[1]);
		game->ball_vel[1] *= -1;
		//game->ball_vel[1] -= game->ball_pos[1] - game->padl_pos[1];
		game->ball_pos[1] = MAX_Y - 1000;
	}

}
