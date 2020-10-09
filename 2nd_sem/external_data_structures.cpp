#include <iostream>
#include <fstream>

int main()
{
   std::ifstream in("in.txt");
   std::ofstream out("out.bin", std::ios::binary);

   double d;
   while(in >> d) {
      out.write((char*)&d, sizeof d);
   }
}
