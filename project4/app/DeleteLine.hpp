#ifndef DELETELINE_HPP
#define DELETELINE_HPP
#include "EditorModel.hpp"
#include "Command.hpp"
#include <string>


class DeleteLine : public Command
{
  public:

  void execute(EditorModel& model);
  void undo(EditorModel& model);

private:
  int currentline;
  int currentcolumn;
  std::string currl;
  std::string prevl;
  int casenum;
  int prevCursCol;
};



#endif
