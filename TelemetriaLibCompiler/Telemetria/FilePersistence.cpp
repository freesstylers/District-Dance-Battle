#include "pch.h"
#using "../PostLibrary/Post.dll"
using namespace System;

FilePersistence::FilePersistence(string filePath)
{
	file_.open(filePath, std::fstream::app);
}

void FilePersistence::Send(Event* e)
{
	string ev = serializerObject->serialize(e);
	file_<< ev <<"\n";
	String^ str = gcnew String(ev.c_str());
	try {
		Post::PostEvent().Post(str, "http://localhost:8080/tracker");
	}
	catch (int e) {
		cout << "Casi" << endl;
	}

}

void FilePersistence::Close() 
{
	file_.close();
}

void FilePersistence::Flush()
{
	//Borrar el fichero que contiene los eventos
}
