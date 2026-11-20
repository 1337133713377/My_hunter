/*
** EPITECH PROJECT, 2026
** My Hunter
** File description:
** Handles -h, the clicks, the score and the game loop
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "my_hunter.h"

void update_score(game_t *game)
{
    char str[] = "Score: 0000";
    int n = game->score;
    int i = 10;

    while (i > 6) {
        str[i] = '0' + n % 10;
        n /= 10;
        i--;
    }
    sfText_setString(game->text, str);
}

static void shoot(game_t *game, sfMouseButtonEvent click)
{
    sfFloatRect box = sfSprite_getGlobalBounds(game->plane);

    if (sfFloatRect_contains(&box, click.x, click.y)) {
        game->score++;
        update_score(game);
        respawn(game);
    }
}

static void handle_events(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtMouseButtonPressed)
            shoot(game, event.mouseButton);
    }
}

static void game_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        handle_events(game);
        move_plane(game);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, game->background, NULL);
        sfRenderWindow_drawSprite(game->window, game->plane, NULL);
        sfRenderWindow_drawText(game->window, game->text, NULL);
        sfRenderWindow_display(game->window);
    }
}

int main(int ac, char **av)
{
    game_t game = {0};
    int status = 0;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h'
        && av[1][2] == '\0') {
        write(1, HELP, sizeof(HELP) - 1);
        return 0;
    }
    srand(time(NULL));
    status = create_game(&game);
    if (status == 0)
        game_loop(&game);
    destroy_game(&game);
    return status;
}
