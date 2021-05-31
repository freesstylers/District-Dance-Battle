#include "pch.h"
#include <cstdio>

FilePersistence::FilePersistence(string filePath)
{
	file_.open(filePath, std::fstream::app);
	filepath_ = filePath;
}

string changeExtension(string completePath, string extension) {
	int size = completePath.size();
	int i;
	for (i = size - 1; i >= 0; i--) {
		if (completePath[i] == '.') {
			break;
		}
	}
	int pathSize = i;
	string ret = "";
	for (int j = 0; j < pathSize; j++) {
		ret.push_back(completePath[j]);
	}
	for (int j = 0; j < extension.size(); j++) {
		ret.push_back(extension[j]);
	}
	return ret;
}

void FilePersistence::Send(Event* e)
{
	string ev = serializerObject->serialize(e);
	file_<< ev <<"\n";
}

std::string getLastLine(std::ifstream& in)
{
    std::string line;
    while (in >> std::ws&& std::getline(in, line))
        ;

    return line;
}

void removeLastLine(std::ifstream& in, string newpath, string ogpath) {
    std::ofstream out;
	out.open(newpath);

    std::string line;
    getline(in, line);
    for (std::string tmp; getline(in, tmp); line.swap(tmp)) {
        out << line << '\n';
    }

	out.close();
	in.close();
	const char* og = ogpath.c_str();
	const char* n = newpath.c_str();
	remove(og);
	rename(n, og);
}

void FilePersistence::Open()
{
	string line;
	ifstream ifile;
	ifile.open(filepath_);
	getline(ifile, line);
	if (line != "<Root>")
		file_ << serializerObject->openSerialization();

	if (getLastLine(ifile) == "</Root>") {
		file_.close();
		ifile.close();
		ifile.open(filepath_);
		removeLastLine(ifile, changeExtension(filepath_, ".tmp"), filepath_);
		file_.open(filepath_, std::fstream::app);
	}
}

void FilePersistence::Close() 
{
	file_<<serializerObject->closeSerialization();
	file_.close();
}

void FilePersistence::Flush()
{
	//Borrar el fichero que contiene los eventos
}

