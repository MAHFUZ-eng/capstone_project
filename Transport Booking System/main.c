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


