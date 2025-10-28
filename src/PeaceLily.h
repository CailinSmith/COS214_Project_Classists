/**
 * @file PeaceLily.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef PEACELILY_H
#define PEACELILY_H

#include "Indoor.h"
#include "HighMoisture.h"
#include "DeadPruning.h"

class PeaceLily : public Indoor {

public:
	PeaceLily() : Indoor(120, new HighMoisture(), new DeadPruning(), "Peace Lily", "Spring") {}
};

#endif
