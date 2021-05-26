#include "pch.h"
#using "../PostLibrary/Post.dll"

using namespace System;

void ServerPersistence::Send(Event* e)
{
	string ev = serializerObject->serialize(e);
	String^ str = gcnew String(ev.c_str());
	try {
		Post::PostEvent().Post(str, "http://localhost:8080/tracker");
	}
	catch (int e) {
		cout << "Casi" << endl;
	}
}

void ServerPersistence::Flush()
{
	//Borrar los datos de telemetría del servidor
}
