#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ==============================
   CONSTANTS
   ============================== */

#define MAX_RESOURCE 100
#define MAX_VICTIM 100
#define MAX_VOLUNTEER 100
#define MAX_DISTRIBUTION 100


/* ==============================
   RESOURCE STRUCTURE
   ============================== */

struct Resource
{
    int id;
    char name[50];
    char category[30];
    int quantity;
    char unit[20];
};


/* ==============================
   VICTIM STRUCTURE
   ============================== */

struct Victim
{
    int id;
    char name[50];
    int age;
    char area[50];
    int familyMembers;
    char priority[20];
};


/* ==============================
   VOLUNTEER STRUCTURE
   ============================== */

struct Volunteer
{
    int id;
    char name[50];
    char phone[20];
    char area[50];
};


/* ==============================
   DISTRIBUTION STRUCTURE
   ============================== */

struct Distribution
{
    int victimID;
    int resourceID;
    int quantity;
};


/* ==============================
   GLOBAL VARIABLES
   ============================== */

struct Resource resource[MAX_RESOURCE];
struct Victim victim[MAX_VICTIM];
struct Volunteer volunteer[MAX_VOLUNTEER];
struct Distribution distribution[MAX_DISTRIBUTION];

int totalResource = 0;
int totalVictim = 0;
int totalVolunteer = 0;
int totalDistribution = 0;


/* ==============================
   FUNCTION PROTOTYPES
   ============================== */

/* Login and Main Menu */
void login();
void mainMenu();

/* Resource Management */
void resourceMenu();
void addResource();
void viewResource();
void searchResource();
void updateResource();
void deleteResource();
void sortResource();

/* Victim Management */
void victimMenu();
void addVictim();
void viewVictim();
void searchVictim();
void updateVictim();
void deleteVictim();

/* Volunteer Management */
void volunteerMenu();
void addVolunteer();
void viewVolunteer();
void searchVolunteer();
void updateVolunteer();
void deleteVolunteer();

/* Relief Distribution */
void reliefMenu();
void allocateRelief();
void distributionHistory();

/* Reports */
void reportMenu();
void totalResourcesReport();
void totalVictimsReport();
void totalVolunteersReport();
void stockReport();
void systemSummary();

/* File Handling */
void saveResources();
void loadResources();
void saveVictims();
void loadVictims();
void saveVolunteers();
void loadVolunteers();


/* ==============================
   LOGIN SYSTEM
   ============================== */

void login()
{
    char username[20];
    char password[20];

    printf("\n==============================");
    printf("\n   DISASTER RELIEF MANAGEMENT");
    printf("\n==============================");

    printf("\nUsername : ");
    scanf("%19s", username);

    printf("Password : ");
    scanf("%19s", password);

    if(strcmp(username, "admin") == 0 &&
       strcmp(password, "1234") == 0)
    {
        printf("\nLogin Successful!\n");
        mainMenu();
    }
    else
    {
        printf("\nInvalid Username or Password.\n");
    }
}


/* ==============================
   MAIN MENU
   ============================== */

