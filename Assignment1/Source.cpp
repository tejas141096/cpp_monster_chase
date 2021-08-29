#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
	//Getting number of monsters from player
	unsigned int numberOfMonsters;
	scanf_s("%d", &numberOfMonsters);
	printf("%d", numberOfMonsters);


	//Dynamically allocate memory for monster names
	char** monsters = new char* [numberOfMonsters];
	//Dynamically allocate memory for monster x coordinates
	int* monsterX = new int[numberOfMonsters];
	//Dynamically allocate memory for monster y coordinates
	int* monsterY = new int[numberOfMonsters];


	//Getting names for monster from player
	char* charInput = new char;
	for (int i = 0; i < numberOfMonsters; i++)
	{

		//printf("%u", sizeof(monsters[i]));
	}
	return 0;
}