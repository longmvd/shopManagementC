#include <stdio.h>
#include <string.h>
#include "catalog.h"
#include "utils.h" // For safeOpenFile()

/* Global array to hold catalog records and counter */
Catalog catalogs[MAX_CATALOGS];
int catalogCount = 0;

int addCatalog(Catalog c)
{
  if (catalogCount >= MAX_CATALOGS)
  {
    printf("Catalog list is full. Cannot add more catalogs.\n");
    return 0;
  }
  catalogs[catalogCount++] = c;
  printf("Catalog added successfully.\n");
  return 1;
}

void listCatalogs(void)
{
  if (catalogCount == 0)
  {
    printf("No catalogs available.\n");
    return;
  }
  printf("Catalog List:\n");
  printf("ID\tName\t\tDescription\n");
  printf("---------------------------------------------\n");
  for (int i = 0; i < catalogCount; i++)
  {
    printf("%d\t%-10s\t%s\n",
           catalogs[i].id,
           catalogs[i].name,
           catalogs[i].description);
  }
}

int updateCatalog(int catalogId, Catalog newCatalog)
{
  for (int i = 0; i < catalogCount; i++)
  {
    if (catalogs[i].id == catalogId)
    {
      catalogs[i] = newCatalog;
      printf("Catalog with ID %d updated successfully.\n", catalogId);
      return 1;
    }
  }
  printf("Catalog with ID %d not found.\n", catalogId);
  return 0;
}

int deleteCatalog(int catalogId)
{
  for (int i = 0; i < catalogCount; i++)
  {
    if (catalogs[i].id == catalogId)
    {
      for (int j = i; j < catalogCount - 1; j++)
      {
        catalogs[j] = catalogs[j + 1];
      }
      catalogCount--;
      printf("Catalog with ID %d deleted successfully.\n", catalogId);
      return 1;
    }
  }
  printf("Catalog with ID %d not found.\n", catalogId);
  return 0;
}

int searchCatalog(int catalogId, Catalog *result)
{
  for (int i = 0; i < catalogCount; i++)
  {
    if (catalogs[i].id == catalogId)
    {
      if (result != NULL)
      {
        *result = catalogs[i];
      }
      return 1;
    }
  }
  return 0;
}

/* Save the entire catalog list to a binary file */
int saveCatalogs(const char *filename)
{
  FILE *fp = safeOpenFile(filename, "wb"); // Use safeOpenFile from utils.c
  if (!fp)
  {
    perror("Error opening file for writing catalogs");
    return 0;
  }
  /* First write the number of catalog entries */
  if (fwrite(&catalogCount, sizeof(int), 1, fp) != 1)
  {
    fclose(fp);
    return 0;
  }
  /* Write the catalog array */
  size_t written = fwrite(catalogs, sizeof(Catalog), catalogCount, fp);
  fclose(fp);
  if (written != catalogCount)
  {
    printf("Error writing catalog data to file.\n");
    return 0;
  }
  return 1;
}

/* Load the catalog list from a binary file */
int loadCatalogs(const char *filename)
{
  FILE *fp = fopen(filename, "rb"); // We can use fopen here since missing file is not fatal
  if (!fp)
  {
    printf("Catalog file not found, starting with an empty catalog.\n");
    catalogCount = 0;
    return 0;
  }
  if (fread(&catalogCount, sizeof(int), 1, fp) != 1)
  {
    fclose(fp);
    return 0;
  }
  size_t read = fread(catalogs, sizeof(Catalog), catalogCount, fp);
  fclose(fp);
  if (read != catalogCount)
  {
    printf("Error reading catalog data from file.\n");
    return 0;
  }
  return 1;
}
