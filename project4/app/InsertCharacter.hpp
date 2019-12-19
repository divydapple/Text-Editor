#ifndef INSERTCHARACTER_HPP
#define INSERTCHARACTER_HPP
#include "EditorModel.hpp"
#include "Command.hpp"


class InsertCharacter : public Command
{
public:
  InsertCharacter(char c);
  void execute(EditorModel& model);
  void undo(EditorModel& model);

private:
  char character;
  std::string s;
};



#endif
