#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <MMsystem.h>
#include "mylib.h"

typedef struct {
	    char name[100];
	    int score;
}highscore;

highscore player[5];

int random(int minN, int maxN) {
	return minN + rand() % (maxN + 1 - minN);
}

void delay(unsigned int mseconds) {
	clock_t goal = mseconds + clock();
	while (goal > clock());
}
 
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool keyPressed() {
	return _kbhit();
}

void getup() {
	system("cls");
	gotoxy(10,1);
	printf("Press Esc to return Menu");
	gotoxy(10,2);
	printf("SCORE : ");
	gotoxy(1,37);
	for(int x=0; x<199; x++)
		printf("Я");
}

int t, scr = 0,speed = 15;
void ds(int jump=0) {
    static int a=1;
    if(jump==0)
        t=0;
    else if(jump==2)
        t--;
    else t++;
    

    gotoxy(5,27-t);
    printf("                    ");gotoxy(2,28-t);
    printf("            ЬЫЯЫЫЫЫЬ");gotoxy(2,29-t);
    printf("            ЫЫЫЫЫЫЫЫ");gotoxy(2,30-t);
    printf("            ЫЫЫЫЫЯЯЯ");gotoxy(2,31-t);
    printf("    Ы      ЬЫЫЫЫЯЯЯ ");gotoxy(2,32-t);
    printf("    ЫЫЬ  ЬЫЫЫЫЫЫЬЬЬ ");gotoxy(2,33-t);
    printf("    ЯЫЫЫЫЫЫЫЫЫЫЫ  Я ");gotoxy(2,34-t);
    printf("      ЯЫЫЫЫЫЫЫЯ     ");gotoxy(2,35-t);
    if(jump==1 || jump==2){
    printf("       ЫЫЯ ЯЫ       ");gotoxy(2,36-t);
    printf("       ЫЬ   ЫЬ      ");
    }
	else if(a==1){
    printf("       ЯЫЫЯ  ЯЯЯ    ");gotoxy(2,36-t);
    printf("         ЫЬ         ");
    a=2;
    }
    else if(a==2){
    printf("        ЯЫЬ ЯЫ      ");gotoxy(2,36-t);
    printf("             ЫЬ     ");
    a=1;
    }
    gotoxy(0,37-t);
    
    if(jump!=0){
        printf("                      ");
    }
    else
    {
         
        printf("ЯЯЯЯЯЯЯЯЯЯЯЯЯЯЯЯЯЯЯЯЯЯ");
    }
    delay(speed);
}


void introboss(){
	int a =1;
	if(a==1){  
	gotoxy(55,9); printf(" ____   ____   _____ _____   _____  _____    _____ ____  __  __ _____ _   _  _____  ");
	gotoxy(55,10); printf("|  _ \\ / __ \\ / ____/ ____| |_   _|/ ____|  / ____/ __ \\|  \\/  |_   _| \\ | |/ ____| ");
	gotoxy(55,11); printf("| |_) | |  | | (___| (___     | | | (___   | |   | |  | | \\  / | | | |  \\| | |  __  ");
	gotoxy(55,12); printf("|  _ <| |  | |\\___  \\___ \\    | |  \\___ \\  | |   | |  | | |\\/| | | | | . ` | | |_ | ");
	gotoxy(55,13); printf("| |_) | |__| |____) |___) |  _| |_ ____) | | |___| |__| | |  | |_| |_| |\\  | |__| | ");
	gotoxy(55,14); printf("|____/ \\____/|_____/_____/  |_____|_____/   \\_____\\____/|_|  |_|_____|_| \\_|\\_____| ");
	a=2; 
}else if(a==2){ 
	gotoxy(55,9); printf("                                                                                           ");
	gotoxy(55,10); printf("                                                                                           ");
	gotoxy(55,11); printf("                                                                                           ");
	gotoxy(55,12); printf("                                                                                           ");
	gotoxy(55,13); printf("                                                                                           ");
	gotoxy(55,14); printf("                                                                                           ");
	a=1; 
}
}

void clear_intro(){
	gotoxy(55,9-t); printf("                                                                                           ");
	gotoxy(55,10-t); printf("                                                                                           ");
	gotoxy(55,11-t); printf("                                                                                           ");
	gotoxy(55,12-t); printf("                                                                                           ");
	gotoxy(55,13-t); printf("                                                                                           ");
	gotoxy(55,14-t); printf("                                                                                           ");
} 

void boss()
{
	SetColor(4);
    gotoxy(142,3-t); 
    printf("                           ЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬ      ");gotoxy(142,4-t);
    printf("                        ЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫ            ");gotoxy(142,5-t);
    printf("                     ЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫ               ");gotoxy(142,6-t);
    printf("                  ЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫ                     ");gotoxy(142,7-t);
    printf("                ЬЫЫЫЫЫЫЫЫЫЫЫЫЫЫ                             ");gotoxy(142,8-t);
    printf("      ЬЬЬЬЬ     ЫЫЫЫЫЫЫЫ                                    ");gotoxy(142,9-t);
    printf("    ЫЯЫЫ      ЫЫЫЫЫЫЫЫЫЫЫЫ                                  ");gotoxy(142,10-t);
    printf("ЬЬЬЬЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЬЬЬЬЬЬЬЬЬЬЬЬ            ");gotoxy(142,11-t);
    printf("ЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫ                        ");gotoxy(142,12-t);
    printf("             ЯЯЯЯЫЫЫЫЫЫЫЯЯЯЯЯЯЯЯ                            ");gotoxy(142,13-t);
    printf("                 ЫЫЫЯЯЯ                                     ");gotoxy(142,14-t);
    printf("                   ЯЯЯЯЯЯ                                   ");
    SetColor(10);
    
}

