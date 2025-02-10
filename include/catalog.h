#ifndef CATALOG_H
#define CATALOG_H

/* Define a Catalog structure */
typedef struct
{
  int id;                // Unique catalog identifier
  char name[100];        // Catalog name
  char description[255]; // Catalog description
} Catalog;

/* Maximum number of catalogs supported */
#define MAX_CATALOGS 50

/* Global variables (defined in catalog.c) */
extern Catalog catalogs[MAX_CATALOGS];
extern int catalogCount;

/* CRUD Function Prototypes */
int addCatalog(Catalog c);
void listCatalogs(void);
int updateCatalog(int catalogId, Catalog newCatalog);
int deleteCatalog(int catalogId);
int searchCatalog(int catalogId, Catalog *result);

/* File I/O Function Prototypes */
/**
 * saveCatalogs:
 * Saves the entire catalog list to a file in binary mode.
 * The file format starts with an integer indicating the number of catalog entries,
 * followed by an array of Catalog structures.
 * Returns 1 on success, 0 on failure.
 */
int saveCatalogs(const char *filename);

/**
 * loadCatalogs:
 * Loads the catalog list from a binary file.
 * If the file does not exist, catalogCount is set to 0.
 * Returns 1 on success, 0 on failure.
 */
int loadCatalogs(const char *filename);

#endif /* CATALOG_H */
