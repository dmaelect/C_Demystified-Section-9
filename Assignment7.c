/*
 Date:    08/24/17
 Description:
// Section 9 Strings, assignment 7:
// A multi word string is input through the keyboard and a single word from the
// string itself is also taken from the user. For example a string entered is
//"She sells sea shells at the sea shore of pacific sea coast".
// Write a C program to find the number of words "Sea" that appear in a given string.
 */

#include <stdio.h>
#include <conio.h>	// for clrscr() function
#include <string.h>
// #include <iostream>

// using namespace std;

int compare(const char*,const char*);
int WordCount(const char* str);
int ExtractCompare(char *strMulti, char *strWod, char *strSingle);


int main(int argc, char* argv[])
{

	char single_string[80];         //-- holds a single string extracted from the multi string
	char multi_string[80];      	//-- holds the multi word string from the user
	char word[80];                  //-- temp array to hold a word string

	int i = 0;      				//-- misc counter
	int j = 0;                      //-- misc counter
	int numberOfWords = 0;          //-- total number of words counted
	int compareGoodCount = 0;		//-- the number of words that matched the test word
									//-- input from the user

	puts("Enter a multi word string:");
	fgets(multi_string, 79, stdin);

	//-- fgets will leaves the '\n' in the string from the user input and this
	//-- is needed to get rid of it
	multi_string[(strlen(multi_string)) - 1] = '\0';

	puts("Enter one word from the previous multi word string:");
	fgets(single_string, 79, stdin);

	//-- fgets will leaves the '\n' in the string from the user input and this
	//-- is needed to get rid of it
	single_string[(strlen(single_string)) - 1] = '\0';

	numberOfWords = WordCount(multi_string);

	printf("\nnumber of words in string = %d\n", WordCount(multi_string));

	//-- Extract each word from multi string and compare it to the test word
	for(i = 0; i < numberOfWords; i++) // , j++
	{
		compareGoodCount += ExtractCompare(multi_string, word, single_string);
	}


	printf("number of words in string that match = %d\n", compareGoodCount);

	getch();
	return 0;
}//-- end Main -------------------------------------------

int compare(const char* ptr1, const char* ptr2)
{
    while (*ptr1 != '\0')
    {
        if (*ptr1 == *ptr2)
        {
            ptr1++;
            ptr2++;
        }
        else return *ptr2 - *ptr1;
    }
        return *ptr2 - *ptr1;
}//-- end compare -----------------------------------------

int WordCount(const char* str)
{
	int i = 0;
	int spaces = 0;
	while (str[i] != '\0') {
		if (str[i] == 32) // equal to space
		{
			spaces++;
		}
		i++;
	}

return spaces + 1;			// this is the number of words
//	numberOfWords = numberofspaces + 1;
}//-- End WordCount-----------------------------------------


int ExtractCompare(char *strMulti, char *strWord, char *strSingle )
{
	int compareGoodCount = 0;
	static int j = 0;           //-- this is strMulti[] ellement positon
	int q = 0;     				//-- reset the strWord ellement position
	//-- extract next word from multi_string into word one char at a time.
	while( strMulti[j] != ' ' && strMulti[j] != '\0')
	{
		strWord[q++] = strMulti[j++];
	}
	strWord[q] = '\0';          //-- terminate the new word by placeing NULL
								//-- at the last word copied.

	//-- compare the latest multi_string word via "word" to "single_word"
	if (compare(strSingle, strWord) == 0) {
		compareGoodCount++;     //-- increment counter
	}

	j++;           				//-- increment past the space in the string

return compareGoodCount;
}//-- end ExtractCompare ----------------------------------
