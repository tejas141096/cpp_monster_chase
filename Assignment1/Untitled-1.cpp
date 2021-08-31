#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

class Player
{
private:
    char *name;
    int *x;
    int *y;
public:
    Player(char *s)
    {
        name = s;
        x=0;
        y=0;
    }
    ~Player() {}
    void printName()
    {
        printf("Name: ");
        for (size_t i = 0; i < strlen(name); i++)
        {
            printf_s("%c", name[i]);
        }
        printf("\n");
        printf("x: %d",x);
        printf("y: %d",y);
    }
};

// Player::Player()
// {
// }
// // Player::Player(char s[])
// // {
// //     for (size_t i = 0; i < strlen(*s); i++)
// //     {
// //         printf_s("%c", s[i]);
// //     }
// // }
// Player::~Player()
// {
// }

int main()
{
    // printf("Hello world!");
    char *playerName = new char;
    char *c = new char;
    size_t size = 1;
    printf("Enter player name: ");
    while (*c != '\n')
    {
        scanf("%c", c);
        playerName = (char *)realloc(playerName, size + 1);
        playerName[size - 1] = *c;
        size++;
    }
    playerName[size] = '\0';

    Player *player = new Player(playerName);
    // player->name = playerName;
    player->printName();
    return 0;
}