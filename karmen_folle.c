#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define MAX_TONTINES 50
#define MAX_LOANS 100
#define NAME_LENGTH 50
#define CONTACT_LENGTH 50
#define DATE_LENGTH 11

typedef struct {
    int id;
    char firstName[NAME_LENGTH];
    char lastName[NAME_LENGTH];
    char contact[CONTACT_LENGTH];
    float balance;
} Member;

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float contributionAmount;
    int frequency; // 1: weekly, 2: bi-weekly, 3: monthly
    int active;
} Tontine;

typedef struct {
    int id;
    int memberId;
    int tontineId;
    float amount;
    float interest;
    char dueDate[DATE_LENGTH];
    int paid;
} Loan;

Member members[MAX_MEMBERS];
Tontine tontines[MAX_TONTINES];
Loan loans[MAX_LOANS];
int memberCount = 0, tontineCount = 0, loanCount = 0;

void saveData();
void loadData();
void addMember();
void modifyMember();
void deleteMember();
void searchMember();
void viewMemberHistory();
void createTontine();
void modifyTontine();
void closeTontine();
void addMemberToTontine();
void createLoan();
void generateReports();
void displayMenu();

int main() {
    loadData();
    displayMenu();
    saveData();
    return 0;
}

void saveData() {
    FILE *file = fopen("data.bin", "wb");
    fwrite(members, sizeof(Member), memberCount, file);
    fwrite(tontines, sizeof(Tontine), tontineCount, file);
    fwrite(loans, sizeof(Loan), loanCount, file);
    fclose(file);
}

void loadData() {
    FILE *file = fopen("data.bin", "rb");
    if (file) {
        memberCount = fread(members, sizeof(Member), MAX_MEMBERS, file);
        tontineCount = fread(tontines, sizeof(Tontine), MAX_TONTINES, file);
        loanCount = fread(loans, sizeof(Loan), MAX_LOANS, file);
        fclose(file);
    }
}

void addMember() {
    if (memberCount < MAX_MEMBERS) {
        Member newMember;
        newMember.id = memberCount + 1;
        printf("Enter first name: ");
        scanf("%s", newMember.firstName);
        printf("Enter last name: ");
        scanf("%s", newMember.lastName);
        printf("Enter contact: ");
        scanf("%s", newMember.contact);
        newMember.balance = 0.0;
        members[memberCount++] = newMember;
        printf("Member added successfully.\n");
    } else {
        printf("Member limit reached.\n");
    }
}

void modifyMember() {
    int id;
    printf("Enter member ID to modify: ");
    scanf("%d", &id);
    if (id > 0 && id <= memberCount) {
        printf("Enter new first name: ");
        scanf("%s", members[id - 1].firstName);
        printf("Enter new last name: ");
        scanf("%s", members[id - 1].lastName);
        printf("Enter new contact: ");
        scanf("%s", members[id - 1].contact);
        printf("Member modified successfully.\n");
    } else {
        printf("Invalid member ID.\n");
    }
}

void deleteMember() {
    int id;
    printf("Enter member ID to delete: ");
    scanf("%d", &id);
    if (id > 0 && id <= memberCount) {
        for (int i = id - 1; i < memberCount - 1; i++) {
            members[i] = members[i + 1];
        }
        memberCount--;
        printf("Member deleted successfully.\n");
    } else {
        printf("Invalid member ID.\n");
    }
}

void searchMember() {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);
    for (int i = 0; i < memberCount; i++) {
        if (strstr(members[i].firstName, name) || strstr(members[i].lastName, name)) {
            printf("ID: %d, Name: %s %s, Contact: %s, Balance: %.2f\n", 
                   members[i].id, members[i].firstName, members[i].lastName, 
                   members[i].contact, members[i].balance);
        }
    }
}

void viewMemberHistory() {
    // Placeholder for member history functionality
    printf("Member history feature not implemented yet.\n");
}

void createTontine() {
    if (tontineCount < MAX_TONTINES) {
        Tontine newTontine;
        newTontine.id = tontineCount + 1;
        printf("Enter tontine name: ");
        scanf("%s", newTontine.name);
        printf("Enter contribution amount: ");
        scanf("%f", &newTontine.contributionAmount);
        printf("Enter frequency (1: weekly, 2: bi-weekly, 3: monthly): ");
        scanf("%d", &newTontine.frequency);
        newTontine.active = 1;
        tontines[tontineCount++] = newTontine;
        printf("Tontine created successfully.\n");
    } else {
        printf("Tontine limit reached.\n");
    }
}

void modifyTontine() {
    int id;
    printf("Enter tontine ID to modify: ");
    scanf("%d", &id);
    if (id > 0 && id <= tontineCount) {
        printf("Enter new tontine name: ");
        scanf("%s", tontines[id - 1].name);
        printf("Enter new contribution amount: ");
        scanf("%f", &tontines[id - 1].contributionAmount);
        printf("Enter new frequency (1: weekly, 2: bi-weekly, 3: monthly): ");
        scanf("%d", &tontines[id - 1].frequency);
        printf("Tontine modified successfully.\n");
    } else {
        printf("Invalid tontine ID.\n");
    }
}

void closeTontine() {
    int id;
    printf("Enter tontine ID to close: ");
    scanf("%d", &id);
    if (id > 0 && id <= tontineCount) {
        tontines[id - 1].active = 0;
        printf("Tontine closed successfully.\n");
    } else {
        printf("Invalid tontine ID.\n");
    }
}

void addMemberToTontine() {
    // Placeholder for adding member to tontine functionality
    printf("Add member to tontine feature not implemented yet.\n");
}

void createLoan() {
    // Placeholder for loan creation functionality
    printf("Create loan feature not implemented yet.\n");
}

void generateReports() {
    // Placeholder for report generation functionality
    printf("Report generation feature not implemented yet.\n");
}

void displayMenu() {
    int choice;
    do {
        printf("\n--- Tontine Management System ---\n");
        printf("1. Add Member\n");
        printf("2. Modify Member\n");
        printf("3. Delete Member\n");
        printf("4. Search Member\n");
        printf("5. View Member History\n");
        printf("6. Create Tontine\n");
        printf("7. Modify Tontine\n");
        printf("8. Close Tontine\n");
        printf("9. Create Loan\n");
        printf("10. Generate Reports\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addMember(); break;
            case 2: modifyMember(); break;
            case 3: deleteMember(); break;
            case 4: searchMember(); break;
            case 5: viewMemberHistory(); break;
            case 6: createTontine(); break;
            case 7: modifyTontine(); break;
            case 8: closeTontine(); break;
            case 9: createLoan(); break;
            case 10: generateReports(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}