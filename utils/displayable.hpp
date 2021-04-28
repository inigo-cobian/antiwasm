#ifndef ANTIWASM_DISPLAYABLE_HPP
#define ANTIWASM_DISPLAYABLE_HPP

struct Displayable {
  virtual void displayError() = 0;
  virtual void displayContentInfo() = 0;
};

#endif // ANTIWASM_DISPLAYABLE_HPP
