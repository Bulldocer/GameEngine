#include "Singleton.h"
class ObjectManager : public Singleton<ObjectManager>
{
	friend class Singleton<ObjectManager>;
private:
	ObjectManager();
	~ObjectManager();
};

