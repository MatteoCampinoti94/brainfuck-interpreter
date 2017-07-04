#include <iostream>
#include <fstream>
#include <vector>
#include "parser.h"
#include "interpreter.h"


bool check_file (std::string name);
void options_parse (std::string, struct options_struct&);

struct options_struct
{
  options_struct() : out(true), plain(false) {}
  bool out;
  bool plain;
};


int main(int argc, char* argv[])
{
  std::vector<char> inst;
  struct options_struct options;

  if (argc<2)
  {
    printf ("Type Brainfuck code: ");
    std::string code; getline(std::cin, code);
    if (!parser_string(code, inst)) { printf ("Loop brackets don't match\n"); exit(3); }
  }
  else if (argc==2)
  {
    if (check_file(argv[1]))
    {
      std::ifstream ifile(argv[1]);
      if (!parser_file(ifile, inst)) { printf ("Loop brackets don't match\n"); exit(3); }
    }
    else if (argv[1][0]=='-')
    {
      options_parse(argv[1], options);
      printf ("Type Brainfuck code: ");
      std::string code; getline(std::cin, code);
      if (!parser_string(code, inst)) { printf ("Loop brackets don't match\n"); exit(3); }
    }
    else { printf("File does not exist\n"); exit(1); }

  }
  else if (argc>2)
  {
    options_parse(argv[1], options);

    if (check_file(argv[2]))
    {
      std::ifstream ifile(argv[2]);
      if (!parser_file(ifile, inst)) { printf ("Loop brackets don't match\n"); exit(3); }
    }
    else { printf("File does not exist\n"); exit(1); }
  }

  interpreter(inst, options.out, options.plain);
}


bool check_file (std::string name) {
  std::fstream file(name.c_str());

  if (file.fail()) { return false; }
  else { file.close(); return true; }
}

void options_parse (std::string opt, struct options_struct& opt_s)
{
  if (opt[0]=='-' && opt.length()>1)
  {
    for (unsigned i=1; i<opt.length(); i++)
    {
      switch (opt[i])
      {
        case 'n' : opt_s.out=false; break;
        case 'p' : opt_s.plain=true; break;
        default  : printf("Uknown option\n"); exit(2);
      }
    }
  }
  else { printf("Uknown option\n"); exit(2); }
}
