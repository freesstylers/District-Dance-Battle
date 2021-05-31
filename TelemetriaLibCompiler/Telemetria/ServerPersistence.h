#pragma once
#include "Persistence.h"
class ServerPersistence :public Persistence
{
public:
	ServerPersistence() {
	};
	virtual void Send(Event* e);
	virtual void Flush();
	virtual void Open();
	virtual void Close();
};