void moving_boss()
{   
    SetColor(4);
	int x = 155;
	while(x>141){

		gotoxy(x,3-t); 
    	printf("                           ЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬЬ ");gotoxy(x,4-t);
    	printf("                        ЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫ       ");gotoxy(x,5-t);
    	printf("                     ЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫ          ");gotoxy(x,6-t);
    	printf("                  ЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫ                ");gotoxy(x,7-t);
    	printf("                ЬЫЫЫЫЫЫЫЫЫЫЫЫЫЫ                        ");gotoxy(x,8-t);
    	printf("      ЬЬЬЬЬ     ЫЫЫЫЫЫЫЫ                               ");gotoxy(x,9-t);
    	printf("    ЫЯЫЫ      ЫЫЫЫЫЫЫЫЫЫЫЫ                             ");gotoxy(x,10-t);
    	printf("ЬЬЬЬЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЬЬЬЬЬЬЬЬЬЬЬЬ       ");gotoxy(x,11-t);
    	printf("ЬЬЬЬЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫ                   ");gotoxy(x,12-t);
    	printf("             ЯЯЯЯЫЫЫЫЫЫЫЯЯЯЯЯЯЯЯ                       ");gotoxy(x,13-t);
    	printf("                 ЫЫЫЯЯЯ                                ");gotoxy(x,14-t);
    	printf("                   ЯЯЯЯЯЯ                              ");
		x--;
		
		for(int i=25;i<50;i++){
			for(int j=25;j<=26;j++){
				gotoxy(i,j);
				printf(" ");
			}
		}
		Sleep(20);
	}
	SetColor(10);
}


void clear_boss(){
    gotoxy(142,3); 
    printf("                                                             ");gotoxy(142,4);
    printf("                                                             ");gotoxy(142,5);
    printf("                                                             ");gotoxy(142,6);
    printf("                                                             ");gotoxy(142,7);
    printf("                                                             ");gotoxy(142,8);
    printf("                                                             ");gotoxy(142,9);
    printf("                                                             ");gotoxy(142,10);
    printf("                                                             ");gotoxy(142,11);
    printf("                                                             ");gotoxy(142,12);
    printf("                                                             ");gotoxy(142,13);
    printf("                                                             ");gotoxy(142,14);
    printf("                                                             ");
}

bool isEmpty();
void get_high_score();
void initScore();
void check_high_score(int x);
void Title(int selection);
void board_main(int color,int y);
void board_selection();
void key_selection(int key);
void board_game();
void bar_loading();
void play();
void how_to_play();
void high_score();
void draw_menu();
void menu();

void _continue(){
	gotoxy(36,8);
	printf("         ");
	gotoxy (36,9);
	printf("                              ");
}

void clear_obj(){
	for(int i = 0; i < 7;i++){
		gotoxy(19,30+i);
		printf("          ");
	}
}

void obj() {
	static int x=0;
	if(x>=178 && t<5) {
		speed = 20;
		clear_boss();
		clear_intro();
		
		
		gotoxy(36,8);
		printf("Game Over");
		gotoxy (36,9);
		printf("Press Y to continue, N to exit");

		int c = getch();
		if(c == 27){
			system("cls");
			x = 0;scr=0;
			menu();
		} else if(c == 110){
			_continue();
			check_high_score(scr);    
			system("cls"); 
			x = 0;
			scr=0; 
			menu();  
		} else if(c == 121) {
			_continue();
			clear_intro();
			clear_boss();
			clear_obj();
			x= 0;scr = 0;
		}else{
			while(c != 110 && c!= 27 && c!= 121){
				c = getch();
				if(c == 27) {
					system("cls");
					x = 0;scr=0;
					menu();
				} else if(c == 110){
					_continue();  
					check_high_score(scr);
					system("cls");
					x = 0;scr=0;
					menu();  
				} else if(c == 121) {
					_continue();
					clear_intro();
					clear_boss();
					clear_obj();
					x= 0;scr = 0;
				}
			}
		}
	}
			
    gotoxy(194-x,30);
    printf("    ЬЫЫЬ  Ь ");gotoxy(194-x,31);
    printf("   ЬЫЫЫЫЬ ЫЫ ");gotoxy(194-x,32);
    printf(" Ь ЫЫЫЫЫЫЫЫЫ ");gotoxy(194-x,33);
    printf("ЫЫ ЫЫЫЫЫЫ ");gotoxy(194-x,34);
    printf("ЫЫ ЫЫЫЫЫЫ ");gotoxy(194-x,35);
    printf("ЫЫЫЫЫЫЫЫЫ ");gotoxy(194-x,36);
    printf("   ЫЫЫЫЫЫ ");
    x++;	
    if(x == 191)
    {
	    x=0;
	    scr++;
	   	PlaySound("score.wav", NULL, SND_ASYNC);
	    gotoxy(20,2);
	    printf("     ");
	    gotoxy(20,2);
	    printf("%d",scr);
	    if(scr % 10 == 0 && scr > 0 && speed >= 10)
	        speed-= 5;
	}
}

// vat the roi

