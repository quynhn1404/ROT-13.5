#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void addValue(char * word);
void readIn();
int main()
{
    int numWords;

    scanf("%d", &numWords);
    for(int i=0; i < numWords; i++)
    {
        //Read in values
       readIn();
    }

    return 0;
}
void readIn()
{
    char theWord[100 + 1];
    scanf("%s", theWord);

    addValue(theWord);
    printf("%s\n", theWord);

}
void addValue(char * word)
{
    int numericValue,i;
    for(i=0; i< strlen(word); i++)
        {
            //move 14 letters for the letter after a vowel
           if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
        {
            //transform the vowels
            numericValue= word[i] +13;
            //if the value is over 123, subtract to get back to the beginning of the latin alphabet
            if(numericValue >= 123)
                {
                   numericValue-= 26;
                }
                word[i]= numericValue;
                //increment to the next index

                i++;
                //check if the next index is at the end of the word
                if(word[i]!= '\0')
                {
                //transform the char after the vowel by 14 letters
                numericValue= word[i] + 14;
             if(numericValue >= 123)
                {
                   numericValue-= 26;
                }
            //assign the new value to the char next to the vowel
            word[i] = numericValue;
                }
                else
                    return;
           }
            else
            {
                numericValue= word[i] + 13;
                if(numericValue >= 123)
                {
                   numericValue-= 26;
                }

                word[i]= numericValue;
            }


        }

}
