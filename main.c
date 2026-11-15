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

    window = sfRenderWindow_create(mode, "My Hunter", sfResize | sfClose, NULL);
    if (!window)
        return (84);

    sfRenderWindow_setFramerateLimit(window, 60);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }

        sfRenderWindow_clear(window, sfBlack);
        
        // Dessin des éléments du jeu ici

        sfRenderWindow_display(window);
    }

    sfRenderWindow_destroy(window);
    return (0);
}
