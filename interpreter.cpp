#include "interpreter.h"
#include "functions.h"


std::vector<unsigned char> tape (30000, 0);
std::vector<unsigned int> loop;
unsigned i=0;
int t=0;
int t_max=0;
unsigned s=0;
char ins=' ';
std::string in="";
std::string out="";
bool esc=false;


void interpreter (std::vector<char>& inst, bool o, bool p)
{
  if (o) { output(tape, t, t_max, s, ins, p); }
  else { printf("=> "); }

  while(!esc && i<inst.size())
  {
    ins=inst[i];
    switch (ins)
    {
      case '+' : tape[t]++; break;
      case '-' : tape[t]--; break;

      case '>' : next(t); break;
      case '<' : prev(t); break;

      case '[' : loop_beg(tape[t], inst, i, loop); break;
      case ']' : loop_end(tape[t], i, loop); break;

      case '.' : print(tape[t], out, o); break;
      case ',' : esc=input(tape[t], in, o); break;

      case '@' : esc=true; break;
    }

    i++;
    s++;
    if (t>t_max) { t_max=t; }

    if (o) { output(tape, t, t_max, s, ins, p); }
  }

  if (o) { printf("\nOutput: %s", out.c_str()); }
  else { printf("\nSteps: %u\n", s); }
}
