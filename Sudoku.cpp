#include<unistd.h>
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<ctime>
#include"Sudoku.h"

using namespace std;

int PNum[9][9];
int PNum_ini[9][9];
int PNum_ch[9][9];
int matrix[9][9];
int matrix_ch[9][9];
int matrix_ini[9][9];
int check_ch[9][9][9];
int check_ini[9][9][9];
int check[9][9][9];
int times[10]={0,0,0,0,0,0,0,0,0,0};
void output();
void  Sudoku::readIn(){
	for(int x=0;x<9;x++){
		for(int y=0;y<9;y++)
	    	matrix[x][y] = 0;
    }

	for(int x=0;x<9;x++){
		for(int y=0;y<9;y++){
	    	cin >> matrix[y][x];
		}
	}
}
int booll;
int checking(){
    for(int x=0;x<9;x++){
		for(int y=0;y<9;y++){
	    	if(matrix[y][x] != 0){
				for(int m=x;m<9;m++){
		    		if(matrix[y][m] == matrix[y][x] && m!=x) {
						booll=1;
		    		}
				}
				for(int n=y;n<9;n++){
		    		if(matrix[n][x] == matrix[y][x] && n!=y) {
						booll=1;
		    		}	
				}
				int cellx,m,celly,n;
				if(x<3){cellx=3;m=0;}
				else if(2<x&&x<6){cellx=6;m=3;}
				else{cellx=9;m=6;}
				if(y<3){celly=3;n=0;}
				else if(2<y&&y<6){celly=6;n=3;}
				else{celly=9;n=6;}
				for(m;m<cellx;m++){
		    		for(n;n<celly;n++){
						if(matrix[n][m] == matrix[y][x] && n!=y && m!=x){
			    			booll=1;
						}
		    		}
				}
				times[matrix[y][x]-1]++;
				times[9]++;
	    	}
		}
    }
}
void precheck(){
    for(int x=0;x<9;x++){
		for(int y=0;y<9;y++){
	    	if(matrix[y][x] != 0){
				for(int m=x;m<9;m++){
		    		if(matrix[y][m] == matrix[y][x] && m!=x) {
						cout << "0" << endl;
						exit(1);
		    		}
				}
				for(int n=y;n<9;n++){
		    		if(matrix[n][x] == matrix[y][x] && n!=y) {
						cout << "0" <<endl;
						exit(1);
		    		}	
				}
				int cellx,m,celly,n;
				if(x<=2){cellx=3;m=0;}
				else if(3<=x&&x<=5){cellx=6;m=3;}
				else if(6<=x&&x<=8){cellx=9;m=6;}
				if(y<=2){celly=3;n=0;}
				else if(3<=y&&y<=5){celly=6;n=3;}
				else if(6<=y&&y<=8){celly=9;n=6;}
				for(m;m<cellx;m++){
		    		for(n;n<celly;n++){
						if(matrix[n][m] == matrix[y][x] && n!=y && m!=x){
			    			cout << "0"<<endl;
			    			exit(1);
						}
		    		}
				}
				times[matrix[y][x]-1]++;
				times[9]++;
	    	}
		}
    }
    if(times[9]<17){
		cout << "2" <<endl;
		exit(1);
    }
	int count=0;
	for(int x=0;x<9;x++){
		if (times[x]==0) count++;
	}
	if(count!=0 && count!=1) {
		cout << "2" <<endl;
		exit(1);
	}
	count = 3;
	for(int x=0;x<9;x++){
		for(int y=0;y<9;y++){
			if(matrix[y][x]!=0){
				count--; break;
			}
		}
		if(x%3==2){
			if(count==2 || count==3){
				cout << "2" <<endl;
				exit(1);
			}
			count=3;
		}
	}
	for(int x=0;x<9;x++){
		for(int y=0;y<9;y++){
			if(matrix[x][y]!=0){
				count--; break;
			}
		}
		if(x%3==2){
			if(count==2 || count==3){
				cout << "2" <<endl;
				exit(1);
			}
			count=3;
		}
	}
}
int Sudoku::giveQuestion(){
	int random = rand()%10;
	if (random==0){
		cout <<"6 0 0 0 0 0 4 0 5"<<endl;
		cout <<"0 0 8 2 0 0 0 0 0"<<endl;
		cout <<"0 0 0 0 0 0 0 0 0"<<endl;
		cout <<"0 0 0 0 0 6 0 1 0"<<endl;
		cout <<"0 0 7 0 0 0 0 0 0"<<endl;
		cout <<"0 0 0 1 0 0 0 2 0"<<endl;
		cout <<"0 0 6 0 0 0 7 8 0"<<endl;
		cout <<"0 0 0 0 5 4 0 0 0"<<endl;
		cout <<"0 0 0 9 0 0 0 0 0"<<endl;	
	}
	else if (random==1){
		cout <<"0 0 0 0 0 0 2 0 0"<<endl;
		cout <<"0 0 9 0 0 0 0 0 0"<<endl;
		cout <<"0 0 0 0 0 0 0 7 0"<<endl;
		cout <<"0 1 0 0 0 2 6 0 0"<<endl;
		cout <<"0 0 0 9 0 0 0 0 5"<<endl;
		cout <<"0 0 0 3 0 0 0 0 0"<<endl;
		cout <<"0 0 0 0 0 1 0 0 0"<<endl;
		cout <<"0 0 5 0 0 7 0 0 9"<<endl;
		cout <<"9 0 3 0 0 0 0 0 4"<<endl;	
	}
	else if (random==2){
		cout <<"0 0 4 0 0 0 0 0 0"<<endl;
		cout <<"0 0 0 3 9 0 0 0 0"<<endl;
		cout <<"0 0 0 0 0 0 1 8 0"<<endl;
		cout <<"0 0 7 0 0 0 3 0 0"<<endl;
		cout <<"0 0 0 0 0 8 0 0 0"<<endl;
		cout <<"0 0 0 0 5 0 0 0 6"<<endl;
		cout <<"0 3 0 0 0 0 0 0 0"<<endl;
		cout <<"0 6 0 0 0 1 0 0 0"<<endl;
		cout <<"0 0 0 0 4 5 0 1 0"<<endl;	
	}
	else if (random==3){
		cout <<"0 0 9 4 0 0 0 0 0"<<endl;
		cout <<"0 0 0 0 0 8 0 6 0"<<endl;
		cout <<"5 0 0 0 0 0 7 0 0"<<endl;
		cout <<"0 0 0 0 0 0 0 0 0"<<endl;
		cout <<"0 0 0 3 0 0 0 4 9"<<endl;
		cout <<"2 0 0 0 0 0 0 0 0"<<endl;
		cout <<"0 0 4 0 0 0 0 0 1"<<endl;
		cout <<"0 0 0 0 7 5 3 0 0"<<endl;
		cout <<"0 0 0 0 2 0 0 0 0"<<endl;	
	}
	else if (random==4){
		cout <<"8 0 0 6 1 0 0 0 0"<<endl;
		cout <<"0 0 0 0 2 0 0 0 0"<<endl;
		cout <<"7 0 0 0 0 0 5 0 4"<<endl;
		cout <<"9 0 0 0 0 0 0 0 0"<<endl;
		cout <<"0 5 0 0 0 0 1 0 0"<<endl;
		cout <<"0 0 0 0 0 0 0 6 0"<<endl;
		cout <<"0 0 0 0 0 8 0 0 9"<<endl;
		cout <<"0 0 1 0 0 0 0 0 0"<<endl;
		cout <<"0 0 4 0 0 0 0 0 7"<<endl;	
	}
	else if (random==5){
		cout <<"0 0 0 8 1 0 6 0 0"<<endl;
		cout <<"0 0 5 0 0 0 0 0 0"<<endl;
		cout <<"0 2 0 0 0 0 0 0 0"<<endl;
		cout <<"0 7 1 0 0 0 0 2 0"<<endl;
		cout <<"0 0 0 4 0 0 0 0 9"<<endl;
		cout <<"0 0 0 0 0 0 1 0 0"<<endl;
		cout <<"0 0 0 0 0 0 0 5 0"<<endl;
		cout <<"0 4 0 0 2 0 0 0 0"<<endl;
		cout <<""<<endl;	
	}
	else if (random==6){
		cout <<"7 0 0 0 0 0 0 0 6"<<endl;
		cout <<"0 0 0 0 2 0 5 0 0"<<endl;
		cout <<"0 0 4 9 0 0 0 0 0"<<endl;
		cout <<"0 0 2 0 0 0 8 7 0"<<endl;
		cout <<"0 0 0 0 5 0 0 9 0"<<endl;
		cout <<"0 0 0 0 6 1 0 0 0"<<endl;
		cout <<"0 0 0 0 0 0 0 0 0"<<endl;
		cout <<"0 5 0 0 0 0 0 0 0"<<endl;
		cout <<"0 0 0 4 0 0 0 3 0"<<endl;	
	}
	else if (random==7){
		cout <<"0 0 0 7 0 0 0 0 0"<<endl;
		cout <<"3 9 0 0 0 0 0 0 0"<<endl;
		cout <<"4 0 0 0 0 0 0 0 0"<<endl;
		cout <<"0 1 0 0 9 0 0 0 0"<<endl;
		cout <<"0 0 5 0 0 0 7 0 0"<<endl;
		cout <<"0 0 0 0 0 4 0 0 3"<<endl;
		cout <<"8 0 0 0 0 0 9 0 0"<<endl;
		cout <<"0 0 0 2 0 3 0 0 0"<<endl;
		cout <<"0 0 0 5 0 0 0 1 0"<<endl;	
	}
	else if (random==8){
		cout <<"0 0 0 9 0 2 0 0 0"<<endl;
		cout <<"0 0 7 0 0 0 5 0 0"<<endl;
		cout <<"0 0 0 0 0 4 0 0 0"<<endl;
		cout <<"0 0 5 0 0 0 0 0 0"<<endl;
		cout <<"0 0 0 0 0 9 0 0 2"<<endl;
		cout <<"3 0 8 0 0 0 0 0 0"<<endl;
		cout <<"0 0 0 0 8 0 3 0 0"<<endl;
		cout <<"0 2 0 0 0 0 0 0 4"<<endl;
		cout <<"0 0 0 0 5 6 0 0 0"<<endl;	
	}
	else if (random==9){
		cout <<"0 0 0 0 0 0 0 0 0"<<endl;
		cout <<"0 0 0 0 6 0 4 0 0"<<endl;
		cout <<"0 0 6 8 0 0 7 0 0"<<endl;
		cout <<"0 4 0 0 0 0 0 0 6"<<endl;
		cout <<"0 5 0 0 0 0 0 0 0"<<endl;
		cout <<"9 0 0 2 0 0 0 1 0"<<endl;
		cout <<"0 0 7 0 0 0 0 0 0"<<endl;
		cout <<"0 0 8 0 0 0 0 2 1"<<endl;
		cout <<"0 0 0 0 5 0 0 0 0"<<endl;	
	}
}
void tracking(int a,int b){
	for(int x=0;x<9;x++){
		if(check[b][x][matrix[b][a]-1]!=0){
			check[b][x][matrix[b][a]-1]=0;
			PNum[b][x]--;
		}
		if(check[x][a][matrix[b][a]-1]!=0){	
			check[x][a][matrix[b][a]-1]=0;
			PNum[x][a]--;
		}
		check[b][a][x]=0;
	}
	for(int x=0;x<9;x++){
		for(int y=0;y<9;y++){
			if(x/3==a/3 && y/3==b/3){
				if(check[y][x][matrix[b][a]-1]!=0){
					check[y][x][matrix[b][a]-1]=0;
					PNum[y][x]--;
				}	
			}
		}
	}
	PNum[b][a]=0;
	
}
int back=0;
void initialSolve(){
	int count=1;
	while (count!=0){
		count=0;
		for(int x=0;x<9;x++){
			for(int y=0;y<9;y++){
				if(PNum[y][x]==1){
					for(int z=0;z<9;z++){
						if (check[y][x][z]!=0){
							matrix[y][x] = check[y][x][z];
							tracking(x,y);
							count++;
							break;
						}
					}
				}
				else if(PNum[y][x]==0 && matrix[y][x]==0){
					back=1;
					//cout << "0" <<endl;
					//exit(1);
				}
				int theOnly=0;
				for(int z=0;z<9;z++){
					if(check[y][z][x]!=0) theOnly++;
				}
				if(theOnly==1){
					for(int z=0;z<9;z++){
						if(check[y][z][x]!=0){
							matrix[y][z] = check[y][z][x];
							tracking(z,y);
							count++;
						}
					}
				}
				theOnly = 0;
				for(int z=0;z<9;z++){
					if(check[z][y][x]!=0) theOnly++;
				}
				if(theOnly==1){
					for(int z=0;z<9;z++){
						if(check[z][y][x]!=0){
							matrix[z][y] = check[z][y][x];
							PNum[z][y]=0;
							tracking(y,z);
							count++;
						}
					}
				}
				theOnly =0;
				if(x%3==0&&y%3==0){
					int cella=x;
					int cella2=x+3;
					int cellb=y;
					int cellb2=y+3;
					for(int z=0;z<9;z++){
						for(cella=x;cella<cella2;cella++){
							for(cellb=y;cellb<cellb2;cellb++){
								if(check[cellb][cella][z]!=0) theOnly++;
							}
						}					
						if(theOnly==1){
							for(cella=x;cella<cella2;cella++){
								for(cellb=y;cellb<cellb2;cellb++){
									if(check[cellb][cella][z]!=0){
										matrix[cellb][cella]=check[cellb][cella][z];
										tracking(cella,cellb);
										count++;
									}
								}		
							}
						}
						theOnly=0;
					}
				}
			}
		}
	/*cout <<endl<<endl;
	output();*/
	}
}
void recheck(){
	for(int x=0;x<9;x++){
		for(int y=0;y<9;y++){
			if(PNum[y][x] ==0 && matrix[y][x]==0){
				cout << "0" <<endl;
				exit(1);
			}
			if( y<3 && x%3==0 && PNum[y][x]==3 && PNum[y][x+1]==3 && PNum[y][x+2]==3){
				int count=0;
				for(int z=0;z<9;z++){
					if(check[y][x][z]==check[y][x+1][z] && check[y][x][z]==check[y][x+2][z])	count++;
				}
				if(count==9){
					for(int n=3;n<6;n++){
						if(PNum[n][x]==3 && PNum[n][x+1]==3 && PNum[n][x+2]==3){
							int count1=0;
							for(int z=0;z<9;z++){
								if(check[n][x][z]==check[n][x+1][z] && check[n][x][z]==check[n][x+2][z])	count1++;
							}
							if(count1==9){
								for(int n=6;n<9;n++){
									if(PNum[n][x]==3 && PNum[n][x+1]==3 && PNum[n][x+2]==3){
										int count2=0;
										for(int z=0;z<9;z++){
											if(check[n][x][z]==check[n][x+1][z] && check[n][x][z]==check[n][x+2][z])	count2++;
										}
										if(count2==9){
											cout << "2" <<endl; exit(1);
										}
									}
								}
							}
						}
					}
				}
			}
			else if(x<3 && y%3==0 && PNum[y][x]==3 && PNum[y+1][x]==3 && PNum[y+2][x]==3){
				int count=0;
				for(int z=0;z<9;z++){
					if(check[y][x][z]==check[y+1][x][z] && check[y][x][z]==check[y+2][x][z])	count++;
				}
				if(count==9){
					for(int n=3;n<6;n++){
						if(PNum[y][n]==3 && PNum[y+1][n]==3 && PNum[y+2][n]==3){
							int count1=0;
							for(int z=0;z<9;z++){
								if(check[y][n][z]==check[y+1][n][z] && check[y][n][z]==check[y+2][n][z])	count1++;
							}
							if(count1==9){
								for(int n=6;n<9;n++){
									if(PNum[y][n]==3 && PNum[y+1][n]==3 && PNum[y+2][n]==3){
										int count2=0;
										for(int z=0;z<9;z++){
											if(check[y][n][z]==check[y+1][n][z] && check[y][n][z]==check[y+2][n][z])	count2++;
										}
										if(count2==9){
											cout << "2" <<endl; exit(1);
										}
									}
								}
							}
						}
					}
				}
			}
			if(x%3==0 && y<6 && PNum[y][x]==2){
				if(PNum[y][x+1] ==2){
					int n;
					if(y<3) n=3;
					else n=6;
					for(n;n<9;n++){
						if(PNum[n][x]==2 && PNum[n][x+1]==2){
							int count=0;
							for(int z=0;z<9;z++){
								if(check[y][x][z]==check[y][x+1][z] && check[y][x][z]==check[n][x][z] && check[n][x+1][z]){
									count++;
								}
							}
							if (count==9){
								cout << "2" <<endl; exit(1);
							}
						}
					}
				}
			}
			if(y%3==0 && x<6 && PNum[y][x]==2){
				if(PNum[y+1][x] ==2){
					int n;
					if(y<x) n=3;
					else n=6;
					for(n;n<9;n++){
						if(PNum[y][n]==2 && PNum[y+1][n]==2){
							int count=0;
							for(int z=0;z<9;z++){
								if(check[y][x][z]==check[y+1][x][z] && check[y][x][z]==check[y][n][z] && check[y+1][n][z]){
									count++;
								}
							}
							if (count==9){
								cout << "2" <<endl; exit(1);
							}
						}
					}
				}
			}
		}
	}	
}

