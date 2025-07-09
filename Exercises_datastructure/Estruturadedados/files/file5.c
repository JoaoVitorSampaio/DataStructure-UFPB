#include <stdio.h>
#include <string.h>

#define SIZE_NAME 50

int main() {
    FILE *f1, *f2, *f3, *db;
    char name[SIZE_NAME], sex;
    int age;

    f1 = fopen("names.txt", "r");
    if (f1 == NULL) {
        printf("Error opening name file\n");
        return 1;
    }

    f2 = fopen("ages.txt", "r");
    if (f2 == NULL) {
        printf("Error opening age file\n");
        fclose(f1);
        return 1;
    }

    f3 = fopen("sex.txt", "r");
    if (f3 == NULL) {
        printf("Error opening sex file\n");
        fclose(f1);
        fclose(f2);
        return 1;
    }

    db = fopen("database.txt", "w");
    if (db == NULL) {
        printf("Error opening database file\n");
        fclose(f1);
        fclose(f2);
        fclose(f3);
        return 1;
    }

    while (fgets(name, sizeof(name), f1) != NULL) {
        // Remove newline character from name if present
        name[strcspn(name, "\n")] = '\0';
        fscanf(f2, "%d", &age);
        fscanf(f3, " %c", &sex);
        fprintf(db, "%s %d %c\n", name, age, sex);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(db);

    printf("Data successfully merged into database.txt\n");

    return 0;
}