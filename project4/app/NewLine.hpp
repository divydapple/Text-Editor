#ifndef NEWLINE_HPP
#define NEWLINE_HPP
#include "EditorModel.hpp"
#include "Command.hpp"


class NewLine : public Command
{
  public:

  void execute(EditorModel& model);
  void undo(EditorModel& model);

private:
  std::string s;
  int cursorpos;
};



#endif
