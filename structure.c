#include <stdio.h>

struct hotel
{
	char name[20], address[100], grade;
	int avgRoomCharge, numRooms;
}hotels[10];

int Index = 0;

void getHotel()
{
	printf("\nEnter name: "); fflush(stdin);
	fgets(hotels[Index].name, 20, stdin);
	printf("Enter address: "); fflush(stdin);
	fgets(hotels[Index].address, 100, stdin);
	printf("Enter grade: ");
	scanf("%c", &hotels[Index].grade);
	printf("Enter average room charge: ");
	scanf("%d", &hotels[Index].avgRoomCharge);
	printf("Enter number of rooms: ");
	scanf("%d", &hotels[Index].numRooms);
	++Index;
}

void displayHotel(struct hotel h)
{
	printf("\n\nName: %sAddress: %sGrade: %c\nAverage Room Charge: %d\nNumber of Rooms: %d\n\n", 
			h.name, h.address, h.grade, h.avgRoomCharge, h.numRooms);
}

void sameGrade(char grade)
{
	struct hotel sameGradeHotels[Index + 1];
	int hotelIndex = 0;
	for(int i = 0; i <= Index; ++i)
		if(hotels[i].grade == grade)
			sameGradeHotels[hotelIndex++] = hotels[i];
	for(int i = 0; i < hotelIndex; ++i)
	{
		int min = i;
		for(int j = i; j <= hotelIndex; ++j)
			if(sameGradeHotels[min].avgRoomCharge > sameGradeHotels[j].avgRoomCharge)
				min = j;
		if(min != i)
		{
			struct hotel temp = sameGradeHotels[min];
			sameGradeHotels[min] = sameGradeHotels[i];
			sameGradeHotels[i] = temp;
		}
	}
	for(int i = 0; i <= hotelIndex; ++i)
		displayHotel(sameGradeHotels[i]);
}

void lessCharge(int value)
{
	for(int i = 0; i <= Index; ++i)
		if(hotels[i].avgRoomCharge < value)
			displayHotel(hotels[i]);
}

int main()
{
	int option = 0;
	while(option != 4)
	{
		printf("\n1. Enter hotel details\n2. Print out hotels of a given grade in order of charges");
		printf("\n3. Print out hotels with room charges less than a given value\n4. Exit\nChoose option (1/2/3/4): ");
		scanf("%d", &option);
		switch(option)
		{
			case 1: printf("\nEnter the number of hotels: ");
					int numberOfHotels;
					scanf("%d", &numberOfHotels);
					for(int i = 0; i < numberOfHotels; ++i)
						getHotel();
					break;
			case 2: printf("\nEnter grade: ");
					char grade; fflush(stdin);
					scanf("%c", &grade);
					sameGrade(grade);
					break;
			case 3: printf("\nEnter charge value: ");
					int value;
					scanf("%d", &value);
					lessCharge(value);
					break;
		}
	}
	return 0;
}