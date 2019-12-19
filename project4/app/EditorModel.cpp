
// EditorModel.cpp
//
// ICS 45C Fall 2019
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"
#include <vector>


EditorModel::EditorModel()
  : lineNum{1}, columnNum{1}, errorM{""}
{
  text.push_back("");
}


int EditorModel::cursorLine() const
{
    return lineNum;
}


int EditorModel::cursorColumn() const
{
    return columnNum;
}

void EditorModel::incrementColumn()
{
  columnNum++;
}

void EditorModel::decrementColumn()
{
  columnNum--;
}

void EditorModel::incrementLine()
{
  lineNum++;
}

void EditorModel::decrementLine()
{
  lineNum--;
}

void EditorModel::setColumn(int num)
{
  columnNum = num;
}

void EditorModel::setLine(int num)
{
  lineNum = num;
}

void EditorModel::insertIntoVector(int position, std::string s)
{
  text.insert(text.begin()+position, 1, s);
}

void EditorModel::removeFromVector(int position)
{
  text.erase(text.begin()+position);
}

void EditorModel::setLineText(std::string s)
{
  text.at(lineNum-1) = s;
}

int EditorModel::lineCount() const
{
  return text.size();
}


const std::string& EditorModel::line(int lineNumber) const
{
  static std::string s;
  s = text[lineNumber-1];
  return s;
}


const std::string& EditorModel::currentErrorMessage() const
{
  
    return errorM;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
  errorM = errorMessage;
}


void EditorModel::clearErrorMessage()
{
  errorM = "";
}

