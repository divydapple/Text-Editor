#ifndef CURSORRIGHT_HPP
#define CURSORRIGHT_HPP
#include "EditorModel.hpp"
#include "Command.hpp"


class CursorRight : public Command
{
  public:

  void execute(EditorModel& model);
  void undo(EditorModel& model);
};



#endif
