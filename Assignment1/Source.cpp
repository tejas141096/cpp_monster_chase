#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>

struct Monster
{
	char* monsterName;
	int* monsterX;
	int* monsterY;
};



int main()
{
	//INPUTS
	//Getting number of monsters from user
	printf("Enter number of monsters: ");
	unsigned int* numberOfMonsters = new unsigned int(0);
	scanf_s("%d", &(*numberOfMonsters));
	printf("Number of monsters = %d\n", *numberOfMonsters);


	//Dynamically allocate memory for monster names
	Monster* monsters = new Monster[*numberOfMonsters];
	if (monsters == NULL)
	{
		printf("Memory cant be allocated for monster names");
	}

	/*char** monsters = (char**)malloc(sizeof(char*) * (*numberOfMonsters));
	if (monsters == NULL)
	{
		printf("Memory cant be allocated for monster names");
	}*/
	//Store size of each name
	int* monsterNameSize = new int[*numberOfMonsters];
	if (monsterNameSize == NULL)
	{
		printf("Memory cant be allocated for monster name size");
	}
	//Dynamically allocate memory for monster x coordinates
	int* monsterX = new int[*numberOfMonsters];
	if (monsterX == NULL)
	{
		printf("Memory cant be allocated for monster X-coordinates");
	}
	//Dynamically allocate memory for monster y coordinates
	int* monsterY = new int[*numberOfMonsters];
	if (monsterY == NULL)
	{
		printf("Memory cant be allocated for monster y-coordinates");
	}



	char* charInput = new char;
	int* sizeOfName = new int;
	
	for (unsigned int i = 0; i < *numberOfMonsters; i++)
	{
		gets_s(monsters[i].monsterName,);
		monsters[i].monsterName = (char*)malloc(sizeof(char));
		if (monsters[i].monsterName == NULL)
		{
			printf("Memory cant be allocated for monster names");
		}
		monsterNameSize[i] = 1;
		printf("Enter name of monster %d: ", i);
		while (getchar()=='\n');
		while (*charInput != '\n')
		{
			*charInput = getchar();
			*monsters[i].monsterName = (char)realloc(monsters[i].monsterName, monsterNameSize[i] + 1);
			monsters[i].monsterName[*monsterNameSize-1] = *charInput;
			monsterNameSize[i]++;
		}
		printf("Size = %d\n", monsterNameSize[i]);
		monsters[i].monsterName[monsterNameSize[i] - 1] = '\0';
		printf("\n");
	}

	for (int i = 0; i < *numberOfMonsters; i++)
	{
		printf("%p", *monsters);
		for (int j = 0; j < monsterNameSize[i]; j++)
		{
			printf("%c", monsters[i].monsterName[j]);
		}
		printf("\n");
	}

	delete sizeOfName;
	delete charInput;
	delete[] monsterY;
	delete[] monsterX;
	delete[] monsterNameSize;
	for (unsigned int i = 0; i < *numberOfMonsters; i++)
	{
		delete[] monsters;
	}
	//delete[] monsters;
	return 0;
}