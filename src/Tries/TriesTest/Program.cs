using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TriesLib;

namespace TriesTest
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                var trie = new LowerCaseAlphabetsTrie();
                var suffixTrie = new LowerCaseAlphabetSuffixTrie();
                Console.WriteLine("Enter string");
                string inputString = Console.ReadLine();
                while (inputString != null && !inputString.Equals("exit"))
                {
                    
                    var exists = trie.Exists(inputString);
                    if (exists)
                        Console.WriteLine("Alread in Trie");
                    else
                    {
                        trie.InsertString(inputString);
                        suffixTrie.Insert(inputString);
                    }

                 
                    Console.WriteLine("Total Strings Entered " + trie.Count());
                    Console.WriteLine("Total SubStrings " + suffixTrie.Count());
                    Console.WriteLine("Enter string");
                    inputString = Console.ReadLine();

                };

                
              //  Console.ReadLine();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex);
                Console.ReadLine();
            }
            
        }
    }
}
