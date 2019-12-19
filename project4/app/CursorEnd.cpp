#include "CursorEnd.hpp"

void CursorEnd::execute(EditorModel& model)
{
  prevcol = model.cursorColumn();
  model.setColumn(model.line(model.cursorLine()).length() + 1);
}

void CursorEnd::undo(EditorModel& model)
{
  model.setColumn(prevcol);
}