// chu B bay
void objB(){
    static int y = 0, z = 0;  
    if(z >= 115 && t<5)
    { 	
		speed = 20; 
		clear_boss();
		clear_intro();
		gotoxy(36,8);
		printf("Game Over");
		gotoxy (36,9);
		printf("Press Y to continue, N to exit");

		int c = getch();
		if(c == 27){
			system("cls");
			z = 0;scr=0;
			menu();
		} else if(c == 110){
			_continue();
			check_high_score(scr);
			system("cls"); 
			z = 0;scr=0; 
			menu();  
		} else if(c == 121) {
				_continue();
				clear_intro();
				clear_boss();
				clear_obj();
				z = 0;scr = 0;
		}else{
			while(c != 110 && c!= 27 && c!= 121){
				c = getch();
				if(c == 27) {
					system("cls");
					z = 0;scr=0;
					menu();
				} else if(c == 110){
					_continue();
					check_high_score(scr);
					system("cls");  
					z = 0;scr=0;
					menu();  
				} else if(c == 121) {
					_continue();
					clear_intro();
					clear_boss();
					clear_obj();
					z = 0;scr=0;
				}
			}
		}
    }  
    
    // chu B bay 
    SetColor(4);
    if (y == 22 ) {
    	//system(“cls”);
    	gotoxy(141-z,8+y);
	    printf("       ");gotoxy(141-z,9+y);
	    printf("       ");gotoxy(141-z,10+y);
	    printf("       ");gotoxy(141-z,11+y);
	    printf("       ");gotoxy(141-z,12+y);
	    printf("       " );gotoxy(141-z,13+y);
	    printf("       " );gotoxy(141-z,14+y);
	    
	    
    	gotoxy(135-z,31);
    	printf("       ");gotoxy(135-z,32);
	    printf("ЫЫЫЫЫ  ");gotoxy(135-z,33);
	    printf("Ы    Ы ");gotoxy(135-z,34);
	    printf("ЫЬЬЬЬ  ");gotoxy(135-z,35);
	    printf("Ы    Ы " );gotoxy(135-z,36);
	    printf("ЫЫЫЫЫ " );gotoxy(135-z,37);
		//printf("       ");
	    z++; 
	} else if (y < 22){
		gotoxy(141-z,8+y);
	    printf("       ");gotoxy(141-z,9+y);
	    printf("ЫЫЫЫЫ  ");gotoxy(141-z,10+y);
	    printf("Ы    Ы ");gotoxy(141-z,11+y);
	    printf("ЫЬЬЬЬ  ");gotoxy(141-z,12+y);
	    printf("Ы    Ы ");gotoxy(141-z,13+y);
	    printf("ЫЫЫЫЫ  ");gotoxy(141-z,14+y);
	   // Sleep(10); 
		//printf("       ");
    	y++;
    	z++; 
	}  
	
	if (scr % 10 == 6) {
		gotoxy(141-z,8+y);
	    printf("         ");gotoxy(141-z,9+y);
	    printf("         ");gotoxy(141-z,10+y);
	    printf("         ");gotoxy(141-z,11+y);
	    printf("         ");gotoxy(141-z,12+y);
	    printf("         ");gotoxy(141-z,13+y);
	    printf("         ");gotoxy(141-z,14+y);
	} 
	SetColor(10); 
    if(z==130)
    {
	    y = 0;
	    z = 0; 
	    scr++;
	    PlaySound("score.wav", NULL, SND_ASYNC);
	    gotoxy(20,2);
	    printf("     ");
	    gotoxy(20,2);
	    printf("%d",scr);
	    
	}
}
// chu U bay
void objU(){
    static int y = 0, z = 0;  
    if(z >= 115 && t<5)
    {
		speed = 20; 
		clear_boss();
		clear_intro();
		gotoxy(36,8);
		printf("Game Over");
		gotoxy (36,9);
		printf("Press Y to continue, N to exit");

		int c = getch();
		if(c == 27){
			system("cls");
			z = 0;scr=0;
			menu();
		} else if(c == 110){
			_continue();
			check_high_score(scr);
			system("cls"); 
			z = 0;scr=0; 
			menu();  
		} else if(c == 121) {
				_continue();
				clear_intro();
				clear_boss();
				clear_obj();
				z = 0;scr = 0;
		}else{
			while(c != 110 && c!= 27 && c!= 121){
				c = getch();
				if(c == 27) {
					system("cls");
					z = 0;scr=0;
					menu();
				} else if(c == 110){
					_continue();
					check_high_score(scr);
					system("cls");  
					z = 0;scr=0;
					menu();  
				} else if(c == 121) {
					_continue();
					clear_intro();
					clear_boss();
					clear_obj();
					z = 0;scr=0;
				}
			}
		}
    }  
     
    
    // chu U bay 
    SetColor(4);
    if (y == 22 ) {
    	//system(“cls”);
    	gotoxy(141-z,8+y);
	    printf("       ");gotoxy(141-z,9+y);
	    printf("       ");gotoxy(141-z,10+y);
	    printf("       ");gotoxy(141-z,11+y);
	    printf("       ");gotoxy(141-z,12+y);
	    printf("       " );gotoxy(141-z,13+y);
	    printf("       " );gotoxy(141-z,14+y);
	    
	    
    	gotoxy(135-z,31);
    	printf("      ");gotoxy(135-z,32);
	    printf("Ы    Ы ");gotoxy(135-z,33);
	    printf("Ы    Ы ");gotoxy(135-z,34);
	    printf("Ы    Ы ");gotoxy(135-z,35);
	    printf("Ы    Ы ");gotoxy(135-z,36);
	    printf(" ЫЫЫЫ  " );gotoxy(135-z,37);
		//printf("       ");
	    z++; 
	} else if (y < 22){
		gotoxy(141-z,8+y);
	    printf("       ");gotoxy(141-z,9+y);
	    printf("Ы    Ы ");gotoxy(141-z,10+y);
	    printf("Ы    Ы ");gotoxy(141-z,11+y);
	    printf("Ы    Ы ");gotoxy(141-z,12+y);
	    printf("Ы    Ы ");gotoxy(141-z,13+y);
	    printf(" ЫЫЫЫ  " );gotoxy(141-z,14+y);
	   // Sleep(10); 
		//printf("       ");
    	y++;
    	z++; 
	} 
	SetColor(10);
	if (scr % 10 == 7) {
		gotoxy(141-z,8+y);
	    printf("         ");gotoxy(141-z,9+y);
	    printf("         ");gotoxy(141-z,10+y);
	    printf("         ");gotoxy(141-z,11+y);
	    printf("         ");gotoxy(141-z,12+y);
	    printf("         ");gotoxy(141-z,13+y);
	    printf("        ");gotoxy(141-z,14+y);
	} 
	
    if(z==130)
    {
	    y = 0;
	    z = 0; 
	    scr++;
	    PlaySound("score.wav", NULL, SND_ASYNC);
	    gotoxy(20,2);
	    printf("     ");
	    gotoxy(20,2);
	    printf("%d",scr);
	}
}
// chu G bay 
void objG(){
    static int y = 0, z = 0;  
    if(z >= 115 && t<5)
    {
		speed = 20; 
		clear_boss();
		clear_intro();
		PlaySound(TEXT("dino2.wav"),NULL,SND_ASYNC);
		printf("Game Over");
		gotoxy (36,9);
		printf("Press Y to continue, N to exit");

		int c = getch();
		if(c == 27){
			system("cls");
			z = 0;scr=0;
			menu();
		} else if(c == 110){
			_continue();
			check_high_score(scr);
			system("cls"); 
			z = 0;scr=0; 
			menu();  
		} else if(c == 121) {
				_continue();
				clear_intro();
				clear_boss();
				clear_obj();
			z = 0;scr = 0;
		}else{
			while(c != 110 && c!= 27 && c!= 121){
				c = getch();
				if(c == 27) {
					system("cls");
					z = 0;scr=0;
					menu();
				} else if(c == 110){
					_continue();
					check_high_score(scr);
					system("cls");  
					z = 0;scr=0;
					menu();  
				} else if(c == 121) {
					_continue();
					clear_intro();
					clear_boss();
					clear_obj();
					z = 0;scr=0;
				}
			}
		}
    }  
    
    // chu G bay 
    SetColor(4);
    if (y == 22 ) {
    	//system(“cls”);
    	gotoxy(141-z,8+y);
	    printf("        ");gotoxy(141-z,9+y);
	    printf("        ");gotoxy(141-z,10+y);
	    printf("        ");gotoxy(141-z,11+y);
	    printf("        ");gotoxy(141-z,12+y);
	    printf("        ");gotoxy(141-z,13+y);
	    printf("        ");gotoxy(141-z,14+y);
	    
	    
    	gotoxy(135-z,31);
    	printf("        ");gotoxy(135-z,32);
	    printf(" ЫЫЫЫЫ  ");gotoxy(135-z,33);
	    printf("Ы       ");gotoxy(135-z,34);
	    printf("Ы   ЫЫЫ ");gotoxy(135-z,35);
	    printf("Ы    Ы  ");gotoxy(135-z,36);
	    printf(" ЫЫЫЫ   ");gotoxy(135-z,37);
		//printf("       ");
	    z++; 
	} else if (y < 22){
		gotoxy(141-z,8+y);
	    printf("        ");gotoxy(141-z,9+y);
	    printf(" ЫЫЫЫЫ");gotoxy(141-z,10+y);
	    printf("Ы       ");gotoxy(141-z,11+y);
	    printf("Ы   ЫЫЫ ");gotoxy(141-z,12+y);
	    printf("Ы    Ы  ");gotoxy(141-z,13+y);
	    printf(" ЫЫЫЫ   ");gotoxy(141-z,14+y);
	   // Sleep(10); 
		//printf("       ");
    	y++;
    	z++; 
	}  
	SetColor(10);
	if (scr % 10 == 8) {
		gotoxy(141-z,8+y);
	    printf("         ");gotoxy(141-z,9+y);
	    printf("         ");gotoxy(141-z,10+y);
	    printf("         ");gotoxy(141-z,11+y);
	    printf("         ");gotoxy(141-z,12+y);
	    printf("         ");gotoxy(141-z,13+y);
	    printf("        ");gotoxy(141-z,14+y);
	} 
	
    if(z==130)
    {
	    y = 0;
	    z = 0; 
	    scr++;
	    PlaySound("score.wav", NULL, SND_ASYNC);
	    gotoxy(20,2);
	    printf("     ");
	    gotoxy(20,2);
	    printf("%d",scr);
	}
}
 
