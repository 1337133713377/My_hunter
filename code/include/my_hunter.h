/*
** EPITECH PROJECT, 2026
** My Hunter
** File description:
** Constants, game state and shared functions
*/

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_

    #include <SFML/Graphics.h>

    #define WIDTH 800
    #define HEIGHT 600
    #define PLANE_SIZE 110
    #define SPEED 4
    #define HELP "USAGE\n    ./my_hunter [-h]\n\nDESCRIPTION\n" \
        "    Shooting game: fighter jets fly across the screen, shoot them\n" \
        "    down to raise your score.\n\nUSER INPUTS\n" \
        "    Mouse click on a jet     shoot it (+1 score)\n" \
        "    Close the window         quit the game\n" \
        "    -h                       display this help\n"

typedef struct game_s {
    sfRenderWindow *window;
    sfTexture *bg_texture;
    sfSprite *background;
    sfTexture *plane_texture;
    sfSprite *plane;
    sfClock *clock;
    sfFont *font;
    sfText *text;
    int frame;
    int score;
} game_t;

int create_game(game_t *game);
void destroy_game(game_t *game);
void respawn(game_t *game);
void move_plane(game_t *game);
void update_score(game_t *game);

#endif
