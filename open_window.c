/*
** EPITECH PROJECT, 2024
** open_window
** File description:
** open a window
*/

#include "include/mycsfml.h"

void handle_event(sfEvent event, sfRenderWindow *window)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed ||
            (event.type == sfEvtKeyPressed &&
            event.key.code == sfKeySpace))
            sfRenderWindow_close(window);
    }
}

void destroy_texture(sfRenderWindow *window, sfTexture *texture,
    sfSprite *sprite)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);

}

int display_window(sfRenderWindow *window, sfTexture *texture,
    sfSprite *sprite, sfEvent event)
{
    while (sfRenderWindow_isOpen(window)) {
        handle_event(event, window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    destroy_texture(window, texture, sprite);
    return 0;
}

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    sfTexture *texture = sfTexture_createFromFile("assets/background_sea.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfEvent event;

    sfSprite_setTexture(sprite, texture, sfTrue);
    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    if (!window)
       return EXIT_FAILURE;
    if (!texture)
        return EXIT_FAILURE;
    display_window(window, texture, sprite, event);
    return EXIT_SUCCESS;
}
