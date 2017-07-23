using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Trie
{
    class Program
    {
        static void Main(string[] args)
        {
            Trie trie = null;
            
            Console.WriteLine("Enter some string");
            string s = Console.ReadLine();
            trie = new Trie(s);

            Console.WriteLine("Enter Another");
            s = Console.ReadLine();
            while (s != "end") {
                bool add = s.Substring(0, 2) == "1 ";
                string newstr = s.Substring(2);
                if (add)
                    trie.Insert(newstr);
                else
                    Console.WriteLine($"{newstr} Found :: { trie.CheckIfWordExists(newstr)}");
                Console.WriteLine("Enter Another");
                s = Console.ReadLine();
            }
        }
    }

    class TrieNode {
        public TrieNode(string s) {
            if (string.IsNullOrEmpty(s))
                throw new Exception("Empty string");
            Data = s[0];
            Insert(s, 0);
        }
        public TrieNode(char c)
        {
            Data = c;
        }
        public TrieNode(char c,TrieNode center)
        {
            Data = c;
            Center = center;
        }
        public bool IsWord { get; set; }
        public TrieNode Left { get; set; }
        public char Data { get; set; }
        public TrieNode Center { get; set; }
        public TrieNode Right { get; set; }

        public TrieNode Insert(string s, int index) {
            if(index >=s.Length)
            { IsWord = true; return this; }
            if (s[index] == Data)
            {
                InsertCenter(s, index + 1);
            }
            else if (s[index] < Data)
            {
                InsertLeft(s, index);
            }
            else {
                InsertRight(s, index);
            }

            return this;
        }

        private TrieNode InsertLeft(string s, int index)
        {
            if (Left == null)
                Left = new TrieNode(s[index]);

            return Left.Insert(s, index);
        }

        private TrieNode InsertRight(string s, int index)
        {
            if (Right == null)
                Right = new TrieNode(s[index]);

            return Right.Insert(s, index);
        }

        private TrieNode InsertCenter(string s, int index) {
            if (index >= s.Length)
            { IsWord = true; return this; }

            if (Center == null)
                Center = new TrieNode(s[index]);

            return Center.Insert(s, index);

        }

        public bool CheckIfMatches(string s, int i) {
            if (i >= s.Length - 1)
                return IsWord;

            if (s[i] == Data)
            {
                if (Center == null)
                    return false;
                else
                    return Center.CheckIfMatches(s, i + 1);
            }
            else if (s[i] < Data) {
                if (Left == null)
                    return false;
                return Left.CheckIfMatches(s, i);
            }
            else
            {
                if (Right == null)
                    return false;
                return Right.CheckIfMatches(s, i);
            }
        }

    }

    class Trie {
        TrieNode _root;

        public Trie(string s)
        {
            _root = new TrieNode(s);
        }

        public void Insert(string s) {
            _root.Insert(s, 0);
        }

        public bool CheckIfWordExists(string s) {
            return _root.CheckIfMatches(s, 0);
        }

        public void Display(TrieNode node ,int level) {

        }
    }


}
