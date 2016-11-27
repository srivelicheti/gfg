using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DPTestClient
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(NStackBooks.GetMaxBooks(new[] {8, 1, 1, 15}, 8));
            Console.ReadLine();
        }
    }
}
