#include "ft_header.h"
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


int	main(int argc, char **argv)
{
	t_game *game;
	WINDOW *wind;
	int	count;
	const struct timespec duration = {0, 100000000};

	game = start_game(NULL);
	if(!game)
		return(0);
	game->score = 0;
	wind = initscr();
	if(!wind)
		goto clean;
	cbreak();
	curs_set(0);
	noecho();
	nodelay(wind, 1);
	keypad(wind, 1);
	mouseinterval(0);
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
	if(argc > 1)
		count = 10 * atoi(argv[1]);
	else
		count = 10 * 10;
	while(count--){
		update_game(game, 100);
		render_game(game);
		nanosleep(&duration,  NULL);
	}
	endwin();
	delwin(wind);
clean:
	free(game);
}
