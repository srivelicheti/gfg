using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using StringLib;

namespace TestStrings
{
    class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine( InterleavedString.IsInterleaved("ABC", "DEF", "ADFEC"));
            do
            {
                Console.WriteLine("Enter String");
                string s = Console.ReadLine();
                var count = CountPalindromeSubSequences.GetCountOfPalidromSubsequence(s);
                Console.WriteLine(count);
            } while (Console.Read() == 1);
           
        }
    }
}
