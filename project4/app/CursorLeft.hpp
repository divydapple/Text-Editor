#ifndef CURSORLEFT_HPP
#define CURSORLEFT_HPP
#include "EditorModel.hpp"
#include "Command.hpp"


class CursorLeft : public Command
{
  public:

  void execute(EditorModel& model);
  void undo(EditorModel& model);

};



#endif
