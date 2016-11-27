using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DPTestClient
{
    public class NStackBooks
    {
        public static int GetMaxBooks(int[] array, int limit)
        {
            
            var length = array.Length;
            var cache = new int[length, length ];
            for (int i = 0; i < length; i++)
            {
                if (array[i] <= limit)
                    cache[i, i] = array[i];
                else
                    cache[i, i] = -1;
                //cache[0, i] = cache[0, i - 1] + array[i - 1];
            }

            int maxCollected = 0;

            for (int i = 0; i < length; i++)
            {
                for (int j = 0; j <= i; j++)
                {
                    if (i == j)
                    {
                        cache[i, i] = array[i] <= limit ? array[i] : -1;
                        maxCollected = maxCollected < cache[i, i] ? cache[i, i] : maxCollected;
                    }
                    else if (cache[j, i - 1] == -1)
                    {
                        cache[j, i] = -1;
                    }
                    else
                    {
                        var precConsecutive = cache[j, i - 1];
                        if (precConsecutive + array[i] <= limit)
                        {
                            cache[j, i] = precConsecutive + array[i];
                            if (maxCollected <= cache[j,i])
                                maxCollected = cache[j, i];
                        }
                        else
                        {
                            cache[j, i] = -1;
                        }
                    }
                }
            }

            return maxCollected;
        }
    }
}
