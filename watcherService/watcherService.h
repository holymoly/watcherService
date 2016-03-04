// ----------------------------------------------------------------------
// Funktions-Prototypen
// ----------------------------------------------------------------------

// Dateisystem
char *make_family_filename(char *filename, unsigned int size, char *ext);
char *make_app_filename(char *appfilename, unsigned int size, char *filename);

// Erstellt einen zu diesem Programm zugehoerigen Dateinamen
// mit der angegebenen Erweiterung.
// filename: Puffer zur Aufnahme des Dateinamens
// ext     : Erweiterung fuer Dateiname
char *make_family_filename(char *filename, unsigned int size, char *ext)
{
	GetModuleFileName(NULL, filename, size);
	strcpy(filename + strlen(filename) - 3, ext);
	return filename;
}

// Erzeugt einen Dateinamen mit dem Verzeichnis der
// Programmdatei als Basisverzeichnis
// appfilename: Zeiger auf einen Puffer, in dem der Dateiname erzeugt werden soll
// size       : Puffergroesse
char *make_app_filename(char *appfilename, unsigned int size, char *filename)
{	
	char *p = NULL;
	GetModuleFileName(NULL, appfilename, size);
	p = strrchr(appfilename, '\\');
	strcpy(p + 1, filename);
	return appfilename;
}