//void attack(){
//	static int y = 0;      
//    // tan cong muc tieu  
//	if(y<31){
//		gotoxy(10+6*y,32-y);printf("      ЫЫЫЫЫ");
//		gotoxy(10+6*y,33-y);printf("      Ы ? Ы");
//		gotoxy(10+6*y,34-y);printf("      ЫЬЬЬЬ");
//		gotoxy(10+6*y,35-y);printf("           ");
//	    y++;
//	}
//	gotoxy(10+6*y,2);printf("      ");
//	gotoxy(10+6*y,3);printf("      ");
//	gotoxy(10+6*y,4);printf("      ");
//	gotoxy(10+6*y,5);printf("           "); 
//    if(y==140)
//    {
//	    y = 0;
//	    scr++;
//	    
//	    gotoxy(20,2); 
//	    printf("     ");
//	    gotoxy(20,2);
//	    printf("%d",scr);
//	}	
//}

int bu;
void attack(){
	
	gotoxy(1,12);printf("ЫЫЫЫЫЫ");
	gotoxy(1,13);printf("Ы  ЫЫЫЫЫЫ");
	gotoxy(1,14);printf("ЫЫЫЫЫЫ");
	
	static int y = 0;      
    // tan cong muc tieu  
	if(y<140){
		gotoxy(10+y,12);printf("      ЫЫЫЫЫ");
		gotoxy(10+y,13);printf("      Ы ? Ы");
		gotoxy(10+y,14);printf("      ЫЬЬЬЯ");
	    y++;
	}
	gotoxy(150,12);printf("      ");
	gotoxy(150,13);printf("      ");
	gotoxy(150,14);printf("      ");
    
//    if (scr%10==8){
//    	gotoxy(10+y,12);printf("           ");
//		gotoxy(10+y,13);printf("           ");
//		gotoxy(10+y,14);printf("           ");
//	}

	if(y==140)
    {
	    y = 0;
	    scr++;
	    gotoxy(20,2); 
	    printf("     ");
	    gotoxy(20,2);
	    printf("%d",scr);
	}	
}

