#include "PersonalComputer.h"
#include "Program.h"

void PersonalComputer::assumeNetworkMessage(Program *program)
{
    program->run(this);
}

void PersonalComputer::assumeNetworkMessage(Data *data)
{
}

