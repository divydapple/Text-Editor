#include "CursorRight.hpp"
#include "EditorException.hpp"

void CursorRight::execute(EditorModel& model)
{
  if(model.cursorColumn() <= model.line(model.cursorLine()).length())
    {
      model.incrementColumn();
    }
  else
    {
      if(model.cursorLine() < model.lineCount())
        {
          model.setColumn(1);
          model.incrementLine();
        }
      else
        {
          throw(EditorException("You have reached the last line."));
          model.setErrorMessage("You have reached the last line.");
        }
    }
}

void CursorRight::undo(EditorModel& model)
{
  if(model.cursorColumn() > 1)
    {
      model.decrementColumn();
    }
  else
    {
      if(model.cursorLine() > 1)
        {
          model.setColumn(model.line(model.cursorLine()-1).length()+1);
          model.decrementLine();
        }
      else
        {
          throw(EditorException("You have reached the beginning of this row."));
          model.setErrorMessage("You have reached the beginning of this row.");
        }
    }
}
