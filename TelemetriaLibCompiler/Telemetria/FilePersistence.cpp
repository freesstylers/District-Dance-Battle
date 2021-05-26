#include "pch.h"

FilePersistence::FilePersistence(string filePath)
{
	file_.open(filePath, std::fstream::app);
}

void FilePersistence::Send(Event* e)
{
	string ev = serializerObject->serialize(e);
	file_<< ev <<"\n";
}

void FilePersistence::Close() 
{
	file_.close();
}

void FilePersistence::Flush()
{
	//Borrar el fichero que contiene los eventos
}
