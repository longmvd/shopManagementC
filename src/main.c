#include <stdio.h>
// #include "login.h"   // Assume login module exists
#include "catalog.h" // Catalog module for catalog management

#define CATALOG_FILENAME "catalog.dat"

void catalogMenu()
{
    int choice, id;
    Catalog cat, foundCat;

    do
    {
        printf("\n=== Catalog Management Menu ===\n");
        printf("1. Add Catalog\n");
        printf("2. List Catalogs\n");
        printf("3. Update Catalog\n");
        printf("4. Delete Catalog\n");
        printf("5. Search Catalog\n");
        printf("6. Save Catalogs to File\n");
        printf("7. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter catalog ID: ");
            scanf("%d", &cat.id);
            printf("Enter catalog name: ");
            scanf("%s", cat.name);
            printf("Enter catalog description: ");
            scanf(" %[^\n]", cat.description);
            addCatalog(cat);
            break;
        case 2:
            listCatalogs();
            break;
        case 3:
            printf("Enter catalog ID to update: ");
            scanf("%d", &id);
            printf("Enter new catalog name: ");
            scanf("%s", cat.name);
            printf("Enter new catalog description: ");
            scanf(" %[^\n]", cat.description);
            cat.id = id;
            updateCatalog(id, cat);
            break;
        case 4:
            printf("Enter catalog ID to delete: ");
            scanf("%d", &id);
            deleteCatalog(id);
            break;
        case 5:
            printf("Enter catalog ID to search: ");
            scanf("%d", &id);
            if (searchCatalog(id, &foundCat))
            {
                printf("Catalog Found:\n");
                printf("ID: %d, Name: %s, Description: %s\n",
                       foundCat.id, foundCat.name, foundCat.description);
            }
            else
            {
                printf("Catalog with ID %d not found.\n", id);
            }
            break;
        case 6:
            if (saveCatalogs(CATALOG_FILENAME))
            {
                printf("Catalogs saved successfully.\n");
            }
            else
            {
                printf("Failed to save catalogs.\n");
            }
            break;
        case 7:
            printf("Returning to main menu...\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
        }
    } while (choice != 7);
}

int main()
{
    int choice;

    // Assume login is required first
    // if (!login())
    // {
    //     return 1;
    // }

    /* Load catalogs from file at startup */
    loadCatalogs(CATALOG_FILENAME);

    do
    {
        printf("\n=== Main Menu ===\n");
        printf("1. Catalog Management\n");
        printf("2. Save Catalogs to File\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            catalogMenu();
            break;
        case 2:
            if (saveCatalogs(CATALOG_FILENAME))
            {
                printf("Catalogs saved successfully.\n");
            }
            else
            {
                printf("Failed to save catalogs.\n");
            }
            break;
        case 3:
            printf("Exiting system. Goodbye!\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
