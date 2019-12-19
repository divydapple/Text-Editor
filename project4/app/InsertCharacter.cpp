#include "InsertCharacter.hpp"
#include <string>

InsertCharacter::InsertCharacter(char c)
  : character{c}
{
  s = "";
}

void InsertCharacter::execute(EditorModel& model)
{
  s = model.line(model.cursorLine());
  std::string a = s;
  a.insert(model.cursorColumn()-1, 1, character);
  model.setLineText(a);
  model.incrementColumn();
}

void InsertCharacter::undo(EditorModel& model)
{
  model.decrementColumn();
  model.setLineText(s);
}


