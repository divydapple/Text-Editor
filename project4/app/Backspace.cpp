#include "Backspace.hpp"
#include <string>
#include "EditorException.hpp"

Backspace::Backspace()
  : lineDeleted{false}
{
}

void Backspace::execute(EditorModel& model)
{
  textsize = model.lineCount();
  col = model.cursorColumn();
  line = model.cursorLine();
  currl = model.line(model.cursorLine());
  if(model.cursorColumn() != 1)
    {
      character = currl.at(model.cursorColumn()-2);
      std::string c = currl;
      c.erase(c.begin()+(model.cursorColumn()-2));
      model.setLineText(c);
      model.decrementColumn();
    }
  else
    {
      if(model.cursorLine() == 1)
        {
          throw(EditorException("You have reached the first line."));
          model.setErrorMessage("You have reached the first line.");
        }
      else
        {
          lineDeleted = true;
          model.decrementLine();
          model.removeFromVector(model.cursorLine());
          prevl = model.line(model.cursorLine());
          model.setColumn(prevl.length() + 1);
          model.setLineText(prevl + currl);
        }
    }
}

void Backspace::undo(EditorModel& model)
{
  if(lineDeleted)
    {
      model.setLineText(prevl);
      model.insertIntoVector(model.cursorLine(), currl);
      model.incrementLine();
      model.setColumn(1);
    }
  else
  {
      model.setLineText(currl);
      model.setColumn(col);
  }
}
