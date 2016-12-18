using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GraphsTest
{
    public class PrimsMST
    {
        public int MstWeight(List<Tuple<int, int>>[] g, int m)
        {
            int remaining = m - 1;

            //List<int> consumed = new List<int>();
            var consumed = new int[m];
            consumed[0] = 1;
            int totalWeight = 0;
            while (remaining > 0)
            {
                int minWeight = int.MaxValue;
                int newIndex = -1;
                foreach (var i in consumed)
                {
                    if (i == 0)
                        continue;

                    var currentEdges = g[i];
                    foreach (var edge in currentEdges)
                    {
                        if (edge.Item1 < minWeight)
                        {
                            minWeight = edge.Item1;
                            newIndex = edge.Item2;
                        }
                    }

                }
                totalWeight += minWeight;
                consumed[newIndex] = 1;
                remaining--;
            }
            return totalWeight;
        }
    }
}
