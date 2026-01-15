#include <stdio.h>
#include <conio.h>
#include <windows.h>

int x=40,y=12, foodx=10, foody=5;
int score=0, gameover=0;
int dir=0; // 1=left,2=right,3=up,4=down

void draw() {
    system("cls");
    printf("Score: %d\n", score);

    for(int i=0;i<20;i++) {
        for(int j=0;j<60;j++) {
            if(i==0 || i==19 || j==0 || j==59)
                printf("#");
            else if(i==y && j==x)
                printf("O");
            else if(i==foody && j==foodx)
                printf("F");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void input() {
    if(kbhit()) {
        switch(getch()) {
            case 'a': dir=1; break;
            case 'd': dir=2; break;
            case 'w': dir=3; break;
            case 's': dir=4; break;
            case 'x': gameover=1; break;
        }
    }
}

void logic() {
    if(x==foodx && y==foody) {
        score+=10;
        foodx = rand()%50+5;
        foody = rand()%15+2;
    }

    switch(dir) {
        case 1: x--; break;
        case 2: x++; break;
        case 3: y--; break;
        case 4: y++; break;
    }

    if(x<=0 || x>=59 || y<=0 || y>=19)
        gameover=1;
}

int main() {
    while(!gameover) {
        draw();
        input();
        logic();
        Sleep(100);
    }

    printf("\nGame Over! Final Score: %d\n", score);
    return 0;
}
