// KeypressInteractionReader.cpp
//
// ICS 45C Fall 2019
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include "KeypressInteractionReader.hpp"
#include "CursorRight.hpp"
#include "CursorLeft.hpp"
#include "CursorUp.hpp"
#include "CursorDown.hpp"
#include "CursorHome.hpp"
#include "CursorEnd.hpp"
#include "NewLine.hpp"
#include "InsertCharacter.hpp"
#include "Backspace.hpp"
#include "DeleteLine.hpp"


// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

Interaction KeypressInteractionReader::nextInteraction()
{
  Command* c = nullptr;
    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

            switch (keypress.code())
            {
            case 'X':
                return Interaction::quit();
            case 'O':
              c = new CursorRight();
              return Interaction::command(c);
            case 'U':
              c = new CursorLeft();
              return Interaction::command(c);
            case 'I':
              c = new CursorUp();
              return Interaction::command(c);
            case 'K':
              c = new CursorDown();
              return Interaction::command(c);
            case 'Y':
              c = new CursorHome();
              return Interaction::command(c);
            case 'P':
              c = new CursorEnd();
              return Interaction::command(c);
            case 'J':
              c = new NewLine();
              return Interaction::command(c);
            case 'M':
              c = new NewLine();
              return Interaction::command(c);
            case 'H':
              c = new Backspace();
              return Interaction::command(c);
            case 'D':
              c = new DeleteLine();
              return Interaction::command(c);
            case 'Z':
              return Interaction::undo();
            case 'A':
              return Interaction::redo();
            }
        }
        else
        {
            // The user pressed a normal key (e.g., 'h') without holding
            // down Ctrl; react accordingly

          c = new InsertCharacter(keypress.code());
          return Interaction::command(c);
        }
    }
}