void mainMenu()
{
    int choice;

    while(1)
    {
        printf("\n==============================");
        printf("\n          MAIN MENU");
        printf("\n==============================");

        printf("\n1. Resource Management");
        printf("\n2. Victim Management");
        printf("\n3. Volunteer Management");
        printf("\n4. Relief Distribution");
        printf("\n5. Reports");
        printf("\n6. Exit");

        printf("\n\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                resourceMenu();
                break;

            case 2:
                victimMenu();
                break;

            case 3:
                volunteerMenu();
                break;

            case 4:
                reliefMenu();
                break;

            case 5:
                reportMenu();
                break;

            case 6:
                saveResources();
                saveVictims();
                saveVolunteers();

                printf("\nThank You.\n");
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}


/* ==============================
   RESOURCE MANAGEMENT
   ============================== */

void resourceMenu()
{
    int choice;

    while(1)
    {
        printf("\n==============================");
        printf("\n     RESOURCE MANAGEMENT");
        printf("\n==============================");

        printf("\n1. Add Resource");
        printf("\n2. View Resources");
        printf("\n3. Search Resource");
        printf("\n4. Update Resource");
        printf("\n5. Delete Resource");
        printf("\n6. Sort Resources");
        printf("\n7. Back");

        printf("\n\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addResource();
                break;

            case 2:
                viewResource();
                break;

            case 3:
                searchResource();
                break;

            case 4:
                updateResource();
                break;

            case 5:
                deleteResource();
                break;

            case 6:
                sortResource();
                break;

            case 7:
                return;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}


/* ==============================
   ADD RESOURCE
   ============================== */

void addResource()
{
    int i;

    if(totalResource >= MAX_RESOURCE)
    {
        printf("\nResource Storage Full!\n");
        return;
    }

    printf("\nResource ID: ");
    scanf("%d", &resource[totalResource].id);

    for(i = 0; i < totalResource; i++)
    {
        if(resource[i].id == resource[totalResource].id)
        {
            printf("\nID Already Exists!\n");
            return;
        }
    }

    printf("Resource Name: ");
    scanf(" %[^\n]", resource[totalResource].name);

    printf("Category: ");
    scanf(" %[^\n]", resource[totalResource].category);

    printf("Quantity: ");
    scanf("%d", &resource[totalResource].quantity);

    printf("Unit: ");
    scanf(" %[^\n]", resource[totalResource].unit);

    totalResource++;

    printf("\nResource Added Successfully!\n");
}


/* ==============================
   VIEW RESOURCES
   ============================== */

void viewResource()
{
    int i;

    if(totalResource == 0)
    {
        printf("\nNo Resource Found.\n");
        return;
    }

    printf("\n=========== RESOURCE LIST ===========");

    for(i = 0; i < totalResource; i++)
    {
        printf("\n----------------------------------");
        printf("\nID       : %d", resource[i].id);
        printf("\nName     : %s", resource[i].name);
        printf("\nCategory : %s", resource[i].category);
        printf("\nQuantity : %d", resource[i].quantity);
        printf("\nUnit     : %s", resource[i].unit);
    }

    printf("\n----------------------------------\n");
}


/* ==============================
   SEARCH RESOURCE
   ============================== */

void searchResource()
{
    int id, i;

    printf("\nEnter Resource ID: ");
    scanf("%d", &id);

    for(i = 0; i < totalResource; i++)
    {
        if(resource[i].id == id)
        {
            printf("\nResource Found!\n");

            printf("ID       : %d\n", resource[i].id);
            printf("Name     : %s\n", resource[i].name);
            printf("Category : %s\n", resource[i].category);
            printf("Quantity : %d\n", resource[i].quantity);
            printf("Unit     : %s\n", resource[i].unit);

            return;
        }
    }

    printf("\nResource Not Found.\n");
}


/* ==============================
   UPDATE RESOURCE
   ============================== */

void updateResource()
{
    int id, i;

    printf("\nEnter Resource ID: ");
    scanf("%d", &id);

    for(i = 0; i < totalResource; i++)
    {
        if(resource[i].id == id)
        {
            printf("New Quantity: ");
            scanf("%d", &resource[i].quantity);

            printf("\nUpdated Successfully.\n");
            return;
        }
    }

    printf("\nResource Not Found.\n");
}


/* ==============================
   DELETE RESOURCE
   ============================== */

void deleteResource()
{
    int id, i, j;

    printf("\nEnter Resource ID: ");
    scanf("%d", &id);

    for(i = 0; i < totalResource; i++)
    {
        if(resource[i].id == id)
        {
            for(j = i; j < totalResource - 1; j++)
            {
                resource[j] = resource[j + 1];
            }

            totalResource--;

            printf("\nDeleted Successfully.\n");
            return;
        }
    }

    printf("\nResource Not Found.\n");
}


/* ==============================
   SORT RESOURCES
   ============================== */

void sortResource()
{
    int i, j;
    struct Resource temp;

    for(i = 0; i < totalResource - 1; i++)
    {
        for(j = i + 1; j < totalResource; j++)
        {
            if(resource[i].id > resource[j].id)
            {
                temp = resource[i];
                resource[i] = resource[j];
                resource[j] = temp;
            }
        }
    }

    printf("\nSorted Successfully.\n");
}


/* ==============================
   VICTIM MANAGEMENT
   ============================== */

void victimMenu()
{
    int choice;

    while(1)
    {
        printf("\n==============================");
        printf("\n       VICTIM MANAGEMENT");
        printf("\n==============================");

        printf("\n1. Add Victim");
        printf("\n2. View Victims");
        printf("\n3. Search Victim");
        printf("\n4. Update Victim");
        printf("\n5. Delete Victim");
        printf("\n6. Back");

        printf("\n\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addVictim();
                break;

            case 2:
                viewVictim();
                break;

            case 3:
                searchVictim();
                break;

            case 4:
                updateVictim();
                break;

            case 5:
                deleteVictim();
                break;

            case 6:
                return;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}


/* ==============================
   ADD VICTIM
   ============================== */

void addVictim()
{
    int i;

    if(totalVictim >= MAX_VICTIM)
    {
        printf("\nVictim Storage Full!\n");
        return;
    }

    printf("\nVictim ID: ");
    scanf("%d", &victim[totalVictim].id);

    for(i = 0; i < totalVictim; i++)
    {
        if(victim[i].id == victim[totalVictim].id)
        {
            printf("\nID Already Exists!\n");
            return;
        }
    }

    printf("Name: ");
    scanf(" %[^\n]", victim[totalVictim].name);

    printf("Age: ");
    scanf("%d", &victim[totalVictim].age);

    printf("Area: ");
    scanf(" %[^\n]", victim[totalVictim].area);

    printf("Family Members: ");
    scanf("%d", &victim[totalVictim].familyMembers);

    printf("Priority (High/Medium/Low): ");
    scanf(" %[^\n]", victim[totalVictim].priority);

    totalVictim++;

    printf("\nVictim Registered Successfully!\n");
}


/* ==============================
   VIEW VICTIMS
   ============================== */

void viewVictim()
{
    int i;

    if(totalVictim == 0)
    {
        printf("\nNo Victim Found.\n");
        return;
    }

    printf("\n========== VICTIM LIST ==========");

    for(i = 0; i < totalVictim; i++)
    {
        printf("\n----------------------------");
        printf("\nID             : %d", victim[i].id);
        printf("\nName           : %s", victim[i].name);
        printf("\nAge            : %d", victim[i].age);
        printf("\nArea           : %s", victim[i].area);
        printf("\nFamily Members : %d", victim[i].familyMembers);
        printf("\nPriority       : %s", victim[i].priority);
    }

    printf("\n----------------------------\n");
}


/* ==============================
   SEARCH VICTIM
   ============================== */

void searchVictim()
{
    int id, i;

    printf("\nEnter Victim ID: ");
    scanf("%d", &id);

    for(i = 0; i < totalVictim; i++)
    {
        if(victim[i].id == id)
        {
            printf("\nVictim Found!\n");

            printf("ID             : %d\n", victim[i].id);
            printf("Name           : %s\n", victim[i].name);
            printf("Age            : %d\n", victim[i].age);
            printf("Area           : %s\n", victim[i].area);
            printf("Family Members : %d\n", victim[i].familyMembers);
            printf("Priority       : %s\n", victim[i].priority);

            return;
        }
    }

    printf("\nVictim Not Found.\n");
}


/* ==============================
   UPDATE VICTIM
   ============================== */

void updateVictim()
{
    int id, i;

    printf("\nEnter Victim ID: ");
    scanf("%d", &id);

    for(i = 0; i < totalVictim; i++)
    {
        if(victim[i].id == id)
        {
            printf("New Area: ");
            scanf(" %[^\n]", victim[i].area);

            printf("New Priority: ");
            scanf(" %[^\n]", victim[i].priority);

            printf("\nVictim Updated Successfully!\n");
            return;
        }
    }

    printf("\nVictim Not Found.\n");
}


/* ==============================
   DELETE VICTIM
   ============================== */

void deleteVictim()
{
    int id, i, j;

    printf("\nEnter Victim ID: ");
    scanf("%d", &id);

    for(i = 0; i < totalVictim; i++)
    {
        if(victim[i].id == id)
        {
            for(j = i; j < totalVictim - 1; j++)
            {
                victim[j] = victim[j + 1];
            }

            totalVictim--;

            printf("\nVictim Deleted Successfully!\n");
            return;
        }
    }

    printf("\nVictim Not Found.\n");
}


/* ==============================
   VOLUNTEER MANAGEMENT
   ============================== */

void volunteerMenu()
{
    int choice;

    while(1)
    {
        printf("\n==================================");
        printf("\n      VOLUNTEER MANAGEMENT");
        printf("\n==================================");

        printf("\n1. Add Volunteer");
        printf("\n2. View Volunteers");
        printf("\n3. Search Volunteer");
        printf("\n4. Update Volunteer");
        printf("\n5. Delete Volunteer");
        printf("\n6. Back");

        printf("\n\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addVolunteer();
                break;

            case 2:
                viewVolunteer();
                break;

            case 3:
                searchVolunteer();
                break;

            case 4:
                updateVolunteer();
                break;

            case 5:
                deleteVolunteer();
                break;

            case 6:
                return;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}


/* ==============================
   ADD VOLUNTEER
   ============================== */

void addVolunteer()
{
    int i;

    if(totalVolunteer >= MAX_VOLUNTEER)
    {
        printf("\nVolunteer Storage Full!\n");
        return;
    }

    printf("\nVolunteer ID: ");
    scanf("%d", &volunteer[totalVolunteer].id);

    for(i = 0; i < totalVolunteer; i++)
    {
        if(volunteer[i].id == volunteer[totalVolunteer].id)
        {
            printf("\nID Already Exists!\n");
            return;
        }
    }

    printf("Name: ");
    scanf(" %[^\n]", volunteer[totalVolunteer].name);

    printf("Phone: ");
    scanf("%19s", volunteer[totalVolunteer].phone);

    printf("Assigned Area: ");
    scanf(" %[^\n]", volunteer[totalVolunteer].area);

    totalVolunteer++;

    printf("\nVolunteer Added Successfully!\n");
}


/* ==============================
   VIEW VOLUNTEERS
   ============================== */

void viewVolunteer()
{
    int i;

    if(totalVolunteer == 0)
    {
        printf("\nNo Volunteer Found.\n");
        return;
    }

    printf("\n=========== VOLUNTEER LIST ===========");

    for(i = 0; i < totalVolunteer; i++)
    {
        printf("\n----------------------------------");
        printf("\nID    : %d", volunteer[i].id);
        printf("\nName  : %s", volunteer[i].name);
        printf("\nPhone : %s", volunteer[i].phone);
        printf("\nArea  : %s", volunteer[i].area);
    }

    printf("\n----------------------------------\n");
}


/* ==============================
   SEARCH VOLUNTEER
   ============================== */

void searchVolunteer()
{
    int id, i;

    printf("\nEnter Volunteer ID: ");
    scanf("%d", &id);

    for(i = 0; i < totalVolunteer; i++)
    {
        if(volunteer[i].id == id)
        {
            printf("\nVolunteer Found!\n");

            printf("ID    : %d\n", volunteer[i].id);
            printf("Name  : %s\n", volunteer[i].name);
            printf("Phone : %s\n", volunteer[i].phone);
            printf("Area  : %s\n", volunteer[i].area);

            return;
        }
    }

    printf("\nVolunteer Not Found.\n");
}


/* ==============================
   UPDATE VOLUNTEER
   ============================== */

void updateVolunteer()
{
    int id, i;

    printf("\nEnter Volunteer ID: ");
    scanf("%d", &id);

    for(i = 0; i < totalVolunteer; i++)
    {
        if(volunteer[i].id == id)
        {
            printf("New Phone: ");
            scanf("%19s", volunteer[i].phone);

            printf("New Area: ");
            scanf(" %[^\n]", volunteer[i].area);

            printf("\nVolunteer Updated Successfully!\n");
            return;
        }
    }

    printf("\nVolunteer Not Found.\n");
}


/* ==============================
   DELETE VOLUNTEER
   ============================== */

void deleteVolunteer()
{
    int id, i, j;

    printf("\nEnter Volunteer ID: ");
    scanf("%d", &id);

    for(i = 0; i < totalVolunteer; i++)
    {
        if(volunteer[i].id == id)
        {
            for(j = i; j < totalVolunteer - 1; j++)
            {
                volunteer[j] = volunteer[j + 1];
            }

            totalVolunteer--;

            printf("\nVolunteer Deleted Successfully!\n");
            return;
        }
    }

    printf("\nVolunteer Not Found.\n");
}


/* ==============================
   RELIEF DISTRIBUTION
   ============================== */

void reliefMenu()
{
    int choice;

    while(1)
    {
        printf("\n==============================");
        printf("\n      RELIEF DISTRIBUTION");
        printf("\n==============================");

        printf("\n1. Allocate Relief");
        printf("\n2. Distribution History");
        printf("\n3. Back");

        printf("\n\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                allocateRelief();
                break;

            case 2:
                distributionHistory();
                break;

            case 3:
                return;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}


/* ==============================
   ALLOCATE RELIEF
   ============================== */

void allocateRelief()
{
    int victimID, resourceID, quantity;
    int i, victimFound = 0, resourceFound = 0;

    if(totalDistribution >= MAX_DISTRIBUTION)
    {
        printf("\nDistribution Storage Full!\n");
        return;
    }

    printf("\nVictim ID: ");
    scanf("%d", &victimID);

    for(i = 0; i < totalVictim; i++)
    {
        if(victim[i].id == victimID)
        {
            victimFound = 1;
            break;
        }
    }

    if(victimFound == 0)
    {
        printf("\nVictim Not Found.\n");
        return;
    }

    printf("Resource ID: ");
    scanf("%d", &resourceID);

    printf("Quantity: ");
    scanf("%d", &quantity);

    if(quantity <= 0)
    {
        printf("\nInvalid Quantity.\n");
        return;
    }

    for(i = 0; i < totalResource; i++)
    {
        if(resource[i].id == resourceID)
        {
            resourceFound = 1;

            if(resource[i].quantity >= quantity)
            {
                resource[i].quantity -= quantity;

                distribution[totalDistribution].victimID = victimID;
                distribution[totalDistribution].resourceID = resourceID;
                distribution[totalDistribution].quantity = quantity;

                totalDistribution++;

                printf("\nRelief Distributed Successfully!\n");

                if(resource[i].quantity <= 10)
                {
                    printf("\n*** LOW STOCK WARNING ***\n");
                }
            }
            else
            {
                printf("\nNot Enough Stock!\n");
            }

            break;
        }
    }

    if(resourceFound == 0)
    {
        printf("\nResource Not Found.\n");
    }
}


/* ==============================
   DISTRIBUTION HISTORY
   ============================== */

void distributionHistory()
{
    int i;

    if(totalDistribution == 0)
    {
        printf("\nNo Distribution History.\n");
        return;
    }

    printf("\n========== DISTRIBUTION HISTORY ==========");

    for(i = 0; i < totalDistribution; i++)
    {
        printf("\n--------------------------------------");
        printf("\nVictim ID   : %d", distribution[i].victimID);
        printf("\nResource ID : %d", distribution[i].resourceID);
        printf("\nQuantity    : %d", distribution[i].quantity);
    }

    printf("\n--------------------------------------\n");
}


/* ==============================
   REPORTS AND STATISTICS
   ============================== */

void reportMenu()
{
    int choice;

    while(1)
    {
        printf("\n=================================");
        printf("\n      REPORTS & STATISTICS");
        printf("\n=================================");

        printf("\n1. Total Resources");
        printf("\n2. Total Victims");
        printf("\n3. Total Volunteers");
        printf("\n4. Stock Report");
        printf("\n5. System Summary");
        printf("\n6. Back");

        printf("\n\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                totalResourcesReport();
                break;

            case 2:
                totalVictimsReport();
                break;

            case 3:
                totalVolunteersReport();
                break;

            case 4:
                stockReport();
                break;

            case 5:
                systemSummary();
                break;

            case 6:
                return;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}


/* ==============================
   TOTAL RESOURCES REPORT
   ============================== */

void totalResourcesReport()
{
    printf("\n========== RESOURCE REPORT ==========");
    printf("\nTotal Resource Types: %d\n", totalResource);
}


/* ==============================
   TOTAL VICTIMS REPORT
   ============================== */

void totalVictimsReport()
{
    printf("\n========== VICTIM REPORT ==========");
    printf("\nTotal Registered Victims: %d\n", totalVictim);
}


/* ==============================
   TOTAL VOLUNTEERS REPORT
   ============================== */

void totalVolunteersReport()
{
    printf("\n========== VOLUNTEER REPORT ==========");
    printf("\nTotal Volunteers: %d\n", totalVolunteer);
}


/* ==============================
   STOCK REPORT
   ============================== */

void stockReport()
{
    int i;

    printf("\n============= STOCK REPORT =============");

    if(totalResource == 0)
    {
        printf("\nNo Resources Available.\n");
        return;
    }

    for(i = 0; i < totalResource; i++)
    {
        printf("\n--------------------------------");
        printf("\nID       : %d", resource[i].id);
        printf("\nName     : %s", resource[i].name);
        printf("\nQuantity : %d %s",
               resource[i].quantity,
               resource[i].unit);

        if(resource[i].quantity <= 10)
        {
            printf("\nStatus   : LOW STOCK");
        }
        else
        {
            printf("\nStatus   : AVAILABLE");
        }
    }

    printf("\n--------------------------------\n");
}


/* ==============================
   SYSTEM SUMMARY DASHBOARD
   ============================== */

void systemSummary()
{
    printf("\n====================================");
    printf("\n      DISASTER RELIEF DASHBOARD");
    printf("\n====================================");

    printf("\nTotal Resources    : %d", totalResource);
    printf("\nTotal Victims      : %d", totalVictim);
    printf("\nTotal Volunteers   : %d", totalVolunteer);
    printf("\nRelief Distributed : %d", totalDistribution);

    printf("\n====================================\n");
}


/* ==============================
   SAVE RESOURCES
   ============================== */

void saveResources()
{
    FILE *fp;

    fp = fopen("resources.dat", "wb");

    if(fp == NULL)
    {
        printf("\nFile Error!\n");
        return;
    }

    fwrite(resource,
           sizeof(struct Resource),
           totalResource,
           fp);

    fclose(fp);
}


/* ==============================
   LOAD RESOURCES
   ============================== */

void loadResources()
{
    FILE *fp;

    fp = fopen("resources.dat", "rb");

    if(fp == NULL)
    {
        return;
    }

    totalResource =
    fread(resource,
          sizeof(struct Resource),
          MAX_RESOURCE,
          fp);

    fclose(fp);
}


/* ==============================
   SAVE VICTIMS
   ============================== */

void saveVictims()
{
    FILE *fp;

    fp = fopen("victims.dat", "wb");

    if(fp == NULL)
    {
        return;
    }

    fwrite(victim,
           sizeof(struct Victim),
           totalVictim,
           fp);

    fclose(fp);
}


/* ==============================
   LOAD VICTIMS
   ============================== */

void loadVictims()
{
    FILE *fp;

    fp = fopen("victims.dat", "rb");

    if(fp == NULL)
    {
        return;
    }

    totalVictim =
    fread(victim,
          sizeof(struct Victim),
          MAX_VICTIM,
          fp);

    fclose(fp);
}


/* ==============================
   SAVE VOLUNTEERS
   ============================== */

void saveVolunteers()
{
    FILE *fp;

    fp = fopen("volunteers.dat", "wb");

    if(fp == NULL)
    {
        return;
    }

    fwrite(volunteer,
           sizeof(struct Volunteer),
           totalVolunteer,
           fp);

    fclose(fp);
}


/* ==============================
   LOAD VOLUNTEERS
   ============================== */

void loadVolunteers()
{
    FILE *fp;

    fp = fopen("volunteers.dat", "rb");

    if(fp == NULL)
    {
        return;
    }

    totalVolunteer =
    fread(volunteer,
          sizeof(struct Volunteer),
          MAX_VOLUNTEER,
          fp);

    fclose(fp);
}


/* ==============================
   MAIN FUNCTION
   ============================== */

int main()
{
    loadResources();
    loadVictims();
    loadVolunteers();

    login();

    return 0;
}
