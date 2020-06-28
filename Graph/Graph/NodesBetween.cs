using System;
using System.Collections.Generic;
using System.Text;

namespace Graph
{
    class NodesBetween
    {


        // function to calculate no of nodes 
        // between two nodes 
        static int totalNodes(List<int>[] adjac,
                              int n, int x, int y)
        {
            // x is the source node and 
            // y is destination node 

            // visited array take account of 
            // the nodes visited through the bfs 
            Boolean[] visited = new Boolean[n + 1];


            // parent array to store each nodes 
            // parent value 
            int[] p = new int[n];

            Queue<int> q = new Queue<int>();
            q.Enqueue(x);


            // take our first node(x) as first element 
            // of queue and marked it as 
            // visited through visited[] array 
            visited[x] = true;

            int m, i;

            // normal bfs method starts 
            while (q.Count != 0)
            {
                m = q.Peek();
                q.Dequeue();
                for (i = 0; i < adjac[m].Count; ++i)
                {
                    int h = adjac[m][i];

                    if (visited[h] != true)
                    {
                        visited[h] = true;

                        // when new node is encountered 
                        // we assign it's parent value 
                        // in parent array p 
                        p[h] = m;
                        q.Enqueue(h);
                    }
                }
            }

            // count variable stores the result 
            int count = 0;

            // loop start with parent of y 
            // till we encountered x 
            i = p[y];
            while (i != x)
            {
                // count increases for counting 
                // the nodes 
                count++;
                i = p[i];
            }
            return count;
        }

        
    }

}
