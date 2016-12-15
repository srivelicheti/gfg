using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArraysTestClient
{
    /// <summary>
    /// http://www.practice.geeksforgeeks.org/problem-page.php?pid=700276
    /// </summary>
    public static class MaxSumInConfiguration
    {
        public static int MaxSumInConfig(int[] input)
        {
            int max = 0;
            for (int i = 0; i < input.Length; i++)
            {
                int sum = 0;
                for (int j = 0; j < input.Length; j++)
                {
                    int toMultiple = j - i;
                    if (toMultiple < 0)
                        toMultiple = toMultiple + input.Length;

                    sum += toMultiple*input[j];
                }
                if (sum > max)
                    max = sum;
            }
            return max;
        }
    }
}
