using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Runtime.InteropServices;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;

namespace TriesLib
{

    internal class TrieNode<TValue>
    {
        static TrieNode()

        {
            var value = default(TValue);
            if (value != null && !value.Equals(null))

                throw new InvalidOperationException(

                "Only types with a default value of null can be assigned to the Parameter<T> type.");
        }
    }

    internal class TrieNode
    {
        private readonly TrieNode[] _next;
        // private char _currentChar;
        private Func<char, int> _convertFunc;
        private int _size;

        public TrieNode(int radix, char c, Func<char, int> convertFunc)
        {
            _size = radix;
            _next = new TrieNode[radix];
            CurrentChar = c;
            _convertFunc = convertFunc;
        }

        //public TrieNode(int radix, char c, Func<char, int> convertFunc, bool everyCharIsSubStr)
        //{
        //    _size = radix;
        //    _next = new TrieNode[radix];
        //    CurrentChar = c;
        //    _convertFunc = convertFunc;
        //    IsValue = everyCharIsSubStr;
        //}

        public TrieNode(int radix, string s, Func<char, int> convertFunc)
        {
            _size = radix;
            _next = new TrieNode[radix];
            CurrentChar = s[0];
            _convertFunc = convertFunc;
            if (s.Length == 0)
            {
                IsValue = true;
            }
            else
            {

                InsertString(s.Substring(1));
            }

        }

        //public TrieNode(int radix, string s, Func<char, int> convertFunc, bool everyCharIsString)
        //{
        //    _size = radix;
        //    _next = new TrieNode[radix];
        //    CurrentChar = s[0];
        //    _convertFunc = convertFunc;
        //    if (s.Length == 0)
        //    {
        //        IsValue = true;
        //    }
        //    else
        //    {
        //        IsValue = everyCharIsString;
        //        InsertString(s.Substring(1), everyCharIsString);
        //    }

        //}

        public bool IsValue { get; set; }

        public TrieNode[] NextNodes => _next;

        private TrieNode InsertNextChar(char c, int index)
        {
            if (index >= _next.Length)
                throw new ArgumentException("Invalid index speicifed");

            var next = _next[index];
            if (next == null)
            {
                _next[index] = new TrieNode(_size, c, _convertFunc);
            }
            return _next[index];
        }

        public TrieNode InsertString(string s)
        {
            var currentNode = this;
            foreach (char c in s)
            {
                var index = _convertFunc(c);
                currentNode = currentNode.InsertNextChar(c, index);
               // currentNode.IsValue = everySubStringIsString || currentNode.IsValue;
            }
            currentNode.IsValue = true;
            return currentNode;

        }

        //public TrieNode InsertString(string s, bool everySubStringIsString)
        //{
        //    var currentNode = this;
        //    foreach (char c in s)
        //    {
        //        var index = _convertFunc(c);
        //        currentNode = currentNode.InsertNextChar(c, index);
        //        currentNode.IsValue = everySubStringIsString || currentNode.IsValue;
        //    }
        //    currentNode.IsValue = true;
        //    return currentNode;

        //}

        public char CurrentChar { get; set; }

        public int TotalCount()
        {
            int count = 0;

            foreach (var trieNode in _next)
            {
                if (trieNode != null)
                    count = count + trieNode.TotalCount();
            }

            if (IsValue)
                count++;
            return count;
        }

        public int TotalSubStringsCount()
        {
            int count = 0;

            foreach (var trieNode in _next)
            {
                if (trieNode != null)
                    count = count + trieNode.TotalSubStringsCount();
            }

            
            count++;
            return count;
        }

    }

    public class LowerCaseAlphabetsTrie
    {
        private const int size = 26;
        private const int lowerBound = 'a';

        private int ConvertFunc(char c)
        {
            return Convert.ToInt32(c) - lowerBound;
        }

        private TrieNode[] _root;

        public LowerCaseAlphabetsTrie()
        {
            _root = new TrieNode[size];
        }

        public LowerCaseAlphabetsTrie(char a)
        {
            _root = new TrieNode[size];
            var index = ConvertFunc(a);
            _root[index] = new TrieNode(size, a, ConvertFunc);
        }

        public LowerCaseAlphabetsTrie(string a)
        {
            _root = new TrieNode[size];
            var index = ConvertFunc(a[0]);
            _root[index] = new TrieNode(size, a, ConvertFunc);
        }

        public void InsertString(string s)
        {
            if (s == string.Empty)
                return;

            var firstChar = s[0];
            var index = ConvertFunc(firstChar);
            var nextNode = _root[index];
            if (nextNode == null)
            {
                _root[index] = new TrieNode(size, s, ConvertFunc);
                _root[index].IsValue = _root[index].IsValue;
            }
            else
            {
                nextNode.InsertString(s.Substring(1));
            }
        }


        public bool Exists(string s)
        {
            if (s.Length == 0)
                return true;
            var firstCharIndex = ConvertFunc(s[0]);

            var currentNode = _root[firstCharIndex];
            if (currentNode == null)
                return false;
            int counter = 1;
            for (int i = 1; i < s.Length; i++)
            {
                var c = s[i];
                var index = ConvertFunc(c);
                currentNode = currentNode.NextNodes[index];
                if (currentNode == null)
                    break;

                counter++;
            }
            return counter == s.Length && currentNode != null && currentNode.IsValue == true;
        }

        public int Count()
        {
            var count = 0;
            foreach (var trieNode in _root)
            {
                if (trieNode != null)
                    count += trieNode.TotalCount();
            }
            count++; //for empty strin that is represented by the creation of trie itself
            return count;
        }

        public int TotalSubStringsCount()
        {
            var count = 0;
            foreach (var trieNode in _root)
            {
                if (trieNode != null)
                    count += trieNode.TotalSubStringsCount();
            }
            count++; //for empty strin that is represented by the creation of trie itself
            return count;
        }
    }


    public class LowerCaseAlphabetSuffixTrie
    {
        private LowerCaseAlphabetsTrie _trie;
        public LowerCaseAlphabetSuffixTrie()
        {
            _trie = new LowerCaseAlphabetsTrie();
        }

        public LowerCaseAlphabetSuffixTrie(string s)
        {
            _trie = new LowerCaseAlphabetsTrie();
            Insert(s);

        }

        public void Insert(string s)
        {
            for (int i = 0; i < s.Length; i++)
            {
                _trie.InsertString(s.Substring(i));
            }
        }

        public int Count()
        {
            return _trie.TotalSubStringsCount();
        }
    }
}
