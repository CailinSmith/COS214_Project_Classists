#include "AskInfoCommand.h"

AskInfoCommand::AskInfoCommand(Staff* s, Plant* p) : CustomerCommand(s, p, nullptr, nullptr){}

pair<string, Receipt*> AskInfoCommand::execute(){
    if(staff && plant){
        return staff->handleRequest("AskInfo", plant, nullptr, nullptr);
    }
    pair<string, Receipt*> result;
    result.first = "No staff assigned\n";
    result.second = nullptr;
    return result;
}