void clear_bullet() {
	gotoxy(10+bu,12);printf("           ");
	gotoxy(10+bu,13);printf("           ");
	gotoxy(10+bu,14);printf("           ");
}
void Title(int selection){
	    int i = rand()%15;         
		int x = 65, y = 0;            
	    
		while(!keyPressed()) {
			
			i = (i+1)%15;
			if(i == 0)
		   	   i = 1;
		   
		SetColor(i);
		if(selection == 1){
		gotoxy(116,28);printf("Esc");	
		gotoxy(118,10);printf("HIGH SCORE");		
		}else if(selection == 0){
		gotoxy(116,28);printf("Esc");			
		}
		gotoxy(122,30);printf("Space Vector !");	 
		gotoxy(x, y);
		printf(" ____    ______   __  __  _____       __  __   ______   __  __  ____ ");i++;
		SetColor(i);
		gotoxy(x, y + 1);printf("/\\  _`\\ /\\__  _\\ /\\ \\/\\ \\/\\  __`\\    /\\ \\/\\ \\ /\\__  _\\ /\\ \\/\\ \\/\\  _`\\    ");i++;
		SetColor(i);
		gotoxy(x, y + 2);printf("\\ \\ \\/\\ \\/_/\\ \\/ \\ \\ `\\\\ \\ \\ \\/\\ \\   \\ \\ \\/'/'\\/_/\\ \\/ \\ \\ `\\\\ \\ \\ \\L\\_\\  ");i++;
		SetColor(i);
		gotoxy(x, y + 3);printf(" \\ \\ \\ \\ \\ \\ \\ \\  \\ \\ , ` \\ \\ \\ \\ \\   \\ \\ , <    \\ \\ \\  \\ \\ , ` \\ \\ \\L_L  ");i++;
		SetColor(i);
		gotoxy(x, y + 4);printf("  \\ \\ \\_\\ \\ \\_\\ \\__\\ \\ \\`\\ \\ \\ \\_\\ \\   \\ \\ \\\\`\\   \\_\\ \\__\\ \\ \\`\\ \\ \\ \\/, \\ ");i++;
		SetColor(i);
		gotoxy(x, y + 5);printf("   \\ \\____/ /\\_____\\\\ \\_\\ \\_\\ \\_____\\   \\ \\_\\ \\_\\ /\\_____\\\\ \\_\\ \\_\\ \\____/");i++;
		SetColor(i);
		gotoxy(x, y + 6);printf("    \\/___/  \\/_____/ \\/_/\\/_/\\/_____/    \\/_/\\/_/ \\/_____/ \\/_/\\/_/\\/___/ ");i++;                    
		Sleep(100);
    }
}
// loading game
void bar_loading(){
	for(int i = 110;i<=131;i++){
		for(int j = 9;j<=23;j++){
			gotoxy(i,j);
			printf(" ");
		}
	}
	
	int x = 90, y = 10;
	gotoxy(x,y-1);printf("Loading... ");
	for(int i = 0;i < 25;i++){
		gotoxy(x+i,y);
		printf("%c",177);
	}
	
	int i = 1,x1 = 65, y1 = 0;
	for(int j = 0;j < 25;j++){

		i = (i+1)%15;
		if(i==0)
		   i = 1;
		SetColor(i);
		gotoxy(x1, y1);
		printf(" ____    ______   __  __  _____       __  __   ______   __  __  ____ ");
		gotoxy(x1, y1 + 1);printf("/\\  _`\\ /\\__  _\\ /\\ \\/\\ \\/\\  __`\\    /\\ \\/\\ \\ /\\__  _\\ /\\ \\/\\ \\/\\  _`\\    ");
		gotoxy(x1, y1 + 2);printf("\\ \\ \\/\\ \\/_/\\ \\/ \\ \\ `\\\\ \\ \\ \\/\\ \\   \\ \\ \\/'/'\\/_/\\ \\/ \\ \\ `\\\\ \\ \\ \\L\\_\\  ");
		gotoxy(x1, y1 + 3);printf(" \\ \\ \\ \\ \\ \\ \\ \\  \\ \\ , ` \\ \\ \\ \\ \\   \\ \\ , <    \\ \\ \\  \\ \\ , ` \\ \\ \\L_L  ");
		gotoxy(x1, y1 + 4);printf("  \\ \\ \\_\\ \\ \\_\\ \\__\\ \\ \\`\\ \\ \\ \\_\\ \\   \\ \\ \\\\`\\   \\_\\ \\__\\ \\ \\`\\ \\ \\ \\/, \\ ");
		gotoxy(x1, y1 + 5);printf("   \\ \\____/ /\\_____\\\\ \\_\\ \\_\\ \\_____\\   \\ \\_\\ \\_\\ /\\_____\\\\ \\_\\ \\_\\ \\____/");
		gotoxy(x1, y1 + 6);printf("    \\/___/  \\/_____/ \\/_/\\/_/\\/_____/    \\/_/\\/_/ \\/_____/ \\/_/\\/_/\\/___/ ");
		gotoxy(122,30);printf("Good Luck !   ");	
		
		SetColor(10);
		gotoxy(x+j,y);
		printf("%c",219);
		Sleep(100);
	}
}

bool isEmpty(){
	FILE *fp = fopen("HighScore.txt","r");;
	long size;
	if(fp){
		fseek (fp, 0, SEEK_END);
        size = ftell(fp);
		fclose(fp);
	}
	return(size == 0);
}

void get_high_score(){
	FILE *fp = fopen("HighScore.txt","w");
	for(int i = 0; i < 5; i++){
		fprintf(fp,"%s",player[i].name);
		fprintf(fp," %d\n",player[i].score);
	}
	fclose(fp);
}

void initScore(){
		if (isEmpty()){
			for (int i = 0;i < 5;i++){
			strcpy(player[i].name,"PLAYER");
			player[i].score = 0;
			}
			get_high_score();
		}else{
			char arr[100];
			int count = 0;
			FILE *fp = fopen("HighScore.txt", "r");
			for (int i = 0;i < 5;){
				while (!feof(fp)){
					count++;
					fscanf(fp,"%s",arr);
					if(count%2==1){
						strcpy(player[i].name,arr);	
					}else{
						player[i].score = atoi(arr);	
						i++;
					}					
				}
			}
				get_high_score();
				fclose(fp);	
		}

}