int guessT1=0;
int matrix_now1[9][9][70];
int check_now1[9][9][9][70];
int PNum_now1[9][9][70];
void redo(){
	int min=10;
	int m,n;
	for(int x=0;x<9;x++){
		for(int y=0;y<9;y++){
			if(PNum[y][x]<min && PNum[y][x]>1) {min=PNum[y][x];m=x;n=y;}
			if(min==2) break;
		}
		if(min==2)break;
	}
	int h=8;
	while(h!=-1){
		if(check[n][m][h]!=0) 
			{matrix[n][m]=check[n][m][h];break;}
		h--;
	} 
	for(int x=0;x<9;x++){
		for(int y=0;y<9;y++){
			matrix_now1[y][x][guessT1] = matrix[y][x];
			PNum_now1[y][x][guessT1] = PNum[y][x];
			for(int z=0;z<9;z++) check_now1[y][x][z][guessT1]=check[y][x][z];
		}
	 }
	tracking(m,n);
	initialSolve();
	guessT1++;
	if(back==1){
		guessT1--;
		for(int x=0;x<9;x++){
			for(int y=0;y<9;y++){
				matrix[y][x] = matrix_now1[y][x][guessT1];
				PNum[y][x] = PNum_now1[y][x][guessT1];
				for(int z=0;z<9;z++) check[y][x][z]=check_now1[y][x][z][guessT1];
			}
	 	}
		PNum[n][m]--;
		for(int z=8;z>-1;z--){ if(check[n][m][z]!=0){check[n][m][z]=0;break;}}
	back=0;
	}
	booll =0;
	checking();
	int toKnow=81;
	if(booll==0){
		for(int x=0;x<9;x++){
			for(int y=0;y<9;y++){
				if(matrix[y][x]!=0) toKnow--;
			}
		}
	}
	if (toKnow==0){
		int tt=81;
		for(int x=0;x<9;x++){
			for(int y=0;y<9;y++){
				if(matrix[y][x]==matrix_ch[y][x]) tt--;
			}
		}
		if(tt==0){
			cout << "1" <<endl;
			output();
			exit(1);	
		}
		else{
			cout <<"2" <<endl;
			exit(1);
		}
	}
	/*else if(toKnow!=0){int tt=81;
		for(int x=0;x<9;x++){for(int y=0;y<9;y++){ if(PNum[y][x]==0) tt--;}}
		if (tt==0){cout <<"0"<<endl;exit(1);}
	}*/
	redo();
}
int guessT=0;
int matrix_now[9][9][70];
int check_now[9][9][9][70];
int PNum_now[9][9][70];
void guess(){
	int min=10;
	int m,n;
	for(int x=0;x<9;x++){
		for(int y=0;y<9;y++){
			if(PNum[y][x]<min && PNum[y][x]>1) {min=PNum[y][x];m=x;n=y;}
			if(min==2) break;
		}
		if(min==2)break;
	}
	for(int z=0;z<9;z++){
		if(check[n][m][z]!=0) 
			{matrix[n][m]=check[n][m][z];break;}
	}
	for(int x=0;x<9;x++){
		for(int y=0;y<9;y++){
			matrix_now[y][x][guessT] = matrix[y][x];
			PNum_now[y][x][guessT] = PNum[y][x];
			for(int z=0;z<9;z++) check_now[y][x][z][guessT]=check[y][x][z];
		}
	 }
	tracking(m,n);
	initialSolve();
	guessT++;
	if(back==1){
		guessT--;
		for(int x=0;x<9;x++){
			for(int y=0;y<9;y++){
				matrix[y][x] = matrix_now[y][x][guessT];
				PNum[y][x] = PNum_now[y][x][guessT];
				for(int z=0;z<9;z++) check[y][x][z]=check_now[y][x][z][guessT];
			}
	 	}
		PNum[n][m]--;
		for(int z=0;z<9;z++){ if(check[n][m][z]!=0){check[n][m][z]=0;break;}}
		back=0;
	}
	booll=0;
	checking();
	int toKnow=81;
	if(booll!=1){
		for(int x=0;x<9;x++){
			for(int y=0;y<9;y++){
				if(matrix[y][x]!=0) toKnow--;
			}
		}
	}
	if (toKnow==0){
		//output();
		for(int x=0;x<9;x++){
			for(int y=0;y<9;y++){
				matrix_ch[y][x]=matrix[y][x];
				matrix[y][x]=matrix_ini[y][x];
				PNum[y][x]=PNum_ini[y][x];
				for(int z=0;z<9;z++) check[y][x][z]=check_ini[y][x][z];
			}
		}
		redo();
		/*cout << "1" <<endl;
		output();
		exit(1);*/
	}
	else if(toKnow!=0){int tt=81;
		for(int x=0;x<9;x++){for(int y=0;y<9;y++){ if(PNum[y][x]==0) tt--;}}
		if (tt==0){cout <<"0"<<endl;exit(1);}
	}
	//output();
	guess();
}
int Sudoku::solve(){

    precheck();
	for(int x=0;x<9;x++){
		for(int y=0;y<9;y++){ 
			PNum[y][x]=0;
			for(int z=0;z<9;z++){check[y][x][z]=0;}
		}
	}
    for(int x=0;x<9;x++){
		for(int y=0;y<9;y++){
	    	for(int z=0;z<9;z++){
	    		if(matrix[y][x] !=0) {check[y][x][z]=0; PNum[y][x]=0;}
				else {check[y][x][z] = z+1; PNum[y][x]++; }
   	    	}
		}
    }
	for(int x=0;x<9;x++){
		for(int y=0;y<9;y++){
			if(matrix[y][x]!=0) tracking(x,y);
		}
	}
    initialSolve();
	recheck();
	int count=81;
	for(int x=0;x<9;x++){
		for(int y=0;y<9;y++){
			if(matrix[y][x]!=0) count--;
		}
	}
	if (count==0) {cout<<"1"<<endl; output();exit(1);}
	for(int x=0;x<9;x++){
		for(int y=0;y<9;y++){
			matrix_ini[y][x]=matrix[y][x];
			matrix_ch[y][x] =matrix[y][x];
			PNum_ini[y][x]=PNum[y][x];
			PNum_ch[y][x] =PNum[y][x];
			for(int z=0;z<9;z++){
				check_ini[y][x][z]=check[y][x][z];
				check_ch[y][x][z] =check[y][x][z];
			}
		}
	}
	guess();


}
void Sudoku::changeNum(int a,int b){
    for(int x=0;x<9;x++){
		for(int y=0;y<9;y++){
	    	if(matrix[y][x] == a) matrix[y][x]=b;
	    	else if(matrix[y][x] == b) matrix[y][x]=a;
	    	else {}
		}
    }
}
void Sudoku::changeRow(int a,int b){
    int change;
    if (a + b==3){
		for(int x=3;x<6;x++){
	    	for(int y=0;y<9;y++){
				change = matrix[y][x];
				matrix[y][x] = matrix[y][x+3];
				matrix[y][x+3] = change; 
	    	}
		}
    }
    else if ( a + b==2 && a!=b){
		for(int x=0;x<3;x++){
	    	for(int y=0;y<9;y++){
				change = matrix[y][x];
				matrix[y][x] = matrix[y][x+6];
				matrix[y][x+6] = change; 
	    	}
		}
    }
    else if ( a + b==1){
		for(int x=0;x<3;x++){
	    	for(int y=0;y<9;y++){
				change = matrix[y][x];
				matrix[y][x] = matrix[y][x+3];
				matrix[y][x+3] = change; 
	    	}
		}
    }
    else {}
}
void Sudoku::changeCol(int a,int b){
    int change;
    if (a + b==3){
		for(int x=3;x<6;x++){
	    	for(int y=0;y<9;y++){
				change = matrix[x][y];
				matrix[x][y] = matrix[x+3][y];
				matrix[x+3][y] = change; 
	    	}
		}
    }
    else if ( a + b==2 && a!=b){
		for(int x=0;x<3;x++){
	    	for(int y=0;y<9;y++){
				change = matrix[x][y];
				matrix[x][y] = matrix[x+6][y];
				matrix[x+6][y] = change; 
	    	}
		}
    }
    else if ( a + b==1){
		for(int x=0;x<3;x++){
	    	for(int y=0;y<9;y++){
				change = matrix[x][y];
				matrix[x][y] = matrix[x+3][y];
				matrix[x+3][y] = change; 
	    	}
		}	
    }
    else {}
}
void Sudoku::rotate(int n){
    int newmatrix[9][9];
    if (n%4 == 0){
	
    }
    else if(n%4 == 1){ 
		for(int x=0;x<9;x++){
	    	for(int y=0;y<9;y++){
				newmatrix[y][x]=matrix[x][8-y];
	    	}
		}
		for(int x=0;x<9;x++){
	    	for(int y=0;y<9;y++){
				matrix[y][x]=newmatrix[y][x];
	    	}
		}
    }
    else if(n%4 == 2){
		for(int x=0;x<9;x++){
	    	for(int y=0;y<9;y++){
				newmatrix[y][x]=matrix[8-y][8-x];
	    	}
		}
		for(int x=0;x<9;x++){
	    	for(int y=0;y<9;y++){
				matrix[y][x]=newmatrix[y][x];
	    	}
		}
    }
    else{
		for(int x=0;x<9;x++){
	    	for(int y=0;y<9;y++){
				newmatrix[y][x]=matrix[8-x][y];
	    	}
		}
		for(int x=0;x<9;x++){
	    	for(int y=0;y<9;y++){
				matrix[y][x]=newmatrix[y][x];
	    	}
		}
    }
}
void Sudoku::flip(int n){
    int put[9];
    if( n ==0 ){
		for(int x=0;x<5;x++){
	    	for(int y=0;y<9;y++){
	    		put[y]=matrix[y][x];
				matrix[y][x]=matrix[y][8-x];
				matrix[y][8-x]=put[y];
	    	}
    	}	
    }
    else if( n == 1){
		for(int x=0;x<5;x++){
	    	for(int y=0;y<9;y++){
				put[y]=matrix[x][y];
				matrix[x][y]=matrix[8-x][y];
				matrix[8-x][y]=put[y];
	    	}
		}
    }
}
int Sudoku::transform(){
    changeNum(rand()%9+1 , rand()%9+1);
    changeRow(rand()%3 ,rand()%3);
    changeCol(rand()%3 ,rand()%3);
    rotate(rand()%101);
    flip(rand()%2);
    output();
}
void output(){
for(int x=0;x<9;x++){
for(int y=0;y<9;y++) cout << matrix[y][x] <<" ";
cout << endl;}cout <<endl;}
