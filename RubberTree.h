#ifndef RUBBERTREE_H
#define RUBBERTREE_H

#include "Indoor.h"
#include "MediumMoisture.h"
#include "Thinning.h"

class RubberTree : public Indoor {

public:
	RubberTree() : Indoor(300, new MediumMoisture(), new Thinning(), "Rubber Tree") {}
};

#endif
