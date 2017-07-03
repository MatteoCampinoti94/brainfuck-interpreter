#include "parser.h"


bool parser_file (std::ifstream& ifile, std::vector<char>& inst)
{
  char c;
  int loop=0;
  std::string buff;

  while (ifile.get(c))
  {
    switch(c)
    {
      case '+' :
      case '-' :
      case '>' :
      case '<' : inst.push_back(c); break;

      case '[' : loop++; inst.push_back(c); break;
      case ']' : loop--; inst.push_back(c); break;

      case ',' :
      case '.' : inst.push_back(c); break;

      case '!' :
      case '#' : getline(ifile, buff); break;

      case '\\' : ifile.get(c); break;

      case '@' : ifile.close(); break;
    }
  }

  if (loop!=0) { return false; }
  return true;
}

bool parser_string(std::string& input, std::vector<char>& inst)
{
  char c;
  int loop=0;

  for (unsigned i=0; i<input.length(); i++)
  {
    c=input[i];
    switch(c)
    {
      case '+' :
      case '-' :
      case '>' :
      case '<' : inst.push_back(c); break;

      case '[' : loop++; inst.push_back(c); break;
      case ']' : loop--; inst.push_back(c); break;

      case ',' :
      case '.' : inst.push_back(c); break;
    }
  }

  if (loop!=0) { return false; }
  return true;
}
