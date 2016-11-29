#include "Singleton.h"
class SoundManager : public Singleton<SoundManager>
{
	friend class Singleton<SoundManager>;
private:
	SoundManager();
	~SoundManager();
};

