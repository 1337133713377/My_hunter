/*
** EPITECH PROJECT, 2026
** My Hunter
** File description:
** Creates and destroys the game, moves and animates the plane
*/

#include <stdlib.h>
#include "my_hunter.h"

static sfSprite *new_sprite(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

int create_game(game_t *game)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};

    game->window = sfRenderWindow_create(mode, "My Hunter", sfClose, NULL);
    game->bg_texture = sfTexture_createFromFile("assets/background.png", 0);
    game->plane_texture = sfTexture_createFromFile("assets/plane.png", 0);
    game->font = sfFont_createFromFile("assets/font.ttf");
    if (!game->window || !game->bg_texture || !game->plane_texture
        || !game->font)
        return 84;
    sfRenderWindow_setFramerateLimit(game->window, 60);
    game->background = new_sprite(game->bg_texture);
    game->plane = new_sprite(game->plane_texture);
    game->clock = sfClock_create();
    game->text = sfText_create();
    sfText_setFont(game->text, game->font);
    update_score(game);
    respawn(game);
    return 0;
}

void destroy_game(game_t *game)
{
    sfText_destroy(game->text);
    sfFont_destroy(game->font);
    sfClock_destroy(game->clock);
    sfSprite_destroy(game->plane);
    sfTexture_destroy(game->plane_texture);
    sfSprite_destroy(game->background);
    sfTexture_destroy(game->bg_texture);
    sfRenderWindow_destroy(game->window);
}

void respawn(game_t *game)
{
    sfVector2f start = {-PLANE_SIZE, rand() % (HEIGHT - PLANE_SIZE)};

    sfSprite_setPosition(game->plane, start);
}

void move_plane(game_t *game)
{
    sfIntRect rect = {game->frame * PLANE_SIZE, 0, PLANE_SIZE, PLANE_SIZE};

    sfSprite_setTextureRect(game->plane, rect);
    sfSprite_move(game->plane, (sfVector2f){SPEED, 0});
    if (sfSprite_getPosition(game->plane).x > WIDTH)
        respawn(game);
    if (sfTime_asSeconds(sfClock_getElapsedTime(game->clock)) > 0.1) {
        game->frame = (game->frame + 1) % 3;
        sfClock_restart(game->clock);
    }
}
