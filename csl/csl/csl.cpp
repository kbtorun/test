// csl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sqlite3.h"


static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for (i = 0; i<argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;

}

int main()
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	rc = sqlite3_open("c:\\testy\\test\\baza.sqlite", &db);
	if (rc) 
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return(1);
	}
	rc = sqlite3_exec(db, "select * from testy", callback, 0, &zErrMsg);
	if (rc != SQLITE_OK) 
	{
		     fprintf(stderr, "SQL error: %s\n", zErrMsg);
		     sqlite3_free(zErrMsg);
		
	}
	   sqlite3_close(db);
	return 0;
}