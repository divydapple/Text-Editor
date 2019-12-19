#ifndef CURSORUP_HPP
#define CURSORUP_HPP
#include "EditorModel.hpp"
#include "Command.hpp"


class CursorUp : public Command
{
  public:

  void execute(EditorModel& model);
  void undo(EditorModel& model);

private:
  int col;
  int lin;
};



#endif
