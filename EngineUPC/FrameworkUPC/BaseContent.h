#pragma once

#include <string>
//Forward declaration
class ContentManager;

class BaseContent
{
public:
	BaseContent(ContentManager* contentManager) { this->contentManager = contentManager; }
	~BaseContent() {}

	virtual void Initialize() {};
	virtual bool Load(std::string path)
	{
		this->path = path;
		return true;
	}
	std::string GetPath() { return path; }
	ContentManager* GetContentManager() { return contentManager; }
protected:
	std::string path;
	ContentManager *contentManager;
};