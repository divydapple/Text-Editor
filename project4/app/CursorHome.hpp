#ifndef CURSORHOME_HPP
#define CURSORHOME_HPP
#include "EditorModel.hpp"
#include "Command.hpp"


class CursorHome : public Command
{
  public:

  void execute(EditorModel& model);
  void undo(EditorModel& model);

private:
  int prevcol;
};



#endif