void check_high_score(int _score){
	    initScore();
		char _name[100];
		for(int i = 0; i< 5; i++){
			if(_score > player[i].score){
				PlaySound(TEXT("CheckHighScore.wav"), NULL, SND_ASYNC);
				for(int j = 0; j < 30; j++){
					if(j%2 == 0){
						SetColor(14);
						if(i==0){
							gotoxy(90,9);
							printf("BEST SCORE");
						}else{
							gotoxy(90,9);
							printf("HIGH SCORE");							
						}
					}else{
						SetColor(9);
						if(i==0){
							gotoxy(90,9);
							printf("BEST SCORE");
						}else{
							gotoxy(90,9);
							printf("HIGH SCORE");
					}
				}
				delay(100);	
			}
			   gotoxy(90,9);
			   printf("          ");
			   SetColor(10);
			   gotoxy(90,9);
			   printf("Player :__________");
			   SetColor(4);
			   gotoxy(100,9);
			   scanf("%s",&_name);	
			for(int j = 4; j > i; j--){
				strcpy(player[j].name,player[j-1].name);
				player[j].score = player[j-1].score;
			}
			strcpy(player[i].name,_name);
			player[i].score = _score;	
			break;			
		}
	}
	get_high_score();	
}

void high_score(){
	initScore();
	for(int i = 110;i<=131;i++){
		for(int j = 9;j<=23;j++){
			gotoxy(i,j);
			printf(" ");
		}
	}
	int x = 105, y = 9;
	SetColor(3);
	for(int i = 0;i < 35;i++){
		gotoxy(x+i,y);
		printf("%c",196);
		gotoxy(x+i,y+18);
		printf("%c",196);
	}
	
	for(int i = 0;i<=18;i++){
		gotoxy(x,y+i);
		printf("%c",179);
		gotoxy(x+35,y+i);
		printf("%c",179);
	}
	
	gotoxy(x,y);printf("%c",218);
	gotoxy(x+35,y);printf("%c",191);
	gotoxy(x,y+18);printf("%c",192);
	gotoxy(x+35,y+18);printf("%c",217);
	
	SetColor(10);
	gotoxy(x+6,y+1);printf("| ===< HIGH SCORE >=== |");
    gotoxy(x+5,y+19);printf("Press Esc to return Menu !");
    
	FILE *fp = fopen("HighScore.txt","r");
	char s[100];
	int count=0,y1 = 13;
	int col = 4;
	while(!feof(fp)){
		SetColor(col);
		if(count == 10) break;
		count++;
		fscanf(fp,"%s",s);
		if(count%2==1){
		   gotoxy(113,y1);
		   printf("%s",s);
		   y1++;	
		}else{
		   gotoxy(129,y1-1);
		   printf("%s",s);
		   col=2;
		}
	}
	fclose(fp);
	
	char a = 0;
	while(a!= 27){
		Title(1);
		a = getch();
	}
   
	for(int i = x;i<=x+35;i++){
		for(int j = y;j<=y+19;j++){
			gotoxy(i,j);
			printf(" ");
		}
	}
			
}

void ABOUT(){
	for(int i = 110;i<=131;i++){
		for(int j = 9;j<=23;j++){
			gotoxy(i,j);
			printf(" ");
		}
	} 
	int x = 105, y = 9;
	SetColor(3);
	for(int i = 0;i < 35;i++){
		gotoxy(x+i,y);
		printf("%c",196);
		gotoxy(x+i,y+18);
		printf("%c",196);
	}
	
	
	for(int i = 0;i<=18;i++){
		gotoxy(x,y+i);
		printf("%c",179);
		gotoxy(x+35,y+i);
		printf("%c",179);
	}	

	gotoxy(x,y);printf("%c",218);
	gotoxy(x+35,y);printf("%c",191);
	gotoxy(x,y+18);printf("%c",192);
	gotoxy(x+35,y+18);printf("%c",217);
	 
	int x1 = x + 10;
	
	SetColor(4);
	gotoxy(x1,y+5);printf("Pham Van Manh");
	
	SetColor(10);
	gotoxy(x+7,y+1);printf("==== DINO KING GAME ====");
	gotoxy(x1,y+3);printf("Phan Van Quyen"); 
	gotoxy(x1,y+7);printf("Tran Khanh Phuong");
	gotoxy(x1,y+9);printf("Nguyen Duc Thanh");
	gotoxy(x1,y+11);printf("Luong Duc Manh");
	gotoxy(x1,y+13);printf("Nguyen Viet Tai");
	gotoxy(x+5,y+19);printf("Press Esc to return Menu !");	 
	 
	 
	char a = 0;
	while(a!= 27){
		Title(0);
		a = getch();
	}	

	for(int i = x;i<=x+35;i++){
		for(int j = y;j<=y+19;j++){
			gotoxy(i,j);
			printf(" ");
		}
	}	
}
void how_to_play(){
	for(int i = 110;i<=131;i++){
		for(int j = 9;j<=23;j++){
			gotoxy(i,j);
			printf(" ");
		}
	}
	int x = 105, y = 9;
	SetColor(3);
	for(int i = 0;i < 35;i++){
		gotoxy(x+i,y);
		printf("%c",196);
		gotoxy(x+i,y+18);
		printf("%c",196);
	}
	
	
	for(int i = 0;i<=18;i++){
		gotoxy(x,y+i);
		printf("%c",179);
		gotoxy(x+35,y+i);
		printf("%c",179);
	}	

	gotoxy(x,y);printf("%c",218);
	gotoxy(x+35,y);printf("%c",191);
	gotoxy(x,y+18);printf("%c",192);
	gotoxy(x+35,y+18);printf("%c",217);
	 
	int x1 = x + 10;
	
	SetColor(6);
	gotoxy(x1-2,y+5);printf("You use the SPACEbar");
	gotoxy(x1-3.25,y+7);printf("To control the DINOSAUR");
	
	SetColor(10);
	gotoxy(x+7,y+1);printf("==== DINO KING GAME ====");
	
	gotoxy(x+5,y+19);printf("Press Esc to return Menu !");	 
	 
	 
	char a = 0;
	while(a!= 27){
		Title(0);
		a = getch();
	}	

	for(int i = x;i<=x+35;i++){
		for(int j = y;j<=y+19;j++){
			gotoxy(i,j);
			printf(" ");
		}
	}	
}

