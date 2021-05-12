#include "pch.h"



FilePersistence::FilePersistence(string filePath)
{
	file_.open(filePath, std::fstream::app);
}

void FilePersistence::Send(Event* e)
{
	
	file_<<serializerObject->serialize(e)<<"\n";
}

void FilePersistence::Close() 
{
	file_.close();
}

void FilePersistence::Flush()
{
	//Borrar el fichero que contiene los eventos
}
