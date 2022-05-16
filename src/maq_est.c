#include <stdio.h>
#include <stdlib.h>

#define S0 0
#define S1 1
#define S2 2
#define S3 3
#define S4 4

int main(void) {

	int state = S0;		//Or whateve is the initial state.
	char tecla;
	double Vtotal = 0;
	
	char produto1[] = "Beer: 1.5 EUR";
	char produto2[] = "Tuna Sandwich: 1.0 EUR";
	char produto3[] = "Coffee: 0.5 EUR";
	
	double vp1 = 1.5;
	double vp2 = 1.0;
	double vp3 = 0.5;
	
	int selProduct = 1;
	int count = 0;
	
	while(1){
		//scanf(" %c\n", &tecla);
	    if (count <= 0)
		{
			printf("\n%s		Credit: %.2f", produto1, Vtotal);
			count++;
		}
		
		
	
	
		tecla = getchar();
		if(tecla >= '1' && tecla <= '4'){
			state = S2;
		}
		
		if(tecla == '8' || tecla == '9'){
			state = S1;
		}
		
		if(tecla == 'R' || tecla == 'r'){
			state = S3;
		}
		
		if (tecla == 'S' || tecla == 's')
		{
			state = S4;
		}
		
		switch(state){
			
			case S0:
					
					if(selProduct == 1){
						printf("\n%s", produto1);
					}
					if(selProduct == 2){
						printf("\n%s", produto2);
					}
					if(selProduct == 3){
						printf("\n%s", produto3);
					}
					printf("		Credit:		%.2f\n", Vtotal);
					
					break;
					
			case S1: // PAGE UP AND PAGE DOWN
					if(tecla == '9' && selProduct == 1) //tecla up
					{
						selProduct = 2;
						//printf("\n%s	Credit: %d", produto2, Vtotal);
					}
					
					else if(tecla == '9' && selProduct == 2) //tecla up
					{
						selProduct = 3;
						//printf("\n%s	Credit: %d", produto3, Vtotal);
					}
					else if(tecla == '9' && selProduct == 3) //tecla up
					{
						selProduct = 1;
						//printf("\n%s	Credit: %d", produto1, Vtotal);
					}
					else if(tecla == '8' && selProduct == 1) //tecla down
					{
						selProduct = 3;
						//printf("\n%s	Credit: %d", produto3, Vtotal);
					}
					else if(tecla == '8' && selProduct == 2) //tecla down
					{
						selProduct = 1;
						//printf("\n%s	Credit: %d", produto1, Vtotal);
					}
					else if(tecla == '8' && selProduct == 3) //tecla down
					{
						selProduct = 2;
						//printf("\n%s	Credit: %d", produto2, Vtotal);
					}
					
					
					state = S0;
					
					break;
			
			case S2: // INSERT COIN
					if(tecla == '1'){
						Vtotal += 0.1;
					}
					
					if(tecla == '2'){
						Vtotal += 0.2;
					}
					
					if(tecla == '3'){
						Vtotal += 0.5;
					}
					
					if(tecla == '4'){
						Vtotal += 1;
					}
					
					state = S0;
					
					break;
					
			case S3: //RETURN CREDIT
					printf("\n%.2f EUR return\n", Vtotal);
					Vtotal = 0;
					state = S0;
					break;
					
			case S4: //Select product
			
						if(selProduct == 1){
							if( vp1 > Vtotal){
								printf("Not enough credit, Product Beer cost 1.5 EUR, credit is %.2f\n", Vtotal);
						}	
							else
						{
								Vtotal = Vtotal - vp1;
								printf("Product Beer dispensed, remaining credit is %.2f\n", Vtotal);
						}
						
					
						}
						if(selProduct == 2){
							if( vp2 > Vtotal){
								printf("Not enough credit, Product Tuna Sandwich cost 1.0 EUR, credit is %.2f\n", Vtotal);
						}	
							else
							{
							Vtotal = Vtotal - vp2;
								printf("Product Tuna Sandwich dispensed, remaining credit is %.2f\n", Vtotal);
							}
						}
						if(selProduct == 3){
							if( vp3 > Vtotal){
								printf("Not enough credit, Product Coffee cost 0.5 EUR, credit is %.2f\n", Vtotal);
						}	
							else
						{
							Vtotal = Vtotal - vp3;
							printf("Product Coffee dispensed, remaining credit is %.2f\n", Vtotal);
						}
						}
						state = S0;
						break;
				}				
	}
	return 0;
	}