//vien game
void board_game(){
	int k,x1 = 50,x2 = 152,y = 0;
	for(int i = 0;i<40;i++){
		k = rand()%15;
		if(k == 0)
		   k = 4;
		SetColor(k);
		gotoxy(x1,y+i);
		printf("%c",219);
		SetColor(k+1);
		gotoxy(x2,y+i);
		printf("%c",219);
	}
}
//hien thi lua chon dang tro toi
void board_main(int color,int y){
	
	int x = 110;
	SetColor(color);
	for(int i = 0;i < 21;i++){
		gotoxy(x+i,y);
		printf("%c",196);
		gotoxy(x+i,y+2);
		printf("%c",196);
	}
	
	for(int i = 0;i<=2;i++){
		gotoxy(x,y+i);
		printf("%c",179);
		gotoxy(x+21,y+i);
		printf("%c",179);
	}
	
	gotoxy(x,y);printf("%c",218);
	gotoxy(x+21,y);printf("%c",191);
	gotoxy(x,y+2);printf("%c",192);
	gotoxy(x+21,y+2);printf("%c",217);
}
// ve bang chon
void board_selection(){
	for(int i = 9;i<= 21;i+=3)
	    board_main(10,i);
}
// hien thi lua chon
void key_selection(int key){
	int x = 115;
	int color = 7;
	if(key == 10){
						
		SetColor(color);
		gotoxy(x-3,13);
		printf("   How to play ?   ");
		gotoxy(x,19);
		printf("    About   ");	
		gotoxy(x-2,16);
		printf("   High Score   ");	
		gotoxy(x,22);
		printf("    Quit   ");		

		SetColor(11);
		gotoxy(x,10);
	    printf(" -> Play <-");
	}
	if(key == 13){
		
		SetColor(color);	
		gotoxy(x,10);
	    printf("    Play   ");
		gotoxy(x-2,16);
		printf("   High Score   ");	
		gotoxy(x,19);
		printf("    About   ");		    
		gotoxy(x,22);
		printf("    Quit   ");
				
		SetColor(11);
		gotoxy(x-2,13);
		printf("-> How to play <-");	
	}
	if(key == 16){

		SetColor(color);
		gotoxy(x,10);
	    printf("    Play   ");
		gotoxy(x-3,13);
		printf("   How to play ?   ");	
		gotoxy(x-2,16);
		printf("   High Score   ");		
		gotoxy(x,19);
		printf("    About   ");	
		gotoxy(x,22);
		printf("    Quit   ");		
		
		SetColor(11);
		gotoxy(x-2,16);
		printf("-> High Score <-");		
	}
	if(key == 19){

		SetColor(color);
		gotoxy(x,10);
	    printf("    Play   ");
		gotoxy(x-3,13);
		printf("   How to play ?   ");		
		gotoxy(x-2,16);
		printf("   High Score   ");	
		gotoxy(x,22);
		printf("    Quit   ");	
		
		SetColor(11);
		gotoxy(x,19);
		printf(" -> About <-");		
	}
	if(key == 22){

		SetColor(color);
		gotoxy(x,10);
	    printf("    Play   ");
		gotoxy(x-3,13);
		printf("   How to play ?   ");		
		gotoxy(x-2,16);
		printf("   High Score   ");	
		gotoxy(x,19);
		printf("    About   ");		
		
		SetColor(11);
		gotoxy(x,22);
		printf(" -> Quit <-");	
	}	
        board_selection();
        board_main(13,key-1);
	
}

void draw_menu() {
    
    board_game();
	int x1 = 62,z=8;
	                         
    SetColor(10);
	gotoxy(x1,z);	printf("     /|");
	gotoxy(x1,z+1);	printf("    / |");
	gotoxy(x1,z+2);	printf("   /  /");
	gotoxy(x1,z+3);	printf("  |   |");
	gotoxy(x1,z+4);	printf(" /    |");
	gotoxy(x1,z+5);	printf(" |    \\_ ");
	gotoxy(x1,z+6);	printf(" |      \\__");
	gotoxy(x1,z+7);	printf(" \\       __\\_______");
	gotoxy(x1,z+8);	printf("  \\                 \\_");
	gotoxy(x1,z+9);	printf("  | /                 \\ ");
	gotoxy(x1,z+10);printf("  \\/                   \\");
	gotoxy(x1,z+11);printf("   |                    |");
	gotoxy(x1,z+12);printf("   \\                   \\|");
	gotoxy(x1,z+13);printf("    |                   \\ ");
	gotoxy(x1,z+14);printf("    \\                    |");
	gotoxy(x1,z+15);printf("   /\    \\_                \\ ");
	gotoxy(x1,z+16);printf("  / |      \\__ (   )       \\ ");
	gotoxy(x1,z+17);printf(" /  \\      / |\\\\\  /       __\\___");
	gotoxy(x1,z+18);printf(" |  ,     |  /\\ \\ \\__    |      \\__");
	gotoxy(x1,z+19);printf(" \\_/|\\___/   \\   \\}}}\\__|  (@)     )");
	gotoxy(x1,z+20);printf("  \\)\\)\\)      \\_\\---\\   \\|       \\ \\ ");
	gotoxy(x1,z+21);printf("                \\>\\>\\>   \\   /\\__o_o)");
	gotoxy(x1,z+22);printf("                          | /  VVVVV                     oh ");
	gotoxy(x1,z+23);printf("                          \\ \\    \\                _____ /   ");
	gotoxy(x1,z+24);printf("                           \\ \\MMMMM              |  O O|    ");
	gotoxy(x1,z+25);printf("                            \\______/            /___|_|/\\_  ");
	gotoxy(x1,z+26);printf("                                            ==( |         | ");
	gotoxy(x1,z+27);printf("   _____________________________________________(o)====(o)_______________  ");
	SetColor(4);
	gotoxy(90,27);printf("@");
	 
	SetColor(10);
	board_selection();
	
    char a = NULL ;
    int key = 10;
    while(a != 13){
	key_selection(key);
	Title(2);
	    a = getch();
		if(a == -32) {
			a = getch();
			if(a != 13) {
				if(a == 80 && key != 22) {
					key+=3;
				} else if(a == 80 && key == 22) {
					key = 10;
				} else if(a == 72 && key != 10) {
					key-=3;
				} else if(a == 72 && key == 10) {
					key = 22;
				}
			}
		}		     	
	}
	
	if(key == 10 ){
		SetColor(10);
       	bar_loading();
		play();
	}else if(key == 13){
		how_to_play();
	}else if(key == 16){
		high_score();
	}else if(key == 19){
		ABOUT();
        
	}else if(key == 22){
//		SetColor(10);
//		system("cls");
//		int x = 0;
//		while(x<=100) {
//			gotoxy(90,12);
//			printf("Dang thoat %d%c",x,37);
//			x++;
//			delay(15);
//		}
//	    gotoxy(90,12);
//		printf("Dang thoat 100%c",37);
//		delay(1000);
//		gotoxy(90,12);
//		printf("See you again !");
//		delay(1000);
		exit(1);		
	}

}

