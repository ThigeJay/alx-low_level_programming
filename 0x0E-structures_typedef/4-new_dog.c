#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - Computes the length of a given string.
 * @str: The string to be measured.
 *
 * Return: The length of the string.
 */
int _strlen(char *str)
{
	int length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}

	return (length);
}

/**
 * *_strcpy - Copies the source string to the destination buffer.
 * @destination: The destination buffer where the string is to be copied.
 * @source: The source string to copy.
 *
 * Return: A pointer to the destination buffer.
 */
char *_strcpy(char *destination, char *source)
{
	int str_len, idx;

	str_len = 0;
	while (source[str_len] != '\0')
	{
		str_len++;
	}

	for (idx = 0; idx < str_len; idx++)
	{
		destination[idx] = source[idx];
	}
	destination[idx] = '\0';

	return (destination);
}

/**
 * new_dog - Creates a new dog structure and initializes its members.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 *
 * Description: Allocates memory for the dog structure and its members,
 * and initializes them with the provided values.
 * Return: A pointer to the new dog structure, or NULL if it fails.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog_obj;
	int name_len, owner_len;

	name_len = _strlen(name);
	owner_len = _strlen(owner);

	dog_obj = malloc(sizeof(dog_t));
	if (dog_obj == NULL)
		return (NULL);

	dog_obj->name = malloc(sizeof(char) * (name_len + 1));
	if (dog_obj->name == NULL)
	{
		free(dog_obj);
		return (NULL);
	}
	dog_obj->owner = malloc(sizeof(char) * (owner_len + 1));
	if (dog_obj->owner == NULL)
	{
		free(dog_obj);
		free(dog_obj->name);
		return (NULL);
	}
	_strcpy(dog_obj->name, name);
	_strcpy(dog_obj->owner, owner);
	dog_obj->age = age;

	return (dog_obj);
}
