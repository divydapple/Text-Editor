#include "CursorUp.hpp"
#include "EditorException.hpp"

void CursorUp::execute(EditorModel& model)
{
  col = model.cursorColumn();
  lin = model.cursorLine();
  if(model.cursorLine() > 1)
    {
      if(model.cursorColumn() > model.line(model.cursorLine()-1).length())
        {
          model.setColumn(model.line(model.cursorLine()-1).length()+1);
          model.decrementLine();
        }
      else
        {
          model.decrementLine();
        }
    }
  else
    {
      throw(EditorException("You have reached the first line."));
      model.setErrorMessage("You have reached the first line.");
    }
}

void CursorUp::undo(EditorModel& model)
{
  model.setLine(lin);
  model.setColumn(col);
}
