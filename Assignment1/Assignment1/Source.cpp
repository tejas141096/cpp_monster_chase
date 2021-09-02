#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

//Player class
class Player
{
private:
	char* playerName = nullptr;
	int playerX = 0;
	int playerY = 0;

public:
	Player() {}
	~Player() {}

	void set(char* s)
	{
		playerName = s;
		playerX = 0;
		playerY = 0;
	}

	void print()
	{
		printf("Player - ");
		for (size_t i = 0; i < strlen(playerName); i++)
		{
			printf("%c", playerName[i]);
		}
		printf(": [ %d , %d ]\n", playerX, playerY);
		//printf("%d", strlen(name));
	}

	void playerMovement(char direction)
	{
		if (direction == 'w')
			playerY += 1;
		if (direction == 's')
			playerY -= 1;
		if (direction == 'a')
			playerX -= 1;
		if (direction == 'd')
			playerX += 1;
	}
};

//Monster class
class Monster
{
private:
	char* monsterName = nullptr;
	int monsterX = 0;
	int monsterY = 0;

public:
	Monster() {}
	~Monster() {}

	void set(char* s)
	{
		monsterName = s;
		monsterX = (rand() % 100) - 50;
		monsterY = (rand() % 100) - 50;
	}

	void print()
	{
		printf("Monster - ");
		for (size_t i = 0; i < strlen(monsterName); i++)
		{
			printf("%c", monsterName[i]);
		}
		printf(": [ %d , %d ]\n", monsterX, monsterY);
		//printf("%d", strlen(name));
	}

	void monsterMovement()
	{
		monsterX += (rand() % 10) - 5;
		monsterY += (rand() % 10) - 5;
	}
};

int main()
{
	//Setup Player
	Player* player = new Player();
	{
		char* playerName = new char();
		char* c = new char();
		size_t* nameSize = new size_t;
		*nameSize = 1;
		printf("Enter player name: ");
		while (*c != '\n')
		{
			scanf_s("%c", &(*c), 1);
			if (*c == '\n')
				break;
			playerName = (char*)realloc(playerName, (*nameSize) + 1);
			if (playerName != NULL)
			{
				playerName[(*nameSize) - 1] = *c;
				playerName[(*nameSize)] = '\0';
				(*nameSize)++;
			}

		}

		//Print Player
		player->set(playerName);
		player->print();
	}

	//Setup and Print Monsters
	unsigned int* numberOfMonsters = new unsigned int();
	printf("Enter number of monsters: ");
	scanf_s("%d", &(*numberOfMonsters));
	printf("Number of monsters: %d\n", *numberOfMonsters);
	Monster* monsters = new Monster[*numberOfMonsters];
	(void)getchar();
	for (size_t i = 0; i < *numberOfMonsters; i++)
	{
		char* monsterName = new char();
		char* c = new char();
		size_t* nameSize = new size_t;
		*nameSize = 1;
		printf("Enter monster %d name: ", i + 1);

		while (*c != '\n')
		{
			scanf_s("%c", &(*c), 1);
			if (*c == '\n')
				break;
			monsterName = (char*)realloc(monsterName, (*nameSize) + 1);
			if (monsterName != NULL)
			{
				monsterName[(*nameSize) - 1] = *c;
				monsterName[(*nameSize)] = '\0';
				(*nameSize)++;
			}
		}

		monsters[i].set(monsterName);
		monsters[i].print();
	}

	{
		char movement;
		do
		{
			printf("Enter 'wasd' for movement direction. Enter 'q' to quit.\n");
			movement = _getch();
			//printf("%c\n", movement);
			if (movement == 'q')
			{
				break;
			}
			player->playerMovement(movement);
			player->print();
			for (size_t i = 0; i < *numberOfMonsters; i++)
			{
				monsters[i].monsterMovement();
				monsters[i].print();
			}
		} while (movement != 'q');
	}

	player->print();
	for (size_t i = 0; i < *numberOfMonsters; i++)
	{
		monsters[i].print();
	}



	return 0;
}
