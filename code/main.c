/*
** EPITECH PROJECT, 2026
** My Hunter
** File description:
** main.c 
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *bg_texture;
    sfSprite *bg_sprite;

    window = sfRenderWindow_create(mode, "My Hunter", sfResize | sfClose, NULL);
    if (!window)
        return (84);

    sfRenderWindow_setFramerateLimit(window, 60);
    bg_texture = sfTexture_createFromFile("assets/background.png", NULL);
    if (!bg_texture)
        return (84);
    bg_sprite = sfSprite_create();
    sfSprite_setTexture(bg_sprite, bg_texture, sfTrue);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }

        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, bg_sprite, NULL);
        sfRenderWindow_display(window);
    }

    sfSprite_destroy(bg_sprite);
    sfTexture_destroy(bg_texture);
    sfRenderWindow_destroy(window);
    return (0);
}
