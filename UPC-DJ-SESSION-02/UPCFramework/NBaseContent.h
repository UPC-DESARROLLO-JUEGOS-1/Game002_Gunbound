#pragma once

#include <string>

// forward declaration, esto es para evitar dependencias circulares
class NContentManagement;

class NBaseContent
{
public:
	NBaseContent(NContentManagement* contentManagment) { 
		mContentManagment = contentManagment;
	}
	~NBaseContent();

	virtual void Initialize() {}
	virtual bool Load(const std::string path) {
		mPath = path;
		return true;
	}

	std::string GetPath() { mPath; }
	NContentManagement* GetContentManagment() { return mContentManagment; }

protected:
	std::string mPath;
	NContentManagement *mContentManagment;
};

