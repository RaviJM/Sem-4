#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct city
{
    char name[20];
    int x, y;
    struct city *next;
} city;
city *head = NULL;
int counter = 0;
void add_city()
{
    city *new_city = malloc(sizeof(city));
    printf("\nEnter name of city: ");
    scanf("%s", &new_city->name);
    printf("Enter x coordinate: ");
    scanf("%d", &new_city->x);
    printf("Enter y coordinate: ");
    scanf("%d", &new_city->y);
    new_city->next = NULL;
    counter++;
    if (head == NULL)
    {
        head = new_city;
    }
    else
    {
        city *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_city;
    }
}
void print_cities()
{
    int i = 1;
    city *temp = head;
    if (temp == NULL)
    {
        printf("\nNo cities are there in database!!!\n");
    }
    while (temp != NULL)
    {
        printf("\n---------------CITY %d---------------", i);
        printf("\nName: %s", temp->name);
        printf("\nX : %d", temp->x);
        printf("\nY : %d\n", temp->y);
        temp = temp->next;
        i++;
    }
}
void print_given_city(city *temp)
{
    printf("\n-----------------------------------------");
    printf("\nName: %s", temp->name);
    printf("\nX : %d", temp->x);
    printf("\nY : %d\n", temp->y);
}
void search_city_by_name()
{
    char name[20];
    printf("\nEnter name of city: ");
    scanf("%s", &name);
    city *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            print_given_city(temp);
            return;
        }
        temp = temp->next;
    }
    printf("\nGiven city not found\n");
}
void search_city_by_x_y()
{
    int x, y;
    printf("\nEnter x coordinate: ");
    scanf("%d", &x);
    printf("Enter y coordinate: ");
    scanf("%d", &y);
    city *temp = head;
    while (temp != NULL)
    {
        if (temp->x == x && temp->y == y)
        {
            print_given_city(temp);
            return;
        }
        temp = temp->next;
    }
    printf("\nGiven city not found\n");
}
float calculate_distance(city *temp1, int x, int y)
{
    float distance = sqrt(pow(x - temp1->x, 2) + pow(y - temp1->y, 2));
    return distance;
}
void delete_city()
{
    int flag = 0;
    char name[20];
    printf("\nEnter name of city: ");
    scanf("%s", &name);
    city *temp = head;
    city *prev = NULL;
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            if (prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            counter--;
            flag++;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (flag == 0)
    {
        printf("\nGiven city not found\n");
    }
}
void print_city_within_distance()
{
    int x, y;
    float distance;
    int flag = 0;
    printf("\nEnter x coordinate: ");
    scanf("%d", &x);
    printf("Enter y coordinate: ");
    scanf("%d", &y);
    printf("Enter distance: ");
    scanf("%f", &distance);
    city *temp = head;
    while (temp != NULL)
    {
        if (calculate_distance(temp, x, y) <= distance)
        {
            print_given_city(temp);
            flag++;
        }
        temp = temp->next;
    }
    if (flag == 0)
    {
        printf("\nNo city found within given distance\n");
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Add city");
        printf("\n2. Print all cities");
        printf("\n3. Search city by name");
        printf("\n4. Search city by x and y coordinate");
        printf("\n5. Delete city");
        printf("\n6. Print cities within given distance");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_city();
            break;
        case 2:
            print_cities();
            break;
        case 3:
            search_city_by_name();
            break;
        case 4:
            search_city_by_x_y();
            break;
        case 5:
            delete_city();
            break;
        case 6:
            print_city_within_distance();
            break;
        case 7:
            exit(0);
        default:
            printf("\nInvalid choice\n");
        }
    }
    return 0;
}