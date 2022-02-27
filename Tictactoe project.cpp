#include <stdio.h>
#include <stdlib.h>


void welcome (){																	//welcome message
	int ent;
	printf("Welcome To Project Tic-Tac-Toe, please press enter to proceed to game\n");		
	scanf("[^\n]",ent);
	return;
}

void reset (char *con,int *pos){													//reset function
	system("cls");
	printf("initiating reset\n");
	for(int i = 0 ; i < 12 ; i++){
		pos[i]=0;
	}
	con[1]='1', con[2]='2', con[3]='3', con[4]='4', con[5]='5',
	con[6]='6', con[7]='7', con[8]='8', con[9]='9';

}

void winprint(char con[12], int play, int bot){
	system("cls");
	printf("=====================================\n");
	printf("|          |           |            |\n");
	printf("|    %c     |     %c     |     %c      |\n",con[1],con[2],con[3]);
	printf("|          |           |            |\n");
	printf("=====================================\n");
	printf("|          |           |            |\n");
	printf("|    %c     |     %c     |     %c      |\n",con[4],con[5],con[6]);
	printf("|          |           |            |\n");
	printf("=====================================\n");
	printf("|          |           |            |\n");
	printf("|    %c     |     %c     |     %c      |\n",con[7],con[8],con[9]);
	printf("|          |           |            |\n");
	printf("=====================================\n");
}

void printer (char con[12], int play, int bot){										//display module
	system("cls");
	printf("=====================================\n");
	printf("|          |           |            |\n");
	printf("|    %c     |     %c     |     %c      |\n",con[1],con[2],con[3]);
	printf("|          |           |            |\n");
	printf("=====================================\n");
	printf("|          |           |            |\n");
	printf("|    %c     |     %c     |     %c      |\n",con[4],con[5],con[6]);
	printf("|          |           |            |\n");
	printf("=====================================\n");
	printf("|          |           |            |\n");
	printf("|    %c     |     %c     |     %c      |\n",con[7],con[8],con[9]);
	printf("|          |           |            |\n");
	printf("=====================================\n");
	
	if(bot == 0){
		if(play==1){
			printf("Player1's Turn\n"); 
			printf("please choose a spot by typing the number then press enter\n");	
		}
		else if(play==2){
			printf("Player2's Turn\n"); 
			printf("please choose spot\n");	
			printf(">>");
		}
	}
	
	if(bot == 1){
		if(play==1)printf("Bot's Turn\n");
		else if(play==2){
			printf("Player2's Turn\n"); 
			printf("please choose spot\n");	
			printf(">>");
		}
	}
	
	if(bot == 2){
		if(play==1){
			printf("Player1's Turn\n"); 
			printf("please choose spot\n");	
			printf(">>");
		}
		else if(play==2)printf("Bot's Turn\n");
	}
	
	return;
}

int winchecker(int pos[12]){														//win checker module
	int win=0;
	int cnt=0;
	if(pos[1]==1 && pos[2]==1 && pos[3]==1){
		return 1;
	}else if(pos[4]==1 && pos[5]==1 && pos[6]==1){
		return 1;
	}else if(pos[7]==1 && pos[8]==1 && pos[9]==1){
		return 1;
	}else if(pos[1]==1 && pos[4]==1 && pos[7]==1){
		return 1;
	}else if(pos[2]==1 && pos[5]==1 && pos[8]==1){
		return 1;
	}else if(pos[3]==1 && pos[6]==1 && pos[9]==1){
		return 1;
	}else if(pos[1]==1 && pos[5]==1 && pos[9]==1){
		return 1;
	}else if(pos[3]==1 && pos[5]==1 && pos[7]==1){
		return 1;
	}
	
	else if(pos[1]==2 && pos[2]==2 && pos[3]==2){
		return 2;
	}else if(pos[4]==2 && pos[5]==2 && pos[6]==2){
		return 2;
	}else if(pos[7]==2 && pos[8]==2 && pos[9]==2){
		return 2;
	}else if(pos[1]==2 && pos[4]==2 && pos[7]==2){
		return 2;
	}else if(pos[2]==2 && pos[5]==2 && pos[8]==2){
		return 2;
	}else if(pos[3]==2 && pos[6]==2 && pos[9]==2){
		return 2;
	}else if(pos[1]==2 && pos[5]==2 && pos[9]==2){
		return 1;
	}else if(pos[3]==2 && pos[5]==2 && pos[7]==2){
		return 2;
	}
	
	for(int i = 1 ; i <=9 ; i++){
		if(pos[i]==0) cnt++;
	} 
	
	if(cnt==0)return 3;
	
	else return 0;		
}

