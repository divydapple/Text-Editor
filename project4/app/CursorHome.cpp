#include "CursorHome.hpp"



void CursorHome::execute(EditorModel& model)
{
  prevcol = model.cursorColumn();
  model.setColumn(1);
}

void CursorHome::undo(EditorModel& model)
{
  model.setColumn(prevcol);
}
