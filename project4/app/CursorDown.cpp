#include "CursorDown.hpp"
#include "EditorException.hpp"

void CursorDown::execute(EditorModel& model)
{
  col = model.cursorColumn();
  lin = model.cursorLine();
  if(model.cursorLine() < model.lineCount())
    {
      if(model.cursorColumn() > model.line(model.cursorLine()+1).length())
        {
          model.incrementLine();
          model.setColumn(model.line(model.cursorLine()).length()+1);
        }
      else
        {
          model.incrementLine();
        }
    }
  else
    {
      throw(EditorException("You have reached the last line."));
      model.setErrorMessage("You have reached the last line.");
    }
}

void CursorDown::undo(EditorModel& model)
{
  model.setColumn(col);
  model.setLine(lin);
}
