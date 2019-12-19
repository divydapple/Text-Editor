#ifndef CURSORDOWN_HPP
#define CURSORDOWN_HPP
#include "EditorModel.hpp"
#include "Command.hpp"


class CursorDown : public Command
{
  public:

  void execute(EditorModel& model);
  void undo(EditorModel& model);

private:
  int col;
  int lin;
};



#endif
