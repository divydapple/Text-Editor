#ifndef BACKSPACE_HPP
#define BACKSPACE_HPP
#include "EditorModel.hpp"
#include "Command.hpp"
#include <string>


class Backspace : public Command
{
  public:
  Backspace();
  void execute(EditorModel& model);
  void undo(EditorModel& model);

private:
  int textsize;
  char character;
  std::string prevl;
  std::string currl;
  bool lineDeleted;
  int col;
  int line;
};



#endif
