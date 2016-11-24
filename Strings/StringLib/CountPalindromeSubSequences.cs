using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StringLib
{
   public class CountPalindromeSubSequences
    {
        public static IDictionary<string, int> _cache;

        public static int GetCountOfPalidromSubsequence(string s)
        {
            _cache = new Dictionary<string, int>();
            return GetCount(s);
        }

        private static int GetCount(string s)
        {
            if (s == string.Empty)
                return 0;
            if (s.Length == 1)
                return 1;
            else if (_cache.ContainsKey(s))
                return _cache[s];

            var prefixString = s.Substring(0, s.Length - 1);
            var suffixIndex = s.Length - 1;
            var suffixChar = s[suffixIndex];

            var prefixPalindromesCount = GetCount(prefixString);
            int count = 1; //just for the last literal alone
            for (int i = 0; i < s.Length - 2; i++)
            {
                if (s[i] == suffixChar)
                {
                   var innerPalinrome = GetCount(s.Substring(i + 1, suffixIndex - (i + 1)));
                    count = innerPalinrome + 1 + count;
                }
            }
            var totalCount = prefixPalindromesCount + count;
            _cache.Add(s, totalCount);
            return totalCount;
        }
    }
}