int usebot (){																		//bot on/off
	int bot,tru=0;
	system("cls");
	while(tru==0){
		printf("use bot ? (0 = no | 1 = bot player 1 | 2 = bot player 2)\n");
		printf(">> ");
		scanf("%d",&bot);
		system("cls");
		if(bot == 0) return 0;
		if(bot == 1) return 1;
		if(bot == 2) return 2;
		else printf("enter the correct input\n");
	}
	
}

int nextplayer(int play){
	if(play==1) return 2;
	else if(play==2) return 1;
}

int botplay (char *con, int *pos, int play, int bot){
	int move,ply;
	int fin=0, cnt=0, sct=0;
	
	if (bot==1)ply=2;
	else if (bot==2)ply=1;
	
	//bot disadvantage
	
	for(int i=1 ; i<=3 ; i++){
		cnt=0;
		if(pos[i]==ply)cnt++;	
		if(pos[i+3]==ply)cnt++;
		if(pos[i+6]==ply)cnt++;

		if(cnt==2)sct=i;
	}
	
	if(sct!=0){
//		printf("V(%d) danger\n",sct);
		if(pos[sct]==0)return sct;	
		else if(pos[sct+3]==0)return sct+3;
		else if(pos[sct+6]==0)return sct+6;
	}
	
	sct=0;
	for(int i=1 ; i<=7 ;){
		cnt=0;
		if(pos[i]==ply)cnt++;	
		if(pos[i+1]==ply)cnt++;
		if(pos[i+2]==ply)cnt++;
		
		if(cnt==2)sct=i;
		i+=3;
	}
	if(sct!=0){
//		printf("H(%d) danger\n",sct);
		if(pos[sct]==0)return sct;	
		else if(pos[sct+1]==0)return sct+1;
		else if(pos[sct+2]==0)return sct+2;
	}
	
	sct=0;
	if(sct==0){
		cnt=0;
		if(pos[1]==ply)cnt++;	
		if(pos[5]==ply)cnt++;
		if(pos[9]==ply)cnt++;

		if(cnt==2){
//			printf("D(%d) danger\n",sct);
			if(pos[1]==0)return 1;	
			else if(pos[5]==0)return 5;
			else if(pos[9]==0)return 9;
		}
		
		cnt=0;
		if(pos[3]==ply)cnt++;	
		if(pos[5]==ply)cnt++;
		if(pos[7]==ply)cnt++;
		
		if(cnt==2){
			printf("D(%d) danger\n",sct);
			if(pos[3]==0)return 3;	
			else if(pos[5]==0)return 5;
			else if(pos[7]==0)return 7;
		}
	}
	
	//bot advantage
	for(int i=1 ; i<=3 ; i++){
		cnt=0;
		if(pos[i]==bot)cnt++;	
		if(pos[i+3]==bot)cnt++;
		if(pos[i+6]==bot)cnt++;

		if(cnt==2)sct=i;
	}
	
	if(sct!=0){
//		printf("V(%d) danger\n",sct);
		if(pos[sct]==0)return sct;	
		else if(pos[sct+3]==0)return sct+3;
		else if(pos[sct+6]==0)return sct+6;
	}
	
	sct=0;
	for(int i=1 ; i<=7 ;){
		cnt=0;
		if(pos[i]==bot)cnt++;	
		if(pos[i+1]==bot)cnt++;
		if(pos[i+2]==bot)cnt++;
		
		if(cnt==2)sct=i;
		i+=3;
	}
	if(sct!=0){
//		printf("H(%d) advantage\n",sct);
		if(pos[sct]==0)return sct;	
		else if(pos[sct+1]==0)return sct+1;
		else if(pos[sct+2]==0)return sct+2;
	}
	
	sct=0;
	if(sct==0){
		cnt=0;
		if(pos[1]==bot)cnt++;	
		if(pos[5]==bot)cnt++;
		if(pos[9]==bot)cnt++;

		if(cnt==2){
//			printf("D(%d) advantage\n",sct);
			if(pos[1]==0)return 1;	
			else if(pos[5]==0)return 5;
			else if(pos[9]==0)return 9;
		}
		
		cnt=0;
		if(pos[3]==bot)cnt++;	
		if(pos[5]==bot)cnt++;
		if(pos[7]==bot)cnt++;
		
		if(cnt==2){
//			printf("D(%d) advantage\n",sct);
			if(pos[3]==0)return 3;	
			else if(pos[5]==0)return 5;
			else if(pos[7]==0)return 7;
		}
	}
	
	while(fin==0){
		move = rand () %9+1;
		if(move<=9||move>=1){
			if(pos[move]==0){
				return move;
			}
		}	
	}
	
}

