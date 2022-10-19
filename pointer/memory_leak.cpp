// guess the position of queen
// 100$ cash initially
// win: + 3*bet        lose: - bets
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cash = 100;
void Play(int bet){
    char*C = (char*)malloc(3*sizeof(char)); // C++: char *C = new char[3];
    C[0] = 'J';
    C[1] = 'Q';
    C[2] = 'K';
    //static: char C[3] = {'J', 'Q', 'K'};
    printf("Shuffling ...\n");
    // srand(time_t(NULL));  // seeding random number generator
    for (int i=0; i<5; i++){
        int x = rand() % 3;  // x,y: position
        int y = rand() % 3;  // % 3: guarantee x and y are between [0,2]
        int tmp = C[x];
        C[x] = C[y];
        C[y] = tmp;  // swap characters at position x and y
    }
    int players_guess;
    printf("What is the positon of queen - 1, 2 or 3?\n");
    scanf("%d", &players_guess);
    if (C[players_guess-1] == 'Q'){
        cash += 3*bet;
        printf("You win! Result = \"%c %c %c\" Total Cash = %d\n", C[0], C[1], C[2], cash);
    }
    else{
        cash -= bet;
        printf("You lose! Result = \"%c %c %c\" Total Cash = %d\n", C[0], C[1], C[2], cash);
    }
    free(C);
}
int main(){
    int bet;
    printf("Welcome to the Virtual Casino\n");
    printf("Total cash = $%d\n", cash);
    while(cash > 0){
        printf("What is your bet? $");
        scanf("%d", &bet);
        if (bet==0 || bet>cash) break;
        Play(bet);
        printf("\n**********************************\n");
    }
}
