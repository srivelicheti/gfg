using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StringLib
{
    public class InterleavedString
    {
        public static bool IsInterleaved(string s1, string s2, string s)
        {
            return IsInterleaved(s1, 0, s2, 0, s, 0);
            throw new NotImplementedException();
        }

        private static bool IsInterleaved(string s1, int p1, string s2, int p2, string s, int p)
        {

            if (p == s.Length)
                return true;

            var match1 = p1 < s1.Length && s1[p1] == s[p];
            var match2 = p2 < s2.Length && s2[p2] == s[p];

            return (match1 && IsInterleaved(s1, p1 + 1, s2, p2, s, p + 1)) ||
                   (match2 && IsInterleaved(s1, p1, s2, p2 + 1, s, p + 1));

        }
    }
}
