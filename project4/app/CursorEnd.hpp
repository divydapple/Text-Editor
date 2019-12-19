#ifndef CURSOREND_HPP
#define CURSOREND_HPP
#include "EditorModel.hpp"
#include "Command.hpp"


class CursorEnd : public Command
{
  public:

  void execute(EditorModel& model);
  void undo(EditorModel& model);

private:
  int prevcol;
};



#endif
