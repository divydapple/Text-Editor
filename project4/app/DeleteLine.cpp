#include "DeleteLine.hpp"
#include "EditorException.hpp"

void DeleteLine::execute(EditorModel& model)
{
  if(model.line(model.cursorLine()) == "" && model.cursorLine() == 1)
    {
      casenum = 2;
      throw(EditorException("Already empty."));
      model.setErrorMessage("Already empty.");
    }
  else
    {
      currentline = model.cursorLine();
      currentcolumn = model.cursorColumn();
      currl = model.line(model.cursorLine());
      if(model.lineCount() > 1)
        {
          casenum = 0;
          if(model.cursorLine() == model.lineCount())
            {
              model.decrementLine();
              model.removeFromVector(model.cursorLine());
            }
          else
            {
              model.removeFromVector(model.cursorLine()-1);
            }
          prevl = model.line(model.cursorLine());
          if(currl.length() > prevl.length())
            {
              model.setColumn(prevl.length()+1);
            }
        }
      else
        {
          casenum = 1;
          prevl = model.line(model.cursorLine());
          prevCursCol = model.cursorColumn();
          model.setLineText("");
          model.setLine(1);
          model.setColumn(1);
        }
    }
}

void DeleteLine::undo(EditorModel& model)
{
  if(casenum == 0)
    {
      model.setLine(currentline);
      model.setColumn(currentcolumn);
      model.insertIntoVector(currentline-1, currl);
    }
  else if(casenum == 1)
    {
      model.setLineText(currl);
      model.setColumn(prevCursCol);
    }
}
