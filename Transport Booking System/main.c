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






float read_float(const char *message){ // what message will user see but cant change the message as it is const
    float value;
    for(;;){
        printf("%s",message);
        if(scanf("%f",&value)==1){ // samne as read_int
            clear_input(); // if something goes worng will be cleared
            return value; // returning the value to read_float
        }
        clear_input();
        printf("Invalid input. Please enter a number\n");
    }
}



// rb = read binary

void load_data(void){ // this section loads the data from the memory it will open the file the will read data with rb
    FILE *file;
    file= fopen(VEHICLE_FILE,"rb"); // rb = read binary read the file
    if(file!=NULL)
    {
        vehicle_count = (int)fread( // fread vehicle data vehcile array te rakhe
            vehicles,
            sizeof(struct Vehicle),
            MAX_VEHICLES,
            file
        );
        fclose(file);
    }
    file = fopen(ROUTE_FILE, "rb");

    if (file != NULL)
    {
        vehicle_count = (int)fread( // data rakhche route array te
            vehicles,
            sizeof(struct Route),
            MAX_VEHICLES,
            file
        );

        fclose(file);   
    }
    file =fopen(TRIP_FILE,"rb");
    
    if(file!= NULL)
    {
        trip_count=(int)fread( // data rakhche trip array te
            trips,
            sizeof(struct Trip),
            MAX_TRIPS,
            file
        );
    }
    fclose(file);
 
    file= fopen(BOOKING_FILE,"rb");
    if(file!=NULL)
    {
booking_count=(int)fread( // data rakhe booking e
bookings,
sizeof(struct Booking),
MAX_BOOKINGS,
file
);
    
    fclose(file);
}
}

// wb = write binary
//fread() file থেকে memory-তে data আনে।

// fwrite() memory থেকে file-এ data পাঠায়।


void save_vehicles(void)
{
    FILE *file =fopen(VEHICLE_FILE,"wb");
    if(file==NULL){
        printf("Could not save vehicles in vehicles.dat\n");
        return;
    }
    fwrite(
        vehicles,
        sizeof(struct Vehicle),
        vehicle_count,
        file
    );
    fclose(file);
}



void save_routes(void){
    FILE *file=fopen(ROUTE_FILE,"wb");
    if(file==NULL){
        printf("Could not save route in routes.dat\n");
        return;
    }
        fwrite(
            routes,
            sizeof(struct Route),
            route_count,
            file
        );
        fclose(file);
}



void save_trips(void){
    FILE *file=fopen(TRIP_FILE,"wb");
    if(file==NULL){
        printf("Could not save trips in trips.data");
        return;
    }
    fwrite(
        trips,
        sizeof(struct Trip),
        trip_count,
        file
    );
    fclose(file);
}



void save_bookings(void){
    FILE *file =fopen(BOOKING_FILE,"wb");
    if(file==NULL){
        printf("Could not save booking in booking.data\n");
        return;
    }
    fwrite(
        bookings,
        sizeof(struct Booking),
        booking_count,
        file
    );
    fclose(file);
}



void admin_menu(void)
{
    for(;;){
    printf("\n===== ADMIN MENU =====\n");
        printf("1. Add Vehicle\n");
        printf("2. View Vehicles\n");
        printf("3. Update Vehicle\n");
        printf("4. Add Route\n");
        printf("5. View Routes\n");
        printf("6. Update Route\n");
        printf("7. Schedule Trip\n");
        printf("8. View Trips\n");
        printf("9. Cancel Trip\n");
        printf("10. View All Bookings\n");
        printf("11. View Reports\n");
        printf("12. View Transaction Log\n");
        printf("0. Back to Main Menu\n");

        int choice = read_int("Choose an option: ");

        switch (choice)
        {
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            case 7:
            break;
            case 8:
            break;
            case 9:
            break;
            case 10:
            break;
            case 11:
            break;
            case 12:
            break;
            case 0:
            printf("Thank you for using this system.\n");
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

void passenger_menu(void)
{
    for (;;)
    {
        printf("\n===== PASSENGER MENU =====\n");
        printf("1. Browse Trips\n");
        printf("2. Book Ticket\n");
        printf("3. Cancel Booking\n");
        printf("0. Back to Main Menu\n");

        int choice = read_int("Choose an option: ");

        switch (choice)
        {
            case 1:
            case 2:
            case 3:
                printf("This feature is coming next.\n");
                break;

            case 0:
                return;

            default:
                printf("Invalid choice.\n");
        }
    }
}





















struct Vehicle *find_vehicle(int id){ // finding vechile with id with the help of the cound and vehcile[i]
    for(int i=0;i<vehicle_count;i++){
        if(vehicles[i].Vehicle_id == id){
            return &vehicles[i];
        }
    }
    return NULL;
 }
  int next_vehicle_id(void)
  {
    int id=1;
    while(find_vehicle(id) != NULL){ // will find the id if not null then will add 1 but initial it is 1
        id++;
    }
    return id;
  }

struct Route *find_route(int id)
{
    for(int i=0;i<route_count;i++){
        if(routes[i].Route_id==id){
            return & routes[i];
        }
    }
    return NULL;
}

struct Trip *find_trip(int id)
{
    for(int i=0;i<trip_count;i++){
        if(trips[i].Trip_id==id){
            return & trips[i];
        }
    }
    return NULL;
}
  struct Booking *find_booking(int id)
  {
   for(int i=0;i<booking_count;i++){
    if(bookings[i].Booking_id==id){
        return & bookings[i];
    }
   }
   return NULL;
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
        int choice = read_int("Choose an option: ");
        switch (choice)
        {
            case 1:
            admin_menu();
            break;
            case 2:
           passenger_menu();
            break;
            case 0:
            printf("Thank you for using the system.\n");
            return 0;

            default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
 }