void playermove (char *con, int *pos, int play, int bot){
	int move;
	int fin=0;
	
	while(fin==0){
		if(bot==0){
			scanf("%d",&move);
			getchar();		
		}
		else if(bot==1 && play==1){
			move = botplay(con,pos,play,bot);
		}
		else if(bot==2 && play==2){
			move = botplay(con,pos,play,bot);
		}
		else if(bot==1 && play==2){
			scanf("%d",&move);
			getchar();
		}
		else if(bot==2 && play==1){
			scanf("%d",&move);
			getchar();
		}
		
		if(move>9||move<1){
			printf("can't use this spot, please pick other spot\n");
		}
		else if(pos[move]!=0){
			printf("spot taken, please pick other spot\n");
		}else{
			pos[move]=play;
			if(play==1)con[move]='X';
			if(play==2)con[move]='O';
			return;
		}
	}	
}

void windisplay(int win,int bot){
	if(bot==0){
		if(win==1)printf("Player 1 Wins\n");
		if(win==2)printf("Player 2 Wins\n");
		if(win==3)printf("Tie\n");
	}else if(bot == 1){
		if(win==1)printf("Bot Wins\n");
		if(win==2)printf("Player 2 Wins\n");
		if(win==3)printf("Tie\n");
	}else if(bot == 2){
		if(win==1)printf("Player 1 Wins\n");
		if(win==2)printf("Bot Wins\n");
		if(win==3)printf("Tie\n");
	}
}
	
int retry(int end){
	while(end==0){
		printf("do you want to retry ? (0 = No | 1 = yes)\n");
		printf(">>");
		scanf("%d",&end);
		getchar();
		system("cls");
		if(end==0) return 1;
		else if(end==1) return 0;
		else{
			printf("please enter a valid answer\n");
			end=0;
		}
	}
	
}

int main (){																		//main unit
	int bot=0, play=1, end=0, win=0;
	int pos [12] = {0};
	char con [12] = {'0','1','2','3','4','5','6','7','8','9','0','0'};
	
	welcome();
	while(end==0){
		bot=usebot();
		while(win == 0){
			printer(con,play,bot);
			playermove(con,pos,play,bot);
			win = winchecker(pos);
			play = nextplayer(play);
			if(win!=0){
				winprint(con,play,bot);
				windisplay(win,bot);
				end = retry(end);
				if(end==0){
					reset (con,pos);
					win=0,play=1,bot=0;	
					bot=usebot();
				}
			}
		
		}
	}
	printf("Thankyou for playing !\n");
	return 0;
}
