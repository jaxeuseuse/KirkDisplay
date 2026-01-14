#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define IMAGE_COUNT 15

void opener(char *images[], int n);
void player(char *song);

int main() {
    
    char *images[IMAGE_COUNT] = 
    {
        "/Applications/KirkDisplay/kirk/kirk0.jpeg",
        "/Applications/KirkDisplay/kirk/kirk1.jpeg",
        "/Applications/KirkDisplay/kirk/kirk2.jpeg",
        "/Applications/KirkDisplay/kirk/kirk3.jpeg",
        "/Applications/KirkDisplay/kirk/kirk4.jpeg",
        "/Applications/KirkDisplay/kirk/kirk5.jpeg",
        "/Applications/KirkDisplay/kirk/kirk6.jpeg",
        "/Applications/KirkDisplay/kirk/kirk7.jpeg",
        "/Applications/KirkDisplay/kirk/kirk8.jpeg",
        "/Applications/KirkDisplay/kirk/kirk9.jpeg",
        "/Applications/KirkDisplay/kirk/kirk10.jpeg",
        "/Applications/KirkDisplay/kirk/kirk11.jpeg",
        "/Applications/KirkDisplay/kirk/kirk12.jpeg",
        "/Applications/KirkDisplay/kirk/kirk13.jpeg",
        "/Applications/KirkDisplay/kirk/kirk14.jpeg",
    };

    player("/Applications/KirkDisplay/kirk/wearekirk.mp3");
    opener(images, IMAGE_COUNT);

    return 0;
}

void opener(char *images[], int n)
{
    for (int i = 0; i < n; i++)
    {
        char cmd [512];
        snprintf(cmd, sizeof(cmd), "open -a Preview %s", images[i]);
        system(cmd);
        usleep(300000);
    }
}
void player(char *song)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        execlp("afplay","musichitsmesohard", song, (char*) NULL);
    }
}