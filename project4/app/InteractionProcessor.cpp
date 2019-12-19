// InteractionProcessor.cpp
//
// ICS 45C Fall 2019
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"
#include <stack>


// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.

void InteractionProcessor::run()
{
    view.refresh();
    std::stack <Command*> undo;
    std::stack <Command*> redo;
    
    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {
          while(undo.size() > 0)
            {
              Command* x = undo.top();
              undo.pop();
              delete x;
            }
          while(redo.size() > 0)
            {
              Command* x = redo.top();
              redo.pop();
              delete x;
            }
          break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
          if (undo.size() != 0)
            {
              Command* c = undo.top();
              try
                {
                  redo.push(c);
                  undo.pop();
                  c->undo(model);
                  model.clearErrorMessage();
                }
              catch(EditorException& e)
                {
                  model.setErrorMessage(e.getReason());
                  delete c;
                }
            }
          view.refresh();
        }
        else if (interaction.type() == InteractionType::redo)
        {
          if(redo.size() != 0)
            {
              Command* c = redo.top();
              try
                {
                  undo.push(c);
                  redo.pop();
                  c->execute(model);
                  model.clearErrorMessage();
                }
              catch(EditorException& e)
                {
                  model.setErrorMessage(e.getReason());
                  delete c;
                }
            }
          view.refresh();
        }
        else if (interaction.type() == InteractionType::command)
        {
            Command* command = interaction.command();
            
            try
            {
              model.clearErrorMessage();
              if(command == nullptr)
                {
                  delete command;
                }
              else
                {
                  command->execute(model);
                  undo.push(command);
                  for(int i=0; i<redo.size(); ++i)
                    {
                      redo.pop();
                    }
                }
             
            }
            catch (EditorException& e)
              {
                model.setErrorMessage(e.getReason());
                delete command;
              }

            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore.
            //delete command;
        }
    }
}

