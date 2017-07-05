#include "functions.h"


void next (int& t)
{
  t++;
  if (t>29999) { t=0; }
}

void prev (int& t)
{
  t--;
  if (t<0) { t=29999; }
}

void loop_beg (unsigned char& cell, std::vector<char>& inst, unsigned& i, std::vector<unsigned int>& loop)
{
  if (cell==0)
  {
    int l=0;
    while (true)
    {
      i++;
      if (l==0 && inst[i]==']') { break; }
      else if (l>0 && inst[i]==']') { l--; }
      else if (inst[i]=='[') { l++; }
    }
  }
  else { loop.push_back(i); }
}

void loop_end (unsigned char& cell, unsigned& i, std::vector<unsigned int>& loop)
{
  if (cell!=0) { i=loop[loop.size()-1]; }
  else { loop.pop_back(); }
}

void print (unsigned char& cell, std::string& out, bool& o)
{
  out+=cell;
  if (!o) { printf("%c", out[out.length()-1]); }
}

char s_pop (std::string&);

bool input (unsigned char& cell, std::string& in, bool& o)
{
  if (in.length()==0)
  {
    if (!o) { printf("\n<= "); }
    else { printf("Input: "); }

    getline(std::cin, in);

    if (in=="!@") { return true; }
    else if (in[0]=='\\' && in.length()>=3)
    {
      if (in[in.length()-2]=='!' && in[in.length()-1]=='@') { s_pop(in); }
    }

    if (!o) { printf("=> "); }
  }

  cell=s_pop(in);

  return false;
}

void output (std::vector<unsigned char>& tape, int& t, int& t_max, unsigned& s, char& ins, bool plain)
{
  printf("%u:%c -> ", s, ins);
  for (int p=0; p<=t_max; p++)
  {
    if (p==t && !plain) { printf ("\033[1m%u:%u\033\[0m ", p, tape[p]); }
    if (p==t && plain) { printf (">%u:%u< ", p, tape[p]); }
    else { printf ("%u:%u ", p, tape[p]); }
  }
  if (ins=='.')
  {
    if (tape[t]>=33 && tape[t]<=254 && tape[t]!=127) { printf("-> %c", tape[t]); }
    else { printf("-> %u", tape[t]); }
  }
  printf("\n");
}


char s_pop (std::string& s)
{
  if (s.length()==0) { return 0; }

  char out=s[0];
  std::string tmp="";

  for (unsigned i=1; i<s.length(); i++) { tmp+=s[i]; }
  s=tmp;

  return out;
}
