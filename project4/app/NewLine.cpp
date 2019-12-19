
#include "NewLine.hpp"
#include <string>

void NewLine::execute(EditorModel& model)
{
  s = model.line(model.cursorLine());
  std::string newl = s.substr(model.cursorColumn()-1,s.size());
  model.setLineText(s.substr(0,model.cursorColumn()-1));
  cursorpos = model.cursorColumn();
  model.insertIntoVector(model.cursorLine(), newl);
  model.incrementLine();
  model.setColumn(1);
}

void NewLine::undo(EditorModel& model)
{
  model.decrementLine();
  model.setColumn(cursorpos);
  model.setLineText(s);
  model.removeFromVector(model.cursorLine());
}
