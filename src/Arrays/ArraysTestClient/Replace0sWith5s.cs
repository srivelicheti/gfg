using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArraysTestClient
{
    public static class Replace0sWith5s
    {
        public static int Execute(int n)
        {
            int input = n;
            int modulo = 10;
            int toAdd = 0;
            int multiplier = 1;
            while (true)
            {
                if (n%modulo == 0)
                {
                    toAdd = toAdd + 5*multiplier;
                }
                multiplier = multiplier*10;
                if(n < 10)
                    break;
                n = n/10;
            }

            return input + toAdd;
        }
    }
}
