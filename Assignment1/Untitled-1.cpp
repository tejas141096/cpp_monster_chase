#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

// Player class
class Player
{
private:
    char *name;
    int x;
    int y;

public:
    Player() {}
    ~Player() {}

    void set(char *s)
    {
        name = s;
        x = 0;
        y = 0;
    }
    void print()
    {
        for (size_t i = 0; i < strlen(name); i++)
        {
            printf("%c", name[i]);
        }
        printf(": [ %d , %d ]\n", x, y);
        printf("%d", strlen(name));
    }
};

class Monster
{
private:
    char *name;
    int x;
    int y;

public:
    Monster() {}
    ~Monster() {}

    void set(char *s)
    {
        name = s;
        x = rand() % 101;
        y = rand() % 101;
    }
    void print()
    {
        for (size_t i = 0; i < strlen(name); i++)
        {
            printf("%c", name[i]);
        }
        printf(": [ %d , %d ]\n", x, y);
        printf("%d", strlen(name));
    }
};

int main()
{
    // Setup Player
    char *playerName = new char;
    char *c = new char;
    size_t *nameSize = new size_t;
    *nameSize = 1;
    printf("Enter player name: ");
    while (*c != '\n')
    {
        scanf("%c", &(*c));
        if (*c == '\n')
            break;
        playerName = (char *)realloc(playerName, (*nameSize) + 1);
        playerName[(*nameSize) - 1] = *c;
        playerName[(*nameSize)] = '\0';
        (*nameSize)++;
    }
    
    Player *player = new Player();
    player->set(playerName);
    player->print();
    delete playerName;
    delete c;
    delete nameSize;

    // Setup Monsters
    unsigned int *numberOfMonsters = new unsigned int();
    printf("Enter number of monsters: ");
    scanf("%d", &(*numberOfMonsters));
    printf("Number of monsters: %d\n", *numberOfMonsters);
    Monster *monsters = new Monster[*numberOfMonsters];
    for (size_t i = 0; i < *numberOfMonsters; i++)
    {
        char *monsterName = new char;
        char *c = new char;
        size_t *nameSize = new size_t;
        *nameSize = 1;
        printf("Enter monster %d name: ", i + 1);
        fflush(stdin);
        while (*c != '\n')
        {
            scanf("%c", &(*c));
            if (*c == '\n')
                break;
            monsterName = (char *)realloc(monsterName, (*nameSize) + 1);
            monsterName[(*nameSize)] = '\0';
            monsterName[(*nameSize) - 1] = *c;
            (*nameSize)++;
        }
        
        monsters[i].set(monsterName);
        monsters[i].print();
        delete monsterName;
        delete c;
        delete nameSize;
    }

    

    return 0;
}