void menu() {
	PlaySound(TEXT("Feeling.wav"), NULL, SND_ASYNC);
	while(1){
		
		draw_menu();	
	}	
}

void play() {
	PlaySound(TEXT("start.wav"),NULL, SND_ASYNC);
	
	SetColor(10);
	scr = 0;
	int i,r, o = 0, z = 0;
	char ch; 
	getup();
	
	while(true)
    { 
	   if (scr %10 == 0 || scr % 10 == 1 || scr % 10 == 2 || scr % 10 == 3 || scr % 10 == 4 || scr % 10 == 9) {
	   		 while(!kbhit())
	        {
	            ds();
	            obj();
	            if(scr % 30 >= 2 && scr % 30 <= 3 ){
            		introboss(); 
					o = 0;  	
			    }
                else if(o == 0 && scr % 30 == 4) {
	                clear_intro();
	            	moving_boss();
	            	o = 1; 
                } else if (scr % 30 == 29) {
                	clear_boss();
//					PlaySound("AttackSoundEffect.wav", NULL, SND_ASYNC);
				}
				else if(scr % 30 != 1 && scr % 30 != 0) boss(); 
	        }
	        ch=getch();
	        if(ch==' ')
	        {
	        	PlaySound("jump.wav", NULL, SND_ASYNC);
	        	for(i=0;i<20;i++)
		            {
		            	ds(1); 
			           	obj();
		            	 
		            }
		            for(i=0;i<20;i++)
		            {
		            	ds(2);
		            	obj(); 
		            }
	    	} else if (ch==27) {
				system("cls");
				menu();
			}
			
	    }
	   	else if (scr % 10 == 5) {
		   	while(!kbhit())
	        {
	            ds();
	            objB();
	            boss(); 
	        }
	        ch=getch();
	        if(ch==' ')
	        {
	        	PlaySound("jump.wav", NULL, SND_ASYNC);
	        	for(i=0;i<20;i++)
		            {
		            	ds(1); 
			           	objB();	 
		            }
		            for(i=0;i<20;i++)
		            {
		            	ds(2);
		            	objB(); 
		            }
		    } else if (ch==27) {
				system("cls");
				menu();
				}
	   	}
	   	else if (scr % 10 == 6) {
	   			while(!kbhit())
		        {
		            ds();
		            objU();
		            boss(); 
		             
		        }
		        ch=getch();
		        if(ch==' ')
		        {
		            PlaySound("jump.wav", NULL, SND_ASYNC);
		        	for(i=0;i<20;i++)
			        {
			           	ds(1); 
			        	objU();	 
		            }
			        for(i=0;i<20;i++)
			        {
			           	ds(2);
			           	objU(); 
			        }
			    } else if (ch==27) {
					system("cls");
					menu();
				}
		}
	   	else if (scr % 10 == 7) {
	   			while(!kbhit())
		        {
		            ds();
		            objG();	 
					boss();            
		        }
		        ch=getch();
		        if(ch==' ')
		        {
		    	    PlaySound("jump.wav", NULL, SND_ASYNC);    	
		        	for(i=0;i<20;i++) 
			            {
			            	ds(1); 
				           	objG();	 
			            }
			            for(i=0;i<20;i++)
			            {
			            	ds(2);
			            	objG(); 
			            }
			    } else if (ch==27) {
					system("cls");
					menu();
				}
		}
	   	else if (scr % 30 == 8 || scr % 30 == 18 || scr % 30 == 28 ) {
	   			while(!kbhit())   
	        {
	        	attack();
	            ds();
	            obj(); 
	            boss(); 
	             
	        }
	        ch=getch();
	        if(ch==' ')
	        {
	    	    PlaySound("jump.wav", NULL, SND_ASYNC);
	        	for(i=0;i<20;i++)
		            {
		            	ds(1); 
						obj();	 
		            }
		            for(i=0;i<20;i++)
		            {
		            	ds(2);
						obj(); 
				 
		            }
		    } else if (ch==27) {
				system("cls");
				menu();
			}
		} 
	} 
}

int main() {

	SetConsoleTitle("DinoKing!");
//	SetConsoleOutputCP(65001);
	system("mode con: lines=40 cols=200");
	ShowCur(0);

	menu();



	
	return 0;   

}
