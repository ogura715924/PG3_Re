#pragma once

class Player;

class ICommand {
public:
	virtual ~ICommand();
	virtual void Exec(Player& player) = 0;
};

class RightCommand : public ICommand {
public:
	void Exec(Player& player) override;
};
class LeftCommand : public ICommand {
public:
	void Exec(Player& player) override;
};
class UpCommand : public ICommand {
public:
	void Exec(Player& player) override;
};
class DownCommand : public ICommand {
public:
	void Exec(Player& player) override;
};