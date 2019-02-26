#include <stdio.h>

double seatPrices[15];
double totalSales;
char theaterSeating[15][30] = {0};

void setTheaterSeating(){

	//makes the theater seating array and sets all values to #

		for (int i = 0; i < 15; i++){
			for(int j = 0; j < 30; j++){
				theaterSeating[i][j] = '#';
			}
		}

}

void getSeatPricing(){

	//takes input from user to determine seat pricing

	for(int i = 0; i < 15; i++){

	printf("\nPlease enter the pricing for Row %d:  ", i+1);
	fflush(stdout);
	scanf("%lf", &seatPrices[i]);

	}

}  void displayTheaterSeating(){

	//displays theater in console

	printf("\n");
	printf("                      Seating:\n");
	printf("          123456789012345678901234567890");

		for(int i = 0; i < 15; i++){

			if(i + 1 < 10){

			printf("\nRow %d:    ", i+1);

		} else {

			printf("\nRow %d:   ", i+1);
		}
			for(int j = 0; j < 30; j++){

				printf("%c", theaterSeating[i][j]);

			}

		}

} void purchaseTickets(){

	int row, seat, exitCheck = 0;

	while(exitCheck == 0){
	printf("\n\nEnter the row number of the tickets you wish to purchase: ");
	printf("\nEnter -1 to return to the options menu.");
	fflush(stdout);
	scanf("%d", &row);


	if(row == -1){

		options();

	}

	printf("\n\nEnter the seat number of the tickets you wish to purchase: ");
	fflush(stdout);
	scanf("%d", &seat);

	if(theaterSeating[row][seat] == '*'){

		printf("\n\nSorry, this seat is taken.");
		printf("\nPlease try again!");


	} else {

		theaterSeating[row][seat] = '*';
		totalTickets(row);
		printf("\nYour tickets for Row %d cost $%.02lf.", row, seatPrices[row - 1]);


	}

 }

} void totalTickets(int row){

	totalSales += seatPrices[row];

} void seatsAvailablePerRow(){

	int seatsAvailable[15] = {0};

	for(int i = 0; i < 15; i++){
			for(int j = 0; j < 30; j++){

				if(theaterSeating[i][j] == '#'){

					seatsAvailable[i]++;

				}

			}

		}


	for(int i = 0; i < 15; i++){

			if(i + 1 < 10){

			printf("\nRow %d:    %d seats available.", i+1, seatsAvailable[i]);

		} else {

			printf("\nRow %d:   %d seats available.", i+1, seatsAvailable[i]);
		}


			}

} void seatsSold(){

	int counter = 0;

	for(int i = 0; i < 15; i++){
		for(int j = 0; j < 15; j++){
			if(theaterSeating[i][j] == '*'){

				counter++;
			}
		}
	}

	printf("%d seats have been sold.", counter);


} void seatsTotal(){

	int counter = 0;

	for(int i = 0; i < 15; i++){
		for(int j = 0; j < 30; j++){
			if(theaterSeating[i][j] == '#'){

				counter++;
			}
		}
	}

	printf("%.d seats are still available.", counter);


} void options(void){

	int selection;

	printf("\n\nChoose what you wish to do: ");
	printf("\n1. Purchase Tickets");
	printf("\n2. See how many seats have been sold");
	printf("\n3. See how many seats are available in each row");
	printf("\n4. See how many seats are available in total");
	printf("\n5. Display total ticket sales");
	printf("\n6. Exit the program\n");

	fflush(stdout);
	scanf("%d", &selection);

	switch(selection){

		case 1:
			purchaseTickets();
			break;
		case 2:
			seatsSold();
			break;
		case 3:
			seatsAvailablePerRow();
			break;
		case 4:
			seatsTotal();
			break;
		case 5:
			displayTotalTicketSales();
			break;
		case 6:
			exit(0);
	}

} void displayTotalTicketSales(){

	printf("\nTotal value of tickets sold: $%.02f", totalSales);
}

int main(void){

	int exitCheckMain = 0;

	printf("Welcome to Dom's Theater!");

	setTheaterSeating();
	getSeatPricing();
	displayTheaterSeating();

	while(exitCheckMain == 0){
	options();

}

	return 0;


}
