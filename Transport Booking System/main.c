#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// file
#define VEHICLE_FILE "vehicles.dat"
#define ROUTE_FILE "routes.dat"
#define TRIP_FILE "trips.dat"
#define BOOKING_FILE "bookings.dat"
#define TRANSACTION_FILE "transactions.txt"

// defining max values for each
#define MAX_VEHICLES 100
#define MAX_ROUTES 100
#define MAX_TRIPS 500
#define MAX_BOOKINGS 2000

struct Vehicle
{
    int Vehicle_id;
    char Vehicle_name[50];
    char Vehicle_type[100];
    int totalseats;

};
struct Route 
{
    int Route_id;
    char source[100];
    char destination[100];
    float distance;
    float fpk; // fare per kilometer
};
struct Trip{
    int Trip_id;
    int Route_id;
    int Vehicle_id;
    char date[12];
    char time[10];
    int booked_seats;
    int cancelled;
};

struct Booking
{
    int Booking_id;
    int Trip_id;
    char passenger_name[50];
    char phone[20];
    int seats;
    float fare;
    int cancelled;
};

// GLOBAL VARIABLES
 

struct Vehicle vehicles[MAX_VEHICLES];
struct Route routes[MAX_ROUTES];
struct Trip trips[MAX_TRIPS];
struct Booking bookings[MAX_BOOKINGS];

int vehicle_count =0;
int route_count = 0;
int trip_count=0;
int booking_count=0;


void ensure_files_exists(void){ //VEHICLE_FILE, ROUTE_FILE, TRIP_FILE, BOOKING_FILE, TRANSACTION_FILE
    FILE *file;
    file=fopen(VEHICLE_FILE,"ab");
    if(file!= NULL){
        fclose(file);
    }
     
    file = fopen(ROUTE_FILE,"ab");
    if(file!=NULL){
        fclose(file);
    }

    file =fopen(TRIP_FILE,"ab");
    if(file!=NULL){
        fclose(file);
    }

    file = fopen(BOOKING_FILE,"ab");
    if(file!=NULL){
        fclose(file);
    }

    file=fopen(TRANSACTION_FILE,"a");
    if(file!=NULL){
        fclose(file);
    }
}
 void clear_input(void){
 int ch;
 while ((ch=getchar()) !='\n' && ch!=EOF) // to remove /n from buffer so that it do not get sztuck in scanf or fegts also eof is end of file it will run until \n
 {
 }
 }
void read_line(char *text,int size){
    if(fgets(text,size,stdin)!=NULL)//size and sizeof is 2 different things size is variable now but sizeof calculase how much memory is consumed 
    {
        size_t length=strlen(text);
        if(length>0 && text[length - 1] == '\n')
        {
            text[length -1]='\0';
        }
        else{
            clear_input();
        }
    } // to remove the new line character \n when we click enter c gets the \n so we have to remove it and replace it by \0 then we are checking it using length and length -1 then replaing it wirth /0
}
int read_int(const char *message){
    int value;
    for(;;) // using infinite loop so that user can input infinte
    {
        printf("%s",message);
        if(scanf("%d",&value)==1) // checking
        {
            clear_input();
            return value;
        }
        clear_input();
        printf("Invalid input. Please enter a number\n");
    }
}

float read_float(const char *message){
    float value;
    for(;;){
        printf("%s",message);
        if(scanf("%f",&value)==1){ // samne as read_int
            clear_input();
            return value;
        }
        clear_input();
        printf("Invalid input. Please enter a number\n");
    }
}
void load_data(void){
    FILE *file;
    file= fopen(VEHICLE_FILE,"rb"); // rb = read binary read the file
    if(file!=NULL)
    {
        vehicle_count = (int)fread(
            vehicles,
            sizeof(struct Vehicle),
            MAX_VEHICLES,
            file
        );
        fclose(file);
    }
}
 int main(void){
    ensure_files_exists();
    load_data();
        printf("========================================\n");
    printf("      TRANSPORT BOOKING SYSTEM\n");
    printf("========================================\n");
    for(;;){
        printf("\n===== MAIN MENU =====\n");
        printf("1. Admin Login\n");
        printf("2. Passenger Menu\n");
        printf("0. Exit\n");
        int choice = read_int("Choose an option");
        switch (choice)
        {
            case 1:
            printf("Admin menus is coming next.\n");
            break;
            case 2:
            printf("Passenger menu is coming next.\n");
            break;
            case 3:
            printf("Thank you for using the system.\n");
            return 0;

            default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
 }