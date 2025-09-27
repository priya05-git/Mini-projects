#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#define MAX_WORD 50
#define MAX_TRIES 6
struct WORDHINT
{
    char word[MAX_WORD];
    char hint[MAX_WORD];
};
void display(const char word[],const bool guessed[]);
void drawHangman(int tries);
int main()
{
    srand(time(NULL));
    struct WORDHINT wordlist[]={{"elephant","A large mammal with a trunk"},
    {"pizza","A popular italian dish"},
    {"beach","Sandy shore by the sea"},
    {"guitar","A musical instrument"},
    {"oscar","A prestigious award"}
};
int wordIndex=rand()%4;
const char* secretword=wordlist[wordIndex].word;
const char* hint=wordlist[wordIndex].hint;
int wordlength=strlen(secretword);
char guessedword[MAX_WORD]={0};
bool guessedletters[26]={false};
printf("Welcome to Hangman!\n");
printf("Hint:%s\n",hint);
int tries=0;
while (tries<MAX_TRIES)
{
    printf("\n");
    display(guessedword,guessedletters);
    drawHangman(tries);
    char guess;
    printf("Enter a letter:");
    scanf("%c",&guess);
    guess=tolower(guess);
    if(guessedletters[guess -'a']){
        printf("You've already guessed that letter."   " Try again.\n");
        continue;
    }
guessedletters[guess -'a']=true;
bool found=false;
for (int i = 0; i < wordlength; i++)
{
    if (secretword[i]==guess)
    {
        found=true;
        guessedword[i]=guess;
    }
}
if (found){
    printf("Good guess\n");
}
else{
    printf("sorry,the letter '%c' is not in the"      "word\n",      guess);
    tries++;
}
if(strcmp(secretword,guessedword)==0){
    printf("\nCongratulations! You've guessed the"                 "word:%s\n",secretword);
    break;
}
}
if (tries>=MAX_TRIES)
{
    printf("\nSorry,you've run out of tries. The word"       "was:%s\n",secretword);
}
return 0;
}
void display(const char word[], const bool guessed[])
{
    printf("Word: ");
    for (int i = 0; word[i] != '\0'; i++) {
        if (guessed[word[i] - 'a']) {
            printf("%c ", word[i]);
        }
        else {
            printf("_ ");
        }
    }
    printf("\n");
}

void drawHangman(int tries)
{
    const char* hangmanParts[]
        = { "     _________",    "    |         |",
            "    |         O",   "    |        /|\\",
            "    |        / \\", "    |" };

    printf("\n");
    for (int i = 0; i <= tries; i++) {
        printf("%s\n", hangmanParts[i]);
    }
}
