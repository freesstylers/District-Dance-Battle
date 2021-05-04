#include "FilePersistence.h"


FilePersistence::FilePersistence(string filePath)
{
	file_.open(filePath);
}

void FilePersistence::Send(Event* e)
{
	
	file_<<serializerObject->serialize(e);

}

void FilePersistence::Flush()
{
	//Borrar el fichero que contiene los eventos
}
