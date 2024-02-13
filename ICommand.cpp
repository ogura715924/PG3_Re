#include "ICommand.h"
#include "Player.h"

ICommand::~ICommand() {}

void RightCommand::Exec(Player& player) { player.MoveRight(); }

void LeftCommand::Exec(Player& player) { player.MoveLeft(); }

void UpCommand::Exec(Player& player) { player.MoveUp(); }

void DownCommand::Exec(Player& player) { player.MoveDown